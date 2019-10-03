/*
 * Description: functions for the level objects
 */

#include "level.h"

//! Function to create a new level.
/*
 * @param    string    name label
 * @param    int       level type
 *
 * @return   string    error message, if any
 */
char* newLevel(Level* level, const char* const label, unsigned int type) {

    if (!level || strlen(label) < 1) {
        return "newLevel() --> invalid input";
    }

    char* err = "";

    level->label = (char*) label;
    level->type  = type;

    // If already ground tiles, free them.
    if (level->ground_tiles) {
        free(level->ground_tiles);
        level->ground_tiles = NULL;
    }

    level->ground_tiles = (CSV*) calloc(1, sizeof(CSV));

    if (!level->ground_tiles) {
        free(level);
        return "newLevel() --> unable to calloc CSV";
    }

    // procedurally generate the ground tiles of the level
    err = procedurallyGenerateCSV(level);

    if (strlen(err) > 0) {
        return err;
    }

    // otherwise everything worked, so no error message
    return "";
}

//! Function to free memory from a level.
/*
 * @param    Level     object to delete
 *
 * @return   string    error message, if any
 */
char* deleteLevel(Level* level) {

    // input validation
    if (!level) {
        return "deleteLevel() --> invalid input";
    }

    // attempt to free the CSV, if it exists
    if (level->ground_tiles) {
        free(level->ground_tiles);
        level->ground_tiles = NULL;
    }

    // free and nullify the level object
    free(level);
    level = NULL;

    // otherwise everything worked, so no error message
    return "";
}

//! Procedurally generate the values in a given CSV.
/*
 * @param    Level*    pointer to the level in question
 *
 * @return   string    error message, if any
 */
char* procedurallyGenerateCSV(Level* level) {

    // input validation
    if (!level) {
        return "procedurallyGenerateCSV() --> invalid input";
    }

    // variable declaration
    bool nothing_to_do = false;
    int min        = 0;
    int max        = 0;
    unsigned int i = 0;
    unsigned int j = 0;

    // seed the global random value using the current time
    srand(time(NULL));

    // switch thru the different level types
    switch(level->type) {

        // level is currently undefined
        case LEVEL_TYPE_IS_UNKNOWN:
            nothing_to_do = true;
            break;

        // level is grass
        case LEVEL_TYPE_IS_GRASS:
            min = LEVEL_TYPE_GRASS_MIN;
            max = LEVEL_TYPE_GRASS_MAX;
            break;

        // level is swamp
        case LEVEL_TYPE_IS_SWAMP:
            min = LEVEL_TYPE_SWAMP_MIN;
            max = LEVEL_TYPE_SWAMP_MAX;
            break;

        // level is desert
        case LEVEL_TYPE_IS_DESERT:
            min = LEVEL_TYPE_DESERT_MIN;
            max = LEVEL_TYPE_DESERT_MAX;
            break;

        // catch-all
        default:
            nothing_to_do = true;
            break;
    }

    // go ahead and leave if there is nothing to do
    if (nothing_to_do) {
        return "";
    }

    // for every element in the csv
    for (i = 0; i < CSV_COLUMN_MAX; i++) {
        for (j = 0; j < CSV_ROW_MAX; j++) {
            level->ground_tiles->data[i][j] = rand() % (max-min);
        }
    }

    // otherwise everything worked, so no error message
    return "";
}

//! Assemble a SDL rectangle + texture from a given set of ground tiles.
/*
 * @param    Level*           pointer to the level in question
 * @param    SDL_Renderer*    pointer to global SDL renderer
 *
 * @return   string           error message, if any
 */
char* assembleGroundTiles(Level* level, SDL_Renderer* renderer) {

    if (!level) {
        return "assembleGroundTiles() --> invalid input";
    }

    unsigned int i    = 0;
    unsigned int j    = 0;
    unsigned int e    = 0;
    unsigned int unit = 64;

    SDL_Rect* rect = (SDL_Rect*) calloc(1, sizeof(SDL_Rect));
    if (!rect) {
        return "assembleGroundTiles() --> unable to "
          "calloc for SDL_Rect";
    }

    for (i = 0; i < CSV_COLUMN_MAX; i++) {
        for (j = 0; j < CSV_ROW_MAX; j++) {

            // Set the diameters
            rect->x = i*unit;
            rect->y = j*unit;
            rect->w = unit;
            rect->h = unit;

            // grab the current tile value
            e = level->ground_tiles->data[i][j];

            switch(level->type) {

                // level is currently undefined
                case LEVEL_TYPE_IS_UNKNOWN:
                    break;

                // level is grass
                case LEVEL_TYPE_IS_GRASS:
                    SDL_QueryTexture(GRASS_TILES[e], NULL, NULL, &rect->w, &rect->h);
                    SDL_RenderCopy(renderer, GRASS_TILES[e], NULL, rect);
                    break;

                // level is swamp
                case LEVEL_TYPE_IS_SWAMP:
                    SDL_QueryTexture(SWAMP_TILES[e], NULL, NULL, &rect->w, &rect->h);
                    SDL_RenderCopy(renderer, SWAMP_TILES[e], NULL, rect);
                    break;

                // level is desert
                case LEVEL_TYPE_IS_DESERT:
                    SDL_QueryTexture(DESERT_TILES[e], NULL, NULL, &rect->w, &rect->h);
                    SDL_RenderCopy(renderer, DESERT_TILES[e], NULL, rect);
                    break;

                // catch-all
                default:
                    break;
            }
        }
    }

    if (rect) {
        free(rect);
        rect = NULL;
    }

    return "";
}

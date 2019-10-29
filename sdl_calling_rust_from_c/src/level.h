/*
 * Description: header with the level definition
 */

#ifndef LEVEL_H
#define LEVEL_H

// SDL includes
#include <SDL2/SDL.h>

// C99 includes
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Project includes
#include "csv.h"
#include "globals.h"

// Type defines
#define LEVEL_TYPE_IS_UNKNOWN 0
#define LEVEL_TYPE_IS_GRASS   1
#define LEVEL_TYPE_IS_SWAMP   2
#define LEVEL_TYPE_IS_DESERT  3

// Desert defines
#define LEVEL_TYPE_DESERT_MIN  1
#define LEVEL_TYPE_DESERT_MAX  6
#define LEVEL_TYPE_DESERT_PATH "img/desert/"

// Grass defines
#define LEVEL_TYPE_GRASS_MIN  1
#define LEVEL_TYPE_GRASS_MAX  14
#define LEVEL_TYPE_GRASS_PATH "img/grass/"

// Swamp defines
#define LEVEL_TYPE_SWAMP_MIN  1
#define LEVEL_TYPE_SWAMP_MAX  13
#define LEVEL_TYPE_SWAMP_PATH "img/swamp/"

//
// Level definition
//
typedef struct Level {
    char* label;
    int type;
    CSV* ground_tiles;
} Level;

//! Function to create a new level.
/*
 * @param    string    name label
 * @param    int       level type
 *
 * @return   string    error message, if any
 */
char* newLevel(Level*, const char* const, unsigned int);

//! Function to free memory from a level.
/*
 * @param    Level     object to delete
 *
 * @return   string    error message, if any
 */
char* deleteLevel(Level*);

//! Procedurally generate the values in a given CSV.
/*
 * @param    Level*    pointer to the level in question
 *
 * @return   string    error message, if any
 */
char* procedurallyGenerateCSV(Level*);

//! Assemble a SDL rectangle + texture from a given set of ground tiles.
/*
 * @param    Level*           pointer to the level in question
 * @param    SDL_Renderer*    pointer to global SDL renderer
 *
 * @return   string           error message, if any
 */
char* assembleGroundTiles(Level*, SDL_Renderer*);

#endif

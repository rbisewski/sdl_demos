/*
 * Description: functions for loading assets
 */

#include "assetloader.h"

//! Function to run all of the initial asset loading.
/*
 * @return    string    error message, if any
 */
char* LoadAssets() {

    // variable declaration
    char* err = "";

    // attempt to initialize the textures
    err = InitTextures();

    // if an error occurs, pass it back.
    if (strlen(err) > 0) {
        return err;
    }

    // everything loaded correctly
    return "";
}

//! Initializes game textures.
/*
 * @return    string    error message, if any
 */
char* InitTextures() {

    // variable declaration
    int i                    = 0;
    char img_path[256]       = {0};
    SDL_Surface* tmp_surface = NULL;

    // assemble the path string for the mouse bitmap
    sprintf(img_path, UI_GFX_LOCATION"mouse.bmp");

    // safety check, ensure the int could actually be converted
    if (strlen(img_path) < 1) {
        return "InitTextures() --> unable to assemble mouse img path";
    }

    // load the mouse graphics into memory
    tmp_surface = SDL_LoadBMP((char*) img_path);
    memset(&img_path, 0, 256*sizeof(char));
    MOUSE_GFX = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);
    SDL_FreeSurface(tmp_surface);

    // ensure calloc worked
    if (!MOUSE_GFX) {
        return "InitTextures() --> unable to calloc for mouse GFX";
    }

    // attempt to calloc mem for the desert tile textures
    DESERT_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_DESERT_MAX,
      sizeof(SDL_Texture*));

    // ensure calloc worked
    if (!DESERT_TILES) {
        DeleteTextures();
        return "InitTextures() --> unable to calloc for desert tiles";
    }

    // attempt to calloc mem for the grass tile textures
    GRASS_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_GRASS_MAX,
      sizeof(SDL_Texture*));

    // ensure calloc worked
    if (!GRASS_TILES) {
        DeleteTextures();
        return "InitTextures() --> unable to calloc for grass tiles";
    }

    // attempt to calloc mem for the swamp tile textures
    SWAMP_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_SWAMP_MAX,
      sizeof(SDL_Texture*));

    // ensure calloc worked
    if (!SWAMP_TILES) {
        DeleteTextures();
        return "InitTextures() --> unable to calloc for swamp tiles";
    }

    // Load all of the desert tiles.
    for (i = 1; i < LEVEL_TYPE_DESERT_MAX; i++) {

        // assemble the path string
        sprintf(img_path, LEVEL_TYPE_DESERT_PATH"%d.bmp", i);

        // safety check, ensure the int could actually be converted
        if (strlen(img_path) < 1) {
            DeleteTextures();
            return "InitTextures() --> unable to assemble desert img path";
        }

        // load the image into memory
        tmp_surface = SDL_LoadBMP((char*) img_path);
        memset(&img_path, 0, 256*sizeof(char));
        DESERT_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);
        SDL_FreeSurface(tmp_surface);
    }

    // Load all of the grass tiles.
    for (i = 1; i < LEVEL_TYPE_GRASS_MAX; i++) {

        // assemble the path string
        sprintf(img_path, LEVEL_TYPE_GRASS_PATH"%d.bmp", i);

        // safety check, ensure the int could actually be converted
        if (strlen(img_path) < 1) {
            DeleteTextures();
            return "InitTextures() --> unable to assemble grass img path";
        }

        // load the image into memory
        tmp_surface = SDL_LoadBMP((char*) img_path);
        memset(&img_path, 0, 256*sizeof(char));
        GRASS_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);
        SDL_FreeSurface(tmp_surface);
    }

    // Load all of the swamp tiles.
    for (i = 1; i < LEVEL_TYPE_SWAMP_MAX; i++) {

        // assemble the path string
        sprintf(img_path, LEVEL_TYPE_SWAMP_PATH"%d.bmp", i);

        // safety check, ensure the int could actually be converted
        if (strlen(img_path) < 1) {
            DeleteTextures();
            return "InitTextures() --> unable to assemble swamp img path";
        }

        // load the image into memory
        tmp_surface = SDL_LoadBMP((char*) img_path);
        memset(&img_path, 0, 256*sizeof(char));
        SWAMP_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);
        SDL_FreeSurface(tmp_surface);
    }

    return "";
}

//! Function to clear all of the loaded textures.
/*
 * @return    string    error message, if any
 *
 * TODO: consider freeing other assets here too
 */
char* DestroyAssets() {

    // variable declaration
    char* err = "";

    // attempt to clear the textures in memory
    err = DeleteTextures();

    // if an error occurs, pass it back.
    if (strlen(err) > 0) {
        return err;
    }

    // everything freed correctly
    return "";
}

//! Frees game textures from memory.
/*
 * @return    string    error message, if any
 */
char* DeleteTextures() {

    // variable declaration
    unsigned int i = 0;

    // attempt to free the mouse texture upon exit
    if (MOUSE_GFX) {
        free(MOUSE_GFX);
        MOUSE_GFX = NULL;
    }

    // If the desert textures are still loaded...
    if (DESERT_TILES) {
        for (i = 0; i < LEVEL_TYPE_DESERT_MAX; i++) {
            if (DESERT_TILES[i]) {
                free(DESERT_TILES[i]);
                DESERT_TILES[i] = NULL;
            }
        }
        free(DESERT_TILES);
        DESERT_TILES = NULL;
    }

    // If the grass textures are still loaded...
    if (GRASS_TILES) {
        for (i = 0; i < LEVEL_TYPE_GRASS_MAX; i++) {
            if (GRASS_TILES[i]) {
                free(GRASS_TILES[i]);
                GRASS_TILES[i] = NULL;
            }
        }
        free(GRASS_TILES);
        GRASS_TILES = NULL;
    }

    // If the swamp textures are still loaded...
    if (SWAMP_TILES) {
        for (i = 0; i < LEVEL_TYPE_SWAMP_MAX; i++) {
            if (SWAMP_TILES[i]) {
                free(SWAMP_TILES[i]);
                SWAMP_TILES[i] = NULL;
            }
        }
        free(SWAMP_TILES);
        SWAMP_TILES = NULL;
    }

    // all of the tile memory was freed correctly
    return "";
}

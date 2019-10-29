/*
 * Description: header for the asset loader file
 */

#ifndef ASSETLOADER_H
#define ASSETLOADER_H

// SDL include
#include <SDL2/SDL.h>

// C99 includes
#include <stdlib.h>
#include <string.h>

// Project includes
#include "globals.h"
#include "level.h"

//! Function to run all of the initial asset loading.
/*
 * @return    string    error message, if any
 */
char* LoadAssets();

//! Initializes game textures.
/*
 * @return    string    error message, if any
 */
char* InitTextures();

//! Function to clear all of the loaded textures.
/*
 * @return    string    error message, if any
 */
char* DestroyAssets();

//! Frees game textures from memory.
/*
 * @return    string    error message, if any
 */
char* DeleteTextures();

#endif

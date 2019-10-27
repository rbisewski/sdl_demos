/*
 * Description: header file for the SDL project functions
 */

#ifndef SDL_FUNCS_H
#define SDL_FUNCS_H

// SDL include
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// C99 includes
#include <stdbool.h>

// Grab the globals
#include "globals.h"

//! Start the SDL window, renderer, and hardware cursor
/*
 * @returns    bool    whether or not an error occurred
 */
bool StartupSDL();

//! Free memory formerly utilized by SDL functionality
/*
 * @return    none
 */
void DestroySDL();

#endif

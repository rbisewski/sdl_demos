/*
 * Description: header file for the game class
 */
#ifndef GAME_H
#define GAME_H

//
// SDL2 includes
//
#include <SDL2/SDL.h>

// C99 includes
#include <stdbool.h>

//
// Internal includes
//
#include "camera.h"
#include "csv.h"
#include "font.h"
#include "level.h"

/*
 * Game class
 */
typedef struct Game {

    // Camera that watches the PC during gameplay
    Camera* camera;

    // Pointer to the mouse rectangle
    SDL_Rect* mouseRect;

    // Pointer to the current level
    Level* currentLevel;

    // Pointer to the player character
    //Character* player;

} Game;

//! Function to delete memory used by a game object
/*!
 * @param      Game*     pointer to the current game instance
 *
 * @return     string    error message, if any
 */
char* DeleteGame(Game*);

//! Function to process our keyboard and mouse input
/*!
 * @param      Game*   pointer to the current game instance
 *
 * @return     bool    true  --> terminate program
 *                     false --> continue program
 */
bool ProcessInput(Game*);

#endif 

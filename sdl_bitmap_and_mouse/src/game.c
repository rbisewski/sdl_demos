/*
 * Description: functions for the game class
 */

#include "game.h"

//! Function to delete memory used by a game object
/*!
 * @param      Game*     pointer to the current game instance
 *
 * @return     string    error message, if any
 */
char* DeleteGame(Game* game) {

    // input validation
    if (!game) {
        return "DeleteGame() --> invalid input";
    }

    // Free the game camera
    if (game && game->camera) {
        free(game->camera);
        game->camera = NULL;
    }

    // Free the mouse rectangle
    if (game && game->mouseRect) {
        free(game->mouseRect);
        game->mouseRect = NULL;
    }

    // Free the current level
    if (game && game->currentLevel) {
        free(game->currentLevel);
        game->currentLevel = NULL;
    }

    if (game && game->ft) {
        if (!freeFontPoly(game->ft)) {
            return "Error: Unable to free Font polygon.";
        }
        free(game->ft);
        game->ft = NULL;
    }

    // Free the game object itself
    if (game) {
        free(game);
        game = NULL;
    }

    return "";
}

//! Function to process our keyboard and mouse input
/*!
 * @param      Game*   pointer to the current game instance
 *
 * @return     bool    true  --> terminate program
 *                     false --> continue program
 */
bool ProcessInput(Game* g) {

    // Variable declaration
    char* err    = "";
    SDL_Event event;
    int mouse_x = 0;
    int mouse_y = 0;

    // 
    // Input validation, somehow the game instance has been cleared, so
    // then pass along the signal to terminate the program.
    //
    if (!g) {
        return true;
    }

    // Clear the renderer of the previous content, if any
    SDL_RenderClear(RENDERER);

    // Poll each of the events...
    while (SDL_PollEvent(&event)) {

        // Handle the different event types.
        switch(event.type) {

            // Quiting the game
            case SDL_QUIT:
                return true;
                break;

            // Window focus lost event occurred
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {

                    // Suspend execution of the game until the window
                    // regains focus, so as to not use tons of CPU
                    // because of the lack of v-sync
                    while (true) {
                        SDL_Delay(10);
                        SDL_Event event;
                        if (SDL_PollEvent(&event)) {
                            if (event.type == SDL_QUIT) {
                                return true; // Signal to quit the program
                            }
                            if (event.type == SDL_WINDOWEVENT &&
                                event.window.event ==
                                SDL_WINDOWEVENT_FOCUS_GAINED) break;
                        }
                    }
                }
                break;

            // Window focus lost event occurred
            case SDL_KEYDOWN:

                // Escape key is pressed:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return true;

                // Otherwise F11 key is pressed:
                } else if (event.key.keysym.sym == SDLK_F11) {

                    // Switch between windowed and fullscreen.
                    uint32_t flags = SDL_GetWindowFlags(WINDOW);
                    uint32_t newFlags
                        = (flags & SDL_WINDOW_FULLSCREEN_DESKTOP ?
                                0 : SDL_WINDOW_FULLSCREEN_DESKTOP);

                    // Based on the above, set the requested mode.
                    SDL_SetWindowFullscreen(WINDOW, newFlags);

                // If the 'e' key was pressed:
                } else if (event.key.keysym.sym == SDLK_e) {

                    // Wipe away the old level
                    SDL_RenderClear(RENDERER);

                    // If swamp, set to desert.
                    if (g->currentLevel->type == LEVEL_TYPE_IS_SWAMP) {

                        // Attempt to initialize the new desert level
                        err = newLevel(g->currentLevel, "sample desert level",
                          LEVEL_TYPE_IS_DESERT);

                        // Safety check, ensure no error occurred.
                        if (strlen(err) > 0) {
                            printf(err);
                            return 1;
                        }

                    // If desert, set to grass.
                    } else if (g->currentLevel->type == LEVEL_TYPE_IS_DESERT) {

                        // Attempt to initialize the new grass level
                        err = newLevel(g->currentLevel, "sample grass level",
                          LEVEL_TYPE_IS_GRASS);

                        // Safety check, ensure no error occurred.
                        if (strlen(err) > 0) {
                            printf(err);
                            return 1;
                        }

                    // If grass, set to swamp.
                    } else if (g->currentLevel->type == LEVEL_TYPE_IS_GRASS) {

                        // Attempt to initialize the new grass level
                        err = newLevel(g->currentLevel, "sample swamp level",
                          LEVEL_TYPE_IS_SWAMP);

                        // Safety check, ensure no error occurred.
                        if (strlen(err) > 0) {
                            printf(err);
                            return 1;
                        }
                    }
                }
                break;
        }
    }

    // Default to having the desert level upon start.
    err = assembleGroundTiles(g->currentLevel, RENDERER);

    if (strlen(err) > 0) {
        printf(err);
        return 1;
    }

    // Create and SDL surface using the given font.
    err = newFontPoly(g->ft, 100, 100, 100, 100, PRIMARY_FONT,
      SDL_COLOUR_BLACK, "Press the {e} key to switch between "
      "desert / grass / swamp biomes.", RENDERER);

    if (strlen(err) > 0) {
        printf(err);
        return 1;
    }

    // Obtain the current position of the mouse.
    SDL_GetMouseState(&mouse_x, &mouse_y);

    // Set the (x,y) coords of the mouse rectangle to the current position.
    g->mouseRect->x = mouse_x;
    g->mouseRect->y = mouse_y;

    // Render the game mouse rectangle in the new location
    SDL_QueryTexture(MOUSE_GFX, NULL, NULL, &g->mouseRect->w,
      &g->mouseRect->h);
    SDL_RenderCopy(RENDERER, MOUSE_GFX, NULL, g->mouseRect);

    // Present the results to the viewer
    SDL_RenderPresent(RENDERER);

    // Signal not to quit the program
    return false;
}

/*
 * Description: Main program routine
 */

#include "main.h"

//
// Program Main
//
int main() {

    // Variable declaration
    char* err  = "";
    Game* game = NULL;
    unsigned int updateTimer   = 999;
    unsigned int timeDelta     = 0;
    unsigned int previousTicks = SDL_GetTicks();

    // Attempt to calloc some memory for the primary game object.
    game = calloc(1, sizeof(Game));

    // Safety check, ensure no error occurred.
    if (!game) {
        printf("Error: Unable to calloc memory for the game object\n");
        return 1;
    }

    // Initialize SDL, or end if an error occurred.
    if (!StartupSDL()) {
        return 1;
    }

    // Clear away and data from the previous render.
    SDL_RenderClear(RENDERER);

    // Go ahead and load all of the assets
    err = LoadAssets();

    // terminate the program if an error occurred
    if (strlen(err) > 0) {
        printf(err);
        return 1;
    }

    // Attempt to initialize the internal variables of the newly calloc'd
    // game object.
    /*
    if (!initializeGame(game)) {
        printf("Error: unable to initialize game variables!\n");
        return 1;
    }
    */

    game->ft = (FontPoly*) calloc(1, sizeof(FontPoly));
    if (!game->ft) {
        printf("Error: calloc of FontTexture failed\n");
        return 1;
    }
   
    // attempt to calloc space for the mouse rectangle
    game->mouseRect = calloc(1, sizeof(SDL_Rect));

    // Safety check, ensure no error occurred.
    if (!game->mouseRect) {
        printf("Error: Unable to calloc memory for the mouse rectangle\n");
        return 1;
    }

    // Set the current game level to the initial level
    game->currentLevel = calloc(1, sizeof(Level));

    // Safety check, ensure no error occurred.
    if (!game->currentLevel) {
        printf("Error: Unable to calloc memory for current game level\n");
        return 1;
    }

    // Attempt to initialize the new desert level
    err = newLevel(game->currentLevel, "sample desert level",
      LEVEL_TYPE_IS_DESERT);

    // Safety check, ensure no error occurred.
    if (strlen(err) > 0) {
        printf(err);
        return 1;
    }

    // Assign the basic properties of the mouse rectangle
    game->mouseRect->x = 300;
    game->mouseRect->y = 400;
    game->mouseRect->w = 20;
    game->mouseRect->h = 40;

    // Attach the game mouse rectangle to the render
    SDL_QueryTexture(MOUSE_GFX, NULL, NULL, &game->mouseRect->w,
      &game->mouseRect->h);
    SDL_RenderCopy(RENDERER, MOUSE_GFX, NULL, game->mouseRect);

    // Have the render present to the desktop.
    SDL_RenderPresent(RENDERER);

    // Infinite game loop begins here...
    while (true) {

        // Grab the current difference in time vs the previous loop
        timeDelta = SDL_GetTicks() - previousTicks;

        // Determine the 
        previousTicks = SDL_GetTicks();

        // Adjust the game timer based on the current time differential.
        updateTimer += timeDelta;

        // If the game gave a quit signal...
        if (ProcessInput(game)) {

            // Go ahead and attempt to free the game object.
            //DestroyEverything(game);
            break;
        }

        // Sync the game screen render to the SDL frame rate.
        if (updateTimer >= 1000 / FPS) {

            // Reset the timer.
            updateTimer = 0;

            // Update the game assets.
            //UpdateGame(game);
        }

        // Render the current screen of the game
        //DrawGame(game, RENDERER);
    }

    // Free all memory used by the game assets
    DestroyAssets();

    // Free memory used by SDL
    DestroySDL();

    // If the game object is still using memory, go ahead and clear it.
    err = DeleteGame(game);

    // Safety check, ensure no error occurred.
    if (strlen(err) > 0) {
        printf(err);
        return 1;
    }

    // If the program got this far, go ahead and exit with a success.
    return 0;
}

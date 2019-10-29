/*
 * Description: holds SDL project functions.
 */
#include "sdl_funcs.h"

//! Start the SDL window, renderer, and hardware cursor
/*
 * @returns    bool    whether or not an error occurred
 */
bool StartupSDL() {

    // Variable declaration
    int rc = 0;

    // Initialize SDL functionality.
    rc = SDL_Init(SDL_INIT_EVERYTHING);

    // Ensure that the init could be started correctly.
    if (rc < 0) {
        return false;
    }

    // Initialize libfreetype.
    rc = TTF_Init();

    // Ensure that libfreetype could be started correctly.
    if (rc < 0) {
        return false;
    }

    // Alloc mem for the primary game font.
    PRIMARY_FONT = TTF_OpenFont(PRIMARY_FONT_LOCATION, PRIMARY_FONT_SIZE);

    // Ensure that the program could actually obtain the font.
    if (!PRIMARY_FONT) {
        return false;
    }

    // Initialize the primary game window.
    WINDOW = SDL_CreateWindow(WINDOW_NAME,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCALED_SCREEN_W,
                              SCALED_SCREEN_H,
                              0);

    //
    // Initalize the primary game renderer.
    //
    RENDERER = SDL_CreateRenderer(WINDOW, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC |
                                  SDL_RENDERER_TARGETTEXTURE);

    // Define the pixel scaling technique used.
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); 
    
    // Set the size we want to screen to appear on the display.
    SDL_RenderSetLogicalSize(RENDERER, SCALED_SCREEN_W, SCALED_SCREEN_H);

    // Hide the cursor
    SDL_ShowCursor(0);

    // All is well, so return true.
    return true;
}

//! Free memory formerly utilized by SDL functionality
/*
 * @return    none
 */
void DestroySDL() {

    // Close the font files and free their memory.
    TTF_CloseFont(PRIMARY_FONT);

    // Wipe away the current screen
    SDL_RenderClear(RENDERER);

    // Free memory used by the renderer
    //
    // TODO: this doesn't appear to work and causes errors.
    //
    //SDL_DestroyRenderer(RENDERER);

    // Free memory used by the window
    SDL_DestroyWindow(WINDOW);

    // Close SDL
    SDL_Quit();
}

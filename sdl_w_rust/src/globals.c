#include "globals.h"

// Screen height and width
int SCALED_SCREEN_W = SCREEN_W * GRAPHICS_SCALE;
int SCALED_SCREEN_H = SCREEN_H * GRAPHICS_SCALE;

// Main game font.
TTF_Font* PRIMARY_FONT          = NULL;
char*     PRIMARY_FONT_LOCATION = "fonts/EightBit.ttf";
int       PRIMARY_FONT_SIZE     = 32;

// Assign the primary text colour.
SDL_Color SDL_COLOUR_EGGSHELL = {201, 201, 201, 255};
SDL_Color SDL_COLOUR_BLACK    = {  0,   0,   0, 255};

// Variable that holds our SDL Window (i.e. everything)
SDL_Window* WINDOW;

// Variable that stores a pointer to our renderer.
SDL_Renderer* RENDERER;

// Variables for our essential textures and sprites rectangles.
SDL_Texture*  MOUSE_GFX    = NULL;
SDL_Texture** DESERT_TILES = NULL;
SDL_Texture** GRASS_TILES  = NULL;
SDL_Texture** SWAMP_TILES  = NULL;

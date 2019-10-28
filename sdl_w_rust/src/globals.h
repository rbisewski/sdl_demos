#ifndef GLOBALS_H
#define GLOBALS_H

// SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Defines
#define FPS 60
#define GRAPHICS_SCALE 1
#define SCREEN_W 1024
#define SCREEN_H 720

#define WINDOW_NAME "Tiling and Level and Mouse Demo"

// TODO: delete these if the CSV header meshes well with Rust
//
//#define CSV_LINE_BUFFER_SIZE 16
//#define CSV_COLUMN_MAX 48
//#define CSV_ROW_MAX 32

extern int SCALED_SCREEN_W;
extern int SCALED_SCREEN_H;

extern TTF_Font* PRIMARY_FONT;
extern char* PRIMARY_FONT_LOCATION;
extern int PRIMARY_FONT_SIZE;

extern SDL_Color SDL_COLOUR_EGGSHELL;
extern SDL_Color SDL_COLOUR_BLACK;

extern SDL_Window* WINDOW;
extern SDL_Renderer* RENDERER;

// Location of the UI graphics elements
#define UI_GFX_LOCATION "img/ui/"

extern SDL_Texture*  MOUSE_GFX;
extern SDL_Texture** DESERT_TILES;
extern SDL_Texture** GRASS_TILES;
extern SDL_Texture** SWAMP_TILES;

#endif

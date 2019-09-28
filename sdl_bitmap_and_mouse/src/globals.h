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

//#define WINDOW_NAME "Project Nova Nine"
#define WINDOW_NAME "Tiling and Level and Mouse Demo"

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

//extern SDL_Texture* SPRITE_TEXTURE;
//extern SDL_Texture* BG_TEXTURE;
//extern SDL_Rect* COLLISION_MASK_RECTS;
//extern SDL_Rect* SPRITE_RECTS;

// Variable to store our worldmap object.
//extern Map* WORLDMAP = NULL;

// Variable to store our character / world map animations.
//extern Animation* ANIMATIONS = NULL;

// Variable to store our array of sprite / character collision masks.
//extern CollisionMask** COLLISION_MASKS = NULL;

#endif

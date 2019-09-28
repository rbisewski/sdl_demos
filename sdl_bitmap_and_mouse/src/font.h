#ifndef FONT_H
#define FONT_H

// SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// C99 includes
#include <stdbool.h>

//
// FontPoly definition
//
typedef struct FontPoly {
    TTF_Font*    ttf;
    SDL_Rect*    rect;
    SDL_Color    color;
    SDL_Surface* surface;
    SDL_Texture* texture;
} FontPoly;

//! Create a new font polygon object.
/*
 * @param    FontPoly*       pointer to new object to initialize
 * @param    int             x coord
 * @param    int             y coord
 * @param    int             height
 * @param    int             width
 * @param    TTF_Font*       SDL font object pointer 
 * @param    char*           ascii text value to render
 * @param    SDL_Renderer*   pointer to the global renderer
 *
 * @return   string          error message, if any
 */
char* newFontPoly(FontPoly*, int, int, int, int, TTF_Font*,
  SDL_Color, const char* const, SDL_Renderer*);

//! Frees an existing font polygon object.
/*
 * @param    FontPoly*       pointer to an object to free
 *
 * @return   bool            whether or not it was freed correctly
 */
bool freeFontPoly(FontPoly*);

#endif

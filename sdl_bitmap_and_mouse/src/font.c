/*
 * Description: handle fonts and create textures from font text
 */
#include "font.h"

//! Create a new font texture object.
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
 * @return   string   error message, if any
 */
char* newFontPoly(FontPoly* ft, int x, int y, int h, int w,
  TTF_Font* ttf, SDL_Color color, const char* const text,
  SDL_Renderer* renderer) {

    // Input validation.
    if (h < 0 || w < 0 || !ttf || strlen(text) < 1) {
        return "newFontPoly() --> invalid input";
    }

    // Attempt to assign a chunk of memory for the FontPoly object.
    ft = (FontPoly*) calloc(1, sizeof(FontPoly));

    // Ensure the calloc worked.
    if (!ft) {
        return "newFontPoly() --> calloc of FontTexture failed";
    }

    // Assign the given TTF to the font poly.
    ft->ttf = ttf;

    // Calloc memory for the SDL rectangle.
    ft->rect = (SDL_Rect*) calloc(1, sizeof(SDL_Rect));

    // Ensure the rectangle was generated correctly.
    if (!ft->rect) {
        free(ft);
        return "newFontPoly() --> calloc of SDL_Rect failed";
    }

    // Set the internal rectangle properties.
    ft->rect->x = x;
    ft->rect->y = y;
    ft->rect->w = w;
    ft->rect->h = h;
 
    // Generate a SDL surface object using the given font and text.
    ft->surface = TTF_RenderText_Blended(ttf, (char*) text, color);

    // Ensure the surface was generated correctly.
    if (!ft->surface) {
        free(ft);
        free(ft->rect);
        return "newFontPoly() --> TTF_RenderText_Blended failed";
    }

    // Create a SDL texture from the surface.
    ft->texture = SDL_CreateTextureFromSurface(renderer, ft->surface);

    // Ensure the surface was generated correctly.
    if (!ft->texture) {
        free(ft);
        free(ft->rect);
        free(ft->surface);
        return "newFontPoly() --> SDL_CreateTextureFromSurface failed";
    }

    // Assign the texture to the surface, and attach it to the renderer.
    SDL_QueryTexture(ft->texture, NULL, NULL, &ft->rect->w, &ft->rect->h);
    SDL_RenderCopy(renderer, ft->texture, NULL, ft->rect);

    // Everything was good, so return the empty string.
    return "";
}

//! Frees an existing font polygon object.
/*
 * @param    FontPoly*       pointer to an object to free
 *
 * @return   bool            whether or not it was freed correctly
 */
bool freeFontPoly(FontPoly* ft) {

    if (!ft) {
        return true;
    }

    if (ft->texture) {
        free(ft->texture);
        ft->texture = NULL;
    }

    if (ft->rect) {
        free(ft->rect);
        ft->rect = NULL;
    }

    if (ft->surface) {
        free(ft->surface);
        ft->surface = NULL;
    }

    return true;
}

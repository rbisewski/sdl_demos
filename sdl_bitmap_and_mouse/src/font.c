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

    if (h < 0 || w < 0 || !ttf || strlen(text) < 1) {
        return "newFontPoly() --> invalid input";
    }

    // Assign the given TTF to the font poly.
    ft->ttf = ttf;

    if (!ft->rect) {
        ft->rect = (SDL_Rect*) calloc(1, sizeof(SDL_Rect));
        if (!ft->rect) {
            return "newFontPoly() --> calloc of SDL_Rect failed";
        }
    }

    // Set the internal rectangle properties.
    ft->rect->x = x;
    ft->rect->y = y;
    ft->rect->w = w;
    ft->rect->h = h;

    // Generate a SDL surface object using the given font and text.
    if (ft->surface) {
        SDL_FreeSurface(ft->surface);
    }
    ft->surface = TTF_RenderText_Blended(ttf, (char*) text, color);
    if (!ft->surface) {
        free(ft->rect);
        ft->rect = NULL;
        return "newFontPoly() --> TTF_RenderText_Blended failed";
    }

    // Create a SDL texture from the surface.
    if (ft->texture) {
        SDL_DestroyTexture(ft->texture);
    }
    ft->texture = SDL_CreateTextureFromSurface(renderer, ft->surface);
    if (!ft->texture) {
        free(ft->rect);
        ft->rect = NULL;
        SDL_FreeSurface(ft->surface);
        ft->surface = NULL;
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
        SDL_DestroyTexture(ft->texture);
        ft->texture = NULL;
    }

    if (ft->rect) {
        free(ft->rect);
        ft->rect = NULL;
    }

    if (ft->surface) {
        SDL_FreeSurface(ft->surface);
        ft->surface = NULL;
    }

    return true;
}

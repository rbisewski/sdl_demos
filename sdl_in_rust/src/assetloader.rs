/*
 * Description: functions for loading assets
 */
extern crate sdl2;

use std::path::PathBuf;
use sdl2::render::*;
use sdl2::surface::*;

pub const UI_GFX_LOCATION: &str = "img/ui/";

pub fn init_textures() -> Result<(), String> {

    let path_to_mouse_gfx: PathBuf = [UI_GFX_LOCATION, "mouse.bmp"].iter().collect();

    let path_to_mouse_gfx_canon = match path_to_mouse_gfx.canonicalize() {
        Err(e) => return Err(e.to_string()),
        Ok(path_to_mouse_gfx_canon) => path_to_mouse_gfx_canon,
    };

    let sdl_tmp_surface = Surface::load_bmp(path_to_mouse_gfx_canon);

    //let MOUSE_GFX = Texture::create_texture_from_surface(sdl_tmp_surface);

    //// load the mouse graphics into memory
    //tmp_surface = SDL_LoadBMP((char*) img_path);
    //memset(&img_path, 0, 256*sizeof(char));
    //MOUSE_GFX = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);
    //SDL_FreeSurface(tmp_surface);
    //tmp_surface = NULL;

    //// ensure calloc worked
    //if (!MOUSE_GFX) {
    //    return "InitTextures() --> unable to calloc for mouse GFX";
    //}

    //// attempt to calloc mem for the desert tile textures
    //DESERT_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_DESERT_MAX,
    //  sizeof(SDL_Texture*));

    //// ensure calloc worked
    //if (!DESERT_TILES) {
    //    DeleteTextures();
    //    return "InitTextures() --> unable to calloc for desert tiles";
    //}

    //// attempt to calloc mem for the grass tile textures
    //GRASS_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_GRASS_MAX,
    //  sizeof(SDL_Texture*));

    //// ensure calloc worked
    //if (!GRASS_TILES) {
    //    DeleteTextures();
    //    return "InitTextures() --> unable to calloc for grass tiles";
    //}

    //// attempt to calloc mem for the swamp tile textures
    //SWAMP_TILES = (SDL_Texture**) calloc(LEVEL_TYPE_SWAMP_MAX,
    //  sizeof(SDL_Texture*));

    //// ensure calloc worked
    //if (!SWAMP_TILES) {
    //    DeleteTextures();
    //    return "InitTextures() --> unable to calloc for swamp tiles";
    //}

    //// Load all of the desert tiles.
    //for (i = 1; i < LEVEL_TYPE_DESERT_MAX; i++) {

    //    // assemble the path string
    //    sprintf(img_path, LEVEL_TYPE_DESERT_PATH"%d.bmp", i);

    //    if (strlen(img_path) < 1) {
    //        DeleteTextures();
    //        return "InitTextures() --> unable to assemble desert img path";
    //    }

    //    tmp_surface = SDL_LoadBMP((char*) img_path);
    //    if (!tmp_surface) {
    //        return "InitTextures() --> unable to open file in: "LEVEL_TYPE_DESERT_PATH;
    //    }

    //    // load the image into memory
    //    memset(&img_path, 0, 256*sizeof(char));
    //    DESERT_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

    //    SDL_FreeSurface(tmp_surface);
    //    tmp_surface = NULL;
    //}

    //// Load all of the grass tiles.
    //for (i = 1; i < LEVEL_TYPE_GRASS_MAX; i++) {

    //    // assemble the path string
    //    sprintf(img_path, LEVEL_TYPE_GRASS_PATH"%d.bmp", i);

    //    if (strlen(img_path) < 1) {
    //        DeleteTextures();
    //        return "InitTextures() --> unable to assemble grass img path";
    //    }

    //    tmp_surface = SDL_LoadBMP((char*) img_path);
    //    if (!tmp_surface) {
    //        return "InitTextures() --> unable to open file in: "LEVEL_TYPE_GRASS_PATH;
    //    }

    //    // load the image into memory
    //    memset(&img_path, 0, 256*sizeof(char));
    //    GRASS_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

    //    SDL_FreeSurface(tmp_surface);
    //    tmp_surface = NULL;
    //}

    //// Load all of the swamp tiles.
    //for (i = 1; i < LEVEL_TYPE_SWAMP_MAX; i++) {

    //    // assemble the path string
    //    sprintf(img_path, LEVEL_TYPE_SWAMP_PATH"%d.bmp", i);

    //    if (strlen(img_path) < 1) {
    //        DeleteTextures();
    //        return "InitTextures() --> unable to assemble swamp img path";
    //    }

    //    tmp_surface = SDL_LoadBMP((char*) img_path);
    //    if (!tmp_surface) {
    //        return "InitTextures() --> unable to open file in: "LEVEL_TYPE_SWAMP_PATH;
    //    }

    //    // load the image into memory
    //    memset(&img_path, 0, 256*sizeof(char));
    //    SWAMP_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

    //    SDL_FreeSurface(tmp_surface);
    //    tmp_surface = NULL;
    //}

    Ok(())
}

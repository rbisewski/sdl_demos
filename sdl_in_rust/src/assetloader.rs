/*
 * Description: functions for loading assets
 */

extern crate sdl2;

use std::path::PathBuf;
use sdl2::surface::*;

use std::collections::HashMap;

pub const UI_GFX_LOCATION: &str = "img/ui/";
pub const LEVEL_TYPE_DESERT_PATH: &str = "img/desert/";
pub const LEVEL_TYPE_GRASS_PATH: &str = "img/grass/";
pub const LEVEL_TYPE_SWAMP_PATH: &str = "img/swamp/";

pub const LEVEL_TYPE_DESERT_MAX: i32 = 6;
pub const LEVEL_TYPE_GRASS_MAX: i32 = 14;
pub const LEVEL_TYPE_SWAMP_MAX: i32 = 13;

//
// Assets
//
pub struct Assets {
    textures: HashMap<&'static str, sdl2::render::Texture<'static>>
}

pub fn init_textures(assets: &Assets, canvas: &sdl2::render::Canvas<sdl2::video::Window>) -> Result<(), String> {

    let path_to_mouse_gfx: PathBuf = [UI_GFX_LOCATION, "mouse.bmp"].iter().collect();

    let path_to_mouse_gfx_canon = match path_to_mouse_gfx.canonicalize() {
        Err(e) => return Err(e.to_string()),
        Ok(p) => p,
    };

    let mouse_surface = match Surface::load_bmp(path_to_mouse_gfx_canon) {
        Err(e) => return Err(e.to_string()),
        Ok(s) => s,
    };

    let mouse_tc = canvas.texture_creator();
    let mouse_gfx = match mouse_tc.create_texture_from_surface(mouse_surface) {
        Err(e) => return Err(e.to_string()),
        Ok(r) => r,
    };

    // TODO: implement this
    //TEXTURES.insert(&String::from("mouse_gfx"), mouse_gfx);

    // Load all of the desert tiles.
    for i in 1..LEVEL_TYPE_DESERT_MAX {

        let path: PathBuf = [LEVEL_TYPE_DESERT_PATH, &format!("{}",i), ".bmp"].iter().collect();

        let path_canon = match path.canonicalize() {
            Err(e) => return Err(e.to_string()),
            Ok(p) => p,
        };

        //tmp_surface = SDL_LoadBMP((char*) img_path);
        //if (!tmp_surface) {
        //    return "InitTextures() --> unable to open file in: "LEVEL_TYPE_DESERT_PATH;
        //}

        //// load the image into memory
        //memset(&img_path, 0, 256*sizeof(char));
        //DESERT_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

        //SDL_FreeSurface(tmp_surface);
        //tmp_surface = NULL;
    }

    // Load all of the grass tiles.
    for i in 1..LEVEL_TYPE_GRASS_MAX {

        let path: PathBuf = [LEVEL_TYPE_GRASS_PATH, &format!("{}",i), ".bmp"].iter().collect();

        let path_canon = match path.canonicalize() {
            Err(e) => return Err(e.to_string()),
            Ok(p) => p,
        };

        //tmp_surface = SDL_LoadBMP((char*) img_path);
        //if (!tmp_surface) {
        //    return "InitTextures() --> unable to open file in: "LEVEL_TYPE_GRASS_PATH;
        //}

        //// load the image into memory
        //memset(&img_path, 0, 256*sizeof(char));
        //GRASS_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

        //SDL_FreeSurface(tmp_surface);
        //tmp_surface = NULL;
    }

    // Load all of the swamp tiles.
    for i in 1..LEVEL_TYPE_SWAMP_MAX {

        let path: PathBuf = [LEVEL_TYPE_SWAMP_PATH, &format!("{}",i), ".bmp"].iter().collect();

        let path_canon = match path.canonicalize() {
            Err(e) => return Err(e.to_string()),
            Ok(p) => p,
        };

        //tmp_surface = SDL_LoadBMP((char*) img_path);
        //if (!tmp_surface) {
        //    return "InitTextures() --> unable to open file in: "LEVEL_TYPE_SWAMP_PATH;
        //}

        //// load the image into memory
        //memset(&img_path, 0, 256*sizeof(char));
        //SWAMP_TILES[i-1] = SDL_CreateTextureFromSurface(RENDERER, tmp_surface);

        //SDL_FreeSurface(tmp_surface);
        //tmp_surface = NULL;
    }

    Ok(())
}

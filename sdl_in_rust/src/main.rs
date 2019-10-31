extern crate sdl2;

use sdl2::pixels::Color;
use sdl2::event::Event;
use sdl2::keyboard::Keycode;
use std::time::Duration;

mod assetloader;

pub fn main() {
    let sdl_context = match sdl2::init() {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(sdl_context) => sdl_context,
    };

    let video_subsystem = match sdl_context.video() {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(video_subsystem) => video_subsystem,
    };

    let window = match video_subsystem
        .window("SDL2 demo", 800, 600)
        .position_centered()
        .build() {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(window) => window,
    };

    let mut canvas = match window.into_canvas().build() {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(canvas) => canvas,
    };

    canvas.set_draw_color(Color::RGB(0, 255, 255));
    canvas.clear();
    canvas.present();

    // load the textures
    let _ = match assetloader::init_textures(&canvas) {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(r) => r,
    };

    let mut event_pump = match sdl_context.event_pump() {
        Err(e) => {
            println!("{:?}", e);
            return;
        },
        Ok(event_pump) => event_pump,
    };

    let mut i = 0;
    'running: loop {
        i = (i + 1) % 255;
        canvas.set_draw_color(Color::RGB(i, 64, 255 - i));
        canvas.clear();
        for event in event_pump.poll_iter() {
            match event {
                Event::Quit {..} |
                Event::KeyDown { keycode: Some(Keycode::Escape), .. } => {
                    break 'running
                },
                _ => {}
            }
        }
        // The rest of the game loop goes here...

        canvas.present();
        ::std::thread::sleep(Duration::new(0, 1_000_000_000u32 / 60));
    }
}

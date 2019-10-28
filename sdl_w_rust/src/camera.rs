#![crate_type = "staticlib"]
#![no_std]

extern crate std;

//
// Camera
//
#[repr(C)]
pub struct Camera {
    x: i32,
    y: i32,
}

//
// Size
//
#[repr(C)]
pub struct Size {
    w: i32,
    h: i32,
}

// Force the camera to be centred at a given position.
//
// @param    Camera   the camera to centre
// @param    int      x-coord
// @param    int      y-coord
// @param    Size     the size of the camera window
// @param    int      screen width, in pixels
// @param    int      screen height, in pixels
// 
// @return   none
//
#[no_mangle]
pub extern "C" fn CentreOn(mut camera: Camera, x: i32, y: i32, window: Size, screen_width: i32, screen_height: i32) {
    camera.x = (x + (window.w / 2)) - (screen_width / 2);
    camera.y = (y + (window.h / 2)) - (screen_height / 2);
}

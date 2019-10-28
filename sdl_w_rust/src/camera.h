#ifndef CAMERA_H
#define CAMERA_H

#include "globals.h"

typedef struct Camera {
    int x;
    int y;
} Camera;

typedef struct Size {
    int w;
    int h;
} Size;

//! Force the camera to be centred at a given position.
/*
 * @param    Camera   the camera to centre
 * @param    int      x-coord
 * @param    int      y-coord
 * @param    Size     the size of the camera window
// @param    int      screen width, in pixels
// @param    int      screen height, in pixels
 *
 * @return   none
 */
void CenterOn(Camera, int, int, Size, int, int);

#endif

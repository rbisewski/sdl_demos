#ifndef CAMERA_H
#define CAMERA_H

#include "globals.h"
#include "size.h"

typedef struct Camera {
    int x;
    int y;
} Camera;

//! Force the camera to be centred at a given position.
/*
 * @param    Camera   the camera to centre
 * @param    int      x-coord
 * @param    int      y-coord
 * @param    Size     the size of the camera window
 *
 * @return   none
 */
void CenterOn(Camera, int, int, Size);

#endif

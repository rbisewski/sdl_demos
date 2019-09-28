#include "camera.h"

//! Force the camera to be centred at a given position.
/*
 * @param    Camera   the camera to centre
 * @param    int      x-coord
 * @param    int      y-coord
 * @param    Size     the size of the camera window
 *
 * @return   none
 */
void CenterOn(Camera c, int x, int y, Size objectSize) {

    // Grab a ref to the camera here.
    c = c;

    // Calculate the X coord of the camera location.
    c.x = (x + (objectSize.w / 2)) - (SCREEN_W / 2);

    // Calculate the Y coord of the camera location.
    c.y = (y + (objectSize.h / 2)) - (SCREEN_H / 2);

    // The camera has since been centred.
    return;
}

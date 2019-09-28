# SDL2 Demos

Contains code of various small SDL2 demos made over the years. Currently this
includes the following:

* SDL2 example of loading bitmaps and tracking mouse movement

Please note that this is primarily tested on Linux, and the SDL2 libraries
were installed using either `apt` or `pacman`.

### SDL2 Bitmap + Mouse demo

Demonstrates a loading of simple textures and TrueType fonts and mouse
movement across the screen.

Build the project like so:

```bash
make
```

In order to run this demo, you'll need to have the following libraries and
headers present on your include path:

* SDL2
* SDL2 TTF

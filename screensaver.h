//
// Created by joconnor on 6/29/19.
//

#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include<stdlib.h>
#include<unistd.h>
#include<X11/Xlib.h>

#include "./vroot.h"

#define NCOLORS 8

void color_rgb(unsigned short r, unsigned short g, unsigned short b, XColor *color);
void allocate_colors(Display *display, XColor colors[]);
unsigned short map_rgb(unsigned short value);

#endif //SIMPLE_EXAMPLE_SCREENSAVER_H

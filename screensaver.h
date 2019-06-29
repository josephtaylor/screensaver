//
// Created by joconnor on 6/29/19.
//

#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include<stdlib.h>
#include<unistd.h>
#include<X11/Xlib.h>

#include "./vroot.h"

#define NCOLORS 32

/*!
 *
 * This populates the given color with the r,g,b values.
 *
 * @param r         the red value
 * @param g         the green value
 * @param b         the blue value
 * @param color     the color to be populated
 */
void color_rgb(unsigned short r, unsigned short g, unsigned short b, XColor *color);

/*!
 * Allocates a random set of colors that is NCOLORS long.
 *
 * @param display   the display
 * @param colors    the color array to be populated
 */
void allocate_colors(Display *display, XColor colors[]);

/*!
 * This maps a value from -255 to 255 to USHORT_MIN to USHORT_MAX
 *
 * @param value     number between -255 and 255
 * @return          the mapped number.
 */
unsigned short map_rgb(unsigned short value);

#endif //SIMPLE_EXAMPLE_SCREENSAVER_H

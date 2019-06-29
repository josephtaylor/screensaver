#include <zconf.h>
#include <time.h>
#include "screensaver.h"

void color_rgb(unsigned short r, unsigned short g, unsigned short b, XColor *color) {
    color->flags = DoRed | DoGreen | DoBlue;
    color->red = r;
    color->green = g;
    color->blue = b;
}

unsigned short map_rgb(unsigned short value) {
    float ratio = (float) value / 255;
    return (unsigned short) (ratio * (float) USHRT_MAX);
}

void allocate_colors(Display *display, XColor colors[]) {
    int i;
    XColor color;
    for (i = 0; i < NCOLORS; i++) {
        color_rgb(map_rgb(random()%255), map_rgb(random()%255), map_rgb(random()%255), &color);
        XAllocColor(display,
                    DefaultColormapOfScreen(DefaultScreenOfDisplay(display)),
                    &color);
        colors[i] = color;
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main() {
    time_t t;
    srandom((unsigned) time(&t));
    Display *display = XOpenDisplay(getenv("DISPLAY"));
    Window root = DefaultRootWindow(display);
    GC gc = XCreateGC(display, root, 0, NULL);

    XWindowAttributes wa;
    XGetWindowAttributes(display, root, &wa);

    XColor xcolors[NCOLORS];

    allocate_colors(display, xcolors);

    while (1) {
        XClearWindow(display, root);
        for (int i = 0; i < 100; i ++) {
            XPoint point;
            point.x = random() % wa.width;
            point.y = random() % wa.height;
            XSetForeground(display, gc, xcolors[random() % NCOLORS].pixel);
            XFillRectangle(display, root, gc, point.x, point.y, 30, 30);
        }
        XFlush(display);
        usleep(10000);
    }

    XCloseDisplay(display);
    return 0;
}
#pragma clang diagnostic pop
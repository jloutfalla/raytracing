#ifndef COLOR_H
#define COLOR_H

#include <cstdio>
#include "vec3.h"

void write_color(FILE* out, const color& pixel, int samples_per_pixel);

#endif /* COLOR_H */

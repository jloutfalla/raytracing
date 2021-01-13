#include "color.h"

void write_color(FILE* out, const color& pixel)
{
  fprintf(out,
          "%d %d %d\n",
          int(255.999 * pixel.x()),
          int(255.999 * pixel.y()),
          int(255.999 * pixel.z()));
}

#include "color.h"
#include "utils.h"

void write_color(FILE* out, const color& pixel, int samples_per_pixel)
{
  double r = pixel.x();
  double g = pixel.y();
  double b = pixel.z();

  // Divide the color by the number of samples
  double scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;
  
  fprintf(out,
          "%d %d %d\n",
          int(256 * clamp(r, 0.0, 0.999)),
          int(256 * clamp(g, 0.0, 0.999)),
          int(256 * clamp(b, 0.0, 0.999)));
}

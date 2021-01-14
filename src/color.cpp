#include "color.h"
#include "utils.h"

void write_color(FILE* out, const color& pixel, int samples_per_pixel)
{
  double r = pixel.x();
  double g = pixel.y();
  double b = pixel.z();
  
  // Divide the color by the number of samples
  double scale = 1.0 / samples_per_pixel;
  double gamma = 2.2;
  r = pow(scale * r, 1.0 / gamma);
  g = pow(scale * g, 1.0 / gamma);
  b = pow(scale * b, 1.0 / gamma);
  
  fprintf(out,
          "%d %d %d\n",
          int(256 * clamp(r, 0.0, 0.999)),
          int(256 * clamp(g, 0.0, 0.999)),
          int(256 * clamp(b, 0.0, 0.999)));
}

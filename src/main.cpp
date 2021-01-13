#include <cstdio>
#include <cmath>
#include <memory>

#include "utils.h"
#include "vec3.h"
#include "ray.h"
#include "hittable_list.h"
#include "sphere.h"
#include "color.h"

color ray_color(const ray& r, const hittable& world);

int main()
{
  int i, j;

  // Image
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = int(image_width / aspect_ratio);

  // World
  hittable_list world;
  world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));
  
  // Camera
  double viewport_height = 2.0;
  double viewport_width = aspect_ratio * viewport_height;
  double focal_length = 1.0;

  point3 origin(0, 0, 0);
  vec3 horizontal(viewport_width, 0, 0);
  vec3 vertical(0, viewport_height, 0);
  point3 lower_left_corner = (origin - horizontal / 2 -
                              vertical / 2 - vec3(0, 0, focal_length));

  // Render
  printf("P3\n%d %d\n255\n", image_width, image_height);

  for (j = image_height - 1; j >= 0; --j)
    {
      fprintf(stderr, "\rScanlines remainings: %d ", j);
      fflush(stderr);
      for (i = 0; i < image_width; ++i)
        {
          double u = double(i) / (image_width - 1);
          double v = double(j) / (image_height - 1);
          ray r(origin,
                lower_left_corner + u * horizontal + v * vertical - origin);
          
          color pixel = ray_color(r, world);
          write_color(stdout, pixel);
        }
    }
  fprintf(stderr, "\nDone\n");
  
  return 0;
}

color ray_color(const ray& r, const hittable& world)
{
  hit_record rec;
  if (world.hit(r, 0, infinity, rec))
    return 0.5 * (rec.n + color(1, 1, 1));
  
  vec3 u = normalize(r.direction());
  double t = 0.5 * (u.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

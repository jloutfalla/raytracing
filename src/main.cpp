#include <cstdio>
#include <cmath>
#include <memory>

#include "utils.h"
#include "vec3.h"
#include "camera.h"
#include "ray.h"
#include "hittable_list.h"
#include "sphere.h"
#include "color.h"

color ray_color(const ray& r, const hittable& world, int depth);

int main()
{
  // Image
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = int(image_width / aspect_ratio);
  const int samples_per_pixel = 100;
  const int max_depth = 50;

  // World
  hittable_list world;
  world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));
  
  // Camera
  camera cam;

  // Render
  printf("P3\n%d %d\n255\n", image_width, image_height);

  for (int j = image_height - 1; j >= 0; --j)
    {
      fprintf(stderr, "\rScanlines remainings: %d ", j);
      fflush(stderr);
      for (int i = 0; i < image_width; ++i)
        {
          color pixel(0, 0, 0);
          
          for (int s = 0; s < samples_per_pixel; ++s)
            {
              double u = (i + randomd()) / (image_width - 1);
              double v = (j + randomd()) / (image_height - 1);
              ray r = cam.get_ray(u, v);
              pixel += ray_color(r, world, max_depth);
            }
          
          write_color(stdout, pixel, samples_per_pixel);
        }
    }
  fprintf(stderr, "\nDone\n");
  
  return 0;
}

color ray_color(const ray& r, const hittable& world, int depth)
{
  hit_record rec;

  if (depth <= 0)
    return color(0, 0, 0);
  
  if (world.hit(r, EPSILON, infinity, rec))
    {
      point3 target = rec.p + rec.n + random_in_hemisphere(rec.n);
      return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1);
    }
  
  vec3 u = normalize(r.direction());
  double t = 0.5 * (u.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

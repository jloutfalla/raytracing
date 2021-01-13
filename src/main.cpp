#include <cstdio>

#include "vec3.h"
#include "ray.h"
#include "color.h"

color ray_color(const ray& r);
bool hit_sphere(const point3& center, double radius, const ray& r);

int main()
{
  int i, j;

  // Image
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = int(image_width / aspect_ratio);

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
          
          color pixel = ray_color(r);
          write_color(stdout, pixel);
        }
    }
  fprintf(stderr, "\nDone\n");
  
  return 0;
}

color ray_color(const ray& r)
{
  if (hit_sphere(point3(0, 0, -1), 0.5, r))
    return color(1, 0, 0);
  
  vec3 u = normalize(r.direction());
  double t = 0.5 * (u.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

bool hit_sphere(const point3& center, double radius, const ray& r)
{
  vec3 oc = r.origin() - center;
  double a = dot(r.direction(), r.direction());
  double b = 2.0 * dot(oc, r.direction());
  double c = dot(oc, oc) - radius * radius;
  double discriminant = b * b - 4 * a * c;
  
  return discriminant > 0;
}

#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable
{
public:
  sphere() {}
  sphere(point3 c, double r);

  virtual bool hit(const ray& r,
                   double t_min, double t_max, hit_record& rec) const override;

private:
  point3 center;
  double radius;
};

#endif /* SPHERE_H */

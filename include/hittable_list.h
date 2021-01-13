#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "hittable.h"

class hittable_list : public hittable
{
public:
  hittable_list() {}
  hittable_list(std::shared_ptr<hittable> object);

  void clear();
  void add(std::shared_ptr<hittable> object);

  virtual bool hit(const ray& r,
                   double t_min, double t_max, hit_record& rec) const override;

private:
  std::vector<std::shared_ptr<hittable>> objects;
};

#endif /* HITTABLE_LIST_H */

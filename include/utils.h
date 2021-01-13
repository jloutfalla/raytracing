#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <cstdlib>
#include <limits>

const double infinity = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

#define RAD(X) (X * pi / 180.0)

inline double randomd()
{
  return rand() / (RAND_MAX + 1.0);
}

inline double randomd(double min, double max)
{
  return min + (max - min) * randomd();
}

inline double clamp(double x, double min, double max)
{
  if (x < min) return min;
  if (x > max) return max;
  
  return x;
}

#endif /* UTILS_H */

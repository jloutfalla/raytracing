#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include "utils.h"

class vec3
{
public:
  vec3() : e{0, 0, 0} {}
  vec3(double x, double y, double z);

  double x() const;
  double y() const;
  double z() const;

  double length() const;
  double length2() const;
  
  friend double dot(const vec3& lhs, const vec3& rhs);
  friend vec3 cross(const vec3& lhs, const vec3& rhs);
  vec3 normalize(const vec3& v);
  
  inline static vec3 random()
  {
    return vec3(randomd(), randomd(), randomd());
  }

  inline static vec3 random(double min, double max)
  {
    return vec3(randomd(min, max), randomd(min, max), randomd(min, max));
  }

  vec3 operator-() const;
  double operator[](int i) const;
  double& operator[](int i);

  vec3& operator+=(const vec3& rhs);
  vec3& operator*=(const double l);
  vec3& operator/=(const double l);

  friend std::ostream& operator<<(std::ostream& os, const vec3& v);
  friend vec3 operator+(const vec3& lhs, const vec3& rhs);
  friend vec3 operator-(const vec3& lhs, const vec3& rhs);
  friend vec3 operator*(const vec3& lhs, const vec3& rhs);
  friend vec3 operator*(double l, const vec3& v);
  friend vec3 operator*(const vec3& v, double l);
  friend vec3 operator/(const vec3& v, double l);
  
private:
  double e[3];
};

typedef vec3 point3;
typedef vec3 color;

double dot(const vec3& lhs, const vec3& rhs);
vec3 cross(const vec3& lhs, const vec3& rhs);
vec3 normalize(const vec3& v);

vec3 random_unit_vector();
vec3 random_in_unit_sphere();
vec3 random_in_hemisphere(const vec3& normal);

std::ostream& operator<<(std::ostream& os, const vec3& v);
vec3 operator+(const vec3& lhs, const vec3& rhs);
vec3 operator-(const vec3& lhs, const vec3& rhs);
vec3 operator*(const vec3& lhs, const vec3& rhs);
vec3 operator*(double l, const vec3& v);
vec3 operator*(const vec3& v, double l);
vec3 operator/(const vec3& v, double l);

/**************************************************************/
/*                     Inline definitions                     */
/**************************************************************/
inline double dot(const vec3& lhs, const vec3& rhs)
{
  return (lhs.e[0] * rhs.e[0] +
          lhs.e[1] * rhs.e[1] +
          lhs.e[2] * rhs.e[2]);
}

inline vec3 cross(const vec3& lhs, const vec3& rhs)
{
  return vec3(lhs.e[1] * rhs.e[2] - lhs.e[2] * rhs.e[1],
              lhs.e[2] * rhs.e[0] - lhs.e[0] * rhs.e[2],
              lhs.e[0] * rhs.e[1] - lhs.e[1] * rhs.e[0]);
}

inline vec3 normalize(const vec3& v)
{
  return v / v.length();
}

inline vec3 random_in_unit_sphere()
{
  while (true)
    {
      vec3 p = vec3::random(-1, 1);
      if (p.length2() >= 1) continue;
      return p;
    }
}

inline vec3 random_unit_vector()
{
  return normalize(random_in_unit_sphere());
}

inline vec3 random_in_hemisphere(const vec3& normal)
{
  vec3 in_unit_sphere = random_in_unit_sphere();
  
  if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
    return in_unit_sphere;
  else
    return -in_unit_sphere;
}

inline std::ostream& operator<<(std::ostream& os, const vec3& v)
{
  return os << "(" << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ")";
}

inline vec3 operator+(const vec3& lhs, const vec3& rhs)
{
  return vec3(lhs.e[0] + rhs.e[0], lhs.e[1] + rhs.e[1], lhs.e[2] + rhs.e[2]);
}

inline vec3 operator-(const vec3& lhs, const vec3& rhs)
{
  return vec3(lhs.e[0] - rhs.e[0], lhs.e[1] - rhs.e[1], lhs.e[2] - rhs.e[2]);
}

inline vec3 operator*(const vec3& lhs, const vec3& rhs)
{
  return vec3(lhs.e[0] * rhs.e[0], lhs.e[1] * rhs.e[1], lhs.e[2] * rhs.e[2]);
}

inline vec3 operator*(double l, const vec3& v)
{
  return vec3(l * v.e[0], l * v.e[1], l * v.e[2]);
}

inline vec3 operator*(const vec3& v, double l)
{
  return l * v;
}

inline vec3 operator/(const vec3& v, double l)
{
  return (1.0 / l) * v;
}

#endif /* VEC3_H */

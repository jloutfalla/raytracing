#include "vec3.h"

#include <cmath>
#include <cassert>

vec3::vec3(double x, double y, double z) : e{x, y, z} {}

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }

double vec3::operator[](int i) const
{
  assert(i < 3 && i >= 0);
  return e[i];
}

double& vec3::operator[](int i)
{
  assert(i < 3 && i >= 0);
  return e[i];
}

vec3& vec3::operator+=(const vec3& rhs)
{
  e[0] += rhs[0];
  e[1] += rhs[1];
  e[2] += rhs[2];

  return *this;
}

vec3& vec3::operator*=(const double l)
{
  e[0] *= l;
  e[1] *= l;
  e[2] *= l;

  return *this;
}

vec3& vec3::operator/=(const double l)
{
  return *this *= 1.0 / l;
}

double vec3::length() const
{
  return sqrt(length2());
}

double vec3::length2() const
{
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
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

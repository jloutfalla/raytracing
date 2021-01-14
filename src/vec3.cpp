#include "vec3.h"

#include <cmath>
#include <cassert>

vec3::vec3(double x, double y, double z) : e{x, y, z} {}

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

double vec3::length() const
{
  return sqrt(length2());
}

double vec3::length2() const
{
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

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

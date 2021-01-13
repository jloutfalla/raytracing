#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class vec3
{
public:
  vec3() : e{0, 0, 0} {}
  vec3(double x, double y, double z);

  double x() const;
  double y() const;
  double z() const;

  vec3 operator-() const;
  double operator[](int i) const;
  double& operator[](int i);

  vec3& operator+=(const vec3& rhs);
  vec3& operator*=(const double l);
  vec3& operator/=(const double l);

  double length() const;
  double length2() const;

  friend std::ostream& operator<<(std::ostream& os, const vec3& v);
  friend vec3 operator+(const vec3& lhs, const vec3& rhs);
  friend vec3 operator-(const vec3& lhs, const vec3& rhs);
  friend vec3 operator*(const vec3& lhs, const vec3& rhs);
  friend vec3 operator*(double l, const vec3& v);
  friend vec3 operator*(const vec3& v, double l);
  friend vec3 operator/(const vec3& v, double l);
  
  friend double dot(const vec3& lhs, const vec3& rhs);
  friend vec3 cross(const vec3& lhs, const vec3& rhs);
  vec3 normalize(const vec3& v);
  
private:
  double e[3];
};

typedef vec3 point3;
typedef vec3 color;

#endif /* VEC3_H */

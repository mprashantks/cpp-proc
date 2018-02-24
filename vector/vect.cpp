// vect.cpp -- methods for the Vector class
#include <cmath>
#include "vect.h"
using std::sqrt;
using std::cout;

namespace VECTOR {
  // public methods
  // construct vector from rectangular coordinates
  Vector::Vector(double n1, double n2, double n3) {
    x = n1;
    y = n2;
    z = n3;
  }

  // reset vector
  void Vector:: reset(double n1, double n2, double n3) {
    x = n1;
    y = n2;
    z = n3;
  }

  // get magnitude of Vector
  double Vector::magnitude() const {
    return sqrt(x * x + y * y + z * z);
  }

  // dot product
  double Vector::dotProduct(const Vector & b) const {
    return x * b.x + y * b.y + z * b.z;
  }

  // operator overloading
  // add two Vectors
  Vector Vector::operator+(const Vector & b) const {
    return Vector(x + b.x, y + b.y, z + b.z);
  }

  // subtract Vector b from a
  Vector Vector::operator-(const Vector & b) const {
    return Vector(x - b.x, y - b.y, z - b.z);
  }

  // negate Vector
  Vector Vector::operator-() const {
    return Vector(-x, -y, -z);
  }

  // multiply vector by n
  Vector Vector::operator*(double n) const {
    return Vector(n * x, n * y, n * z);
  }

  // cross product of two vectors
  Vector Vector::operator*(const Vector & b) const {
    double n1 = (y * b.z - z * b.y);
    double n2 = (x * b.z - z * b.x);
    double n3 = (x * b.y - y * b.x);
    return Vector(n1, n2, n3);
  }

  // friend methods
  // multiply n by Vector a
  Vector operator*(double n, const Vector & a) {
    return a * n;
  }

  // display rectangular coordinates
  std::ostream & operator<<(std::ostream & os, const Vector & v) {
      os << "(x,y,z) = (" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
  }
}
// end namespace VECTOR

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <cmath>
using std::sqrt;

namespace VECTOR {
  class Vector {
    private:
      double x;               // x dimension
      double y;               // y dimension
      double z;               // z dimension

    public:
      Vector(double n1=0.0, double n2=0.0, double n3=0.0);
      void reset(double n1, double n2, double n3);
      ~Vector();

      double magnitude() const;                             // report magnitude
      double dotProduct(const Vector & b) const;

      // operator overloading
      Vector operator+(const Vector & b) const;
      Vector operator-(const Vector & b) const;
      Vector operator-() const;
      Vector operator*(double n) const;
      Vector operator*(const Vector & b) const;

      // friends
      friend Vector operator*(double n, const Vector & a);
      friend std::ostream & operator<<(std::ostream & os, const Vector & v);
  };
}
// end namespace VECTOR
#endif

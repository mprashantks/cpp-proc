#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

// Create custom namespace for better management in case of large project
namespace VECTOR {
  class Vector {
    private:
      double x;                                                                 // x dimension
      double y;                                                                 // y dimension
      double z;                                                                 // z dimension

    public:
      Vector(double n1=0.0, double n2=0.0, double n3=0.0);                      // Constructor to assign values, default to 0
      void reset(double n1, double n2, double n3);                              // Reset function

      double magnitude() const;                                                 // Get magnitude of vector
      double dotProduct(const Vector & b) const;                                // Get dot product of two vectors
                                                                                // . operator cannot be overloaded
                                                                                // so function is defined

      // operator overloading
      Vector operator+(const Vector & b) const;                                 // Add two vectors and return computed vector object
      Vector operator-(const Vector & b) const;                                 // Subtract two vectors and return computed vector object
      Vector operator-() const;                                                 // Negate vector and return computed vector
      Vector operator*(double n) const;                                         // Vector and constant multiplication
      Vector operator*(const Vector & b) const;                                 // Cross product of two vectors

      // friends
      friend Vector operator*(double n, const Vector & a);                      // Vector and constant multiplication
                                                                                // Developed to enforce commutative property
                                                                                // of vector and constant multiplication
      friend std::ostream & operator<<(std::ostream & os, const Vector & v);    // Overload << to display
                                                                                // Vector object
  };
}
// end namespace VECTOR
#endif

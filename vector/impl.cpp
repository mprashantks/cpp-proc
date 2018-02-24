// Compile with vect.cpp file

#include <iostream>
#include "vect.h"

int main() {
  using namespace std;
  using VECTOR::Vector;

  Vector a(3, -5, 4);
  Vector b(2, 6, 5);
  Vector c(1, 1, 1);

  cout << "a - " << a << endl;                                          // Print vector
  a.reset(1, 0, -2);                                                    // Reset vector to another value
  cout << "Reset a - "  << a << endl;                                   // Negate vector
  cout << "Negate a - " << -a << endl;                                  // Vector magnitude
  cout << "a - " << a << " | Magnitude: " << a.magnitude() << endl;
  cout << "b - " << b << " | Magnitude: " << b.magnitude() << endl;
  cout << "c - " << c << " | Magnitude: " << c.magnitude() << endl;
  cout << "(a + b) - " << a + b << endl;                                // Vector addition
  cout << "(a + b + c) - " << a + b + c << endl;                        // Vector addition
  cout << "(a - b) - " << a - b << endl;                                // Vector subtraction
  cout << "(a * 3) - " << a * 3 << endl;                                // Vector and constant multiplication
  cout << "(2 * a) - " << 2 * a << endl;
  cout << "(a . b) - " << a.dotProduct(b) << endl;                      // Dot product
  cout << "(a * b) - " << a * b << endl;                                // Cross product

  return 0;
}

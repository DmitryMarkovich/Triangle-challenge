/// Copyright 2017 Dmitriy Markovich @ dmmrkovich@gmail.com

// file: triangle.cc

// purpose: source file for header file triangle.h

#include "triangle.h"
#include <math.h>
#include <iostream>
#include <string>

// sets the object with parameters a, b, c
void Triangle::set(double a, double b, double c) {
  this -> a = a;
  this -> b = b;
  this -> c = c;
  set_side_lengths_are_valid();
  set_is_triangle();
}  // End of void Triangle::initialize(double a, double b, double c)

// sets if side lengths are valid (positive, non-zero, non-nan, non-inf)
void Triangle::set_side_lengths_are_valid() {
  if (!isnan(a) && !isinf(a) && a > 0.0 &&
      !isnan(b) && !isinf(b) && b > 0.0 &&
      !isnan(c) && !isinf(c) && c > 0.0) {
    // lengths are valid doubles
    side_lengths_are_valid = true;
  } else {
    // lengths are not valid doubles
    side_lengths_are_valid = false;
    // if lengths are not valid they can not form a valid triangle
    is_triangle = false;
  }
}  // End of void Triangle::set_side_lengths_are_valid()

// sets if valid lengths form a triangle that satisfies the triangle inequality
// (each side is less than the sum of the other two)
void Triangle::set_is_triangle() {
  if (side_lengths_are_valid) {
    // side lengths are valid, so check if they can form a triangle
    if (a + b > c && a + c > b && b + c > a) {
      // the triangle inequality is ok, so the legnths do form a triangle
      is_triangle = true;
    } else {
      // and they do not if otherwise
      is_triangle = false;
    }
  }
}  // End of void Triangle::set_is_triangle()

// determines the type of the triangle
std::string Triangle::determine_type() const {
  if (side_lengths_are_valid) {
    if (is_triangle) {
      if (a == b || a == c || b == c) {
        if (a == b && a == c && b == c) {
          // equilateral triangle, all sides are equal
          return "equilateral";
        } else {
          // isosceles triangle, two sides are equal
          return "isosceles";
        }  // End of if (a == b && a == c && b == c) else
      } else {
        // scalene triangle, all sides of different lengths
        return "scalene";
      }  // End of if (a == b || a == c || b == c) else
    } else {
      // valid sides lengths but they can not form a triangle
      return "N/A (lengths can not form a triangle)";
    }  // End of if (is_triangle) else
  } else {
    // sides lengths are not valid
    return "N/A (lengths are not valid)";
  }  // End of if (side_lengths_are_valid) else
}  // End of std::string Triangle::determine_type()

// prints the object
void Triangle::print() const {
  std::cout << ">> Object of class Triangle at " << this << ":\n   a = " << a
            << ", b = " << b << ", c = " << c <<
    "\n   side_lengths_are_valid = " << side_lengths_are_valid <<
    ", is_triangle = " << is_triangle << "\n";
}  // End of void Triangle::print()

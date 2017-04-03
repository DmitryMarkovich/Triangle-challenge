/// Copyright 2017 Dmitriy Markovich @ dmmrkovich@gmail.com

// file: triangle.h

// purpose: header file for class Triangle to store triangle objects

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <math.h>
#include <iostream>
#include <string>

class Triangle {
 private:
  // the lengths of three sides of the triangle
  double a, b, c;
  // boolean variables showing 1) whether side lengths of the triangle are valid
  // (positive, non-zero, non-nan, non-inf) 2) whether the given lengths form a
  // triangle that satisfies the triangle inequality
  bool side_lengths_are_valid, is_triangle;

 public:
  // default constructor
  Triangle() {}
  // default destructor
  ~Triangle() {}
  // sets the object with parameters a, b, c
  void set(double a, double b, double c);
  // sets if side lengths are valid (positive and non-zero, finite and non-NaN)
  void set_side_lengths_are_valid();
  // sets if valid lengths form a triangle that satisfies the triangle
  // inequality (each side is less than the sum of the other two)
  void set_is_triangle();
  // determines the type of the triangle
  std::string determine_type() const;
  // prints the object
  void print() const;
};
#endif  // _TRIANGLE_H_

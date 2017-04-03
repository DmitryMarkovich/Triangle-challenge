/// Copyright 2017 Dmitriy Markovich @ dmmrkovich@gmail.com

// Triangle challenge: given the lengths of the three sides of a triangle,
// determine whether it is equilateral (all three sides are equal), isosceles
// (two sides are equal) or scalene (all sides of different lenghts).

// file: main.cc

// purpose: get the name of the file with triangle data as argv[1] and process
// it using the function ProcessTriangleFile()

#include <iostream>
#include "triangle.h"  // definition of class Triangle to store triangle objects
#include "helper_functions.h"  // helper functions to load data file

int main(int argc, char** argv) {
  if (argv[0] != nullptr) {
    // get the absolute path where the main.cc is located
    std::string main_path = GetExecPath(std::string(argv[0]));
    if (argv[1] != nullptr) {
      // pass the file with triangles data to process as valid argv[1]
      ProcessTriangleFile(main_path, argv[1]);
    } else {
      // error: file to process was not given as argv[1]
      std::cerr << ">> File to process not found in argv[1]!\n";
      exit(1);
    }
  } else {
    // error: program name was not given as argv[0]
    std::cerr << ">> Program name not found in argv[0]!\n";
    exit(1);
  }
  return 0;
}  // End of int main(int argc, char** argv)

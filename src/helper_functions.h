/// Copyright 2017 Dmitriy Markovich @ dmmrkovich@gmail.com

// file: helper_functions.h

// purpose: header file for helper functions to load and process a triangle data
// file

#ifndef _SRC_HELPER_FUNCTIONS_H_
#define _SRC_HELPER_FUNCTIONS_H_
#include "triangle.h"
#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// gets the directory where main.cc is located
std::string GetExecPath(std::string program_name);
// prints the line from a triangle data file, the extracted triangle lengths,
// and the type of the extracted triangle
void PrintTriangleAndResultForLine(std::string line, std::string triangle,
                                   std::string result);
// nice conversion from double to string for pretty output
std::string DoubleToString(double x);
// loads a triangle data file from /data and processes it line-by-line
void ProcessTriangleFile(std::string main_path, std::string fname);
#endif  // _SRC_HELPER_FUNCTIONS_H_

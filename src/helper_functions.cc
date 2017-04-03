/// Copyright 2017 Dmitriy Markovich @ dmmrkovich@gmail.com

// file: helper_functions.cc

// purpose: source file for helper_functions.h

#include "helper_functions.h"
#include <iostream>
#include <string>

// gets the directory where main.cc is located
std::string GetExecPath(std::string program_name) {
  if (!program_name.empty()) {
    char tmp[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", tmp, PATH_MAX);
    std::string path = std::string(tmp, (count > 0) ? count : 0);
    if (!path.empty()) {
      // return the asolute path to main.cc
      return path.substr(0, path.length() - (program_name.length() - 2));
    } else {
      // signal error because path was empty
      std::cerr << ">> path is empty!\n";
      exit(1);
    }  // End of if (!path.empty()) else
  } else {
    // signal error because program_name was empty
    std::cerr << ">> Program name is empty!\n";
    exit(1);
  }  // End of if (!program_name.empty()) else
}  // End of std::string GetExecPath(std::string program_name)

// prints the line from a triangle data file, the extracted triangle lengths,
// and the type of the extracted triangle
void PrintTriangleAndResultForLine(std::string line, std::string triangle,
                                   std::string result) {
  std::cout << "Line: " << line << " | Extr trgl: " << triangle <<
    " | Result: " << result << "\n";
}  // End of void PrintTriangleAndResultForLine()

std::string DoubleToString(double x) {
  std::string str = std::to_string(x);
  str.erase(str.find_last_not_of('0') + 1, std::string::npos);
  return str;
}  // End of std::string DoubleToString(double x)

// loads a triangle data file from /data and processes it line-by-line
void ProcessTriangleFile(std::string main_path, std::string fname) {
  if (main_path.empty()) {
    std::cerr << ">> main_path is empty!\n";
    exit(1);
  } else if (fname.empty()) {
    std::cerr << ">> fname is empty!\n";
    exit(1);
  } else {
    std::string full_fname = main_path + "data/" + fname;
    std::ifstream input(full_fname);
    if (!input) {
      std::cerr << ">> Could not open file data/" << fname << "!" << std::endl;
      exit(1);
    } else {
      // file successfully opened, create a triangle object to hold a triangle
      // extracted from each line of the data file
      Triangle t; std::string line;
      // declare three sides a b c and two separators comma1 comma2 between them
      double a, b, c; char comma1, comma2;
      // read file line-by-line
      while (std::getline(input, line)) {
        std::istringstream iss(line);
        // attempt to split out three comma-separated doubles in the line
        if (!((iss >> a >> comma1 >> b >> comma2 >> c) &&
              (comma1 == ',' && comma2 == ','))) {
          // print N/A for triangle type because the split failed
          PrintTriangleAndResultForLine(line,"", "N/A (failed to split input)");
        } else {
          // initialize or reset the triangle object with successfully split
          // doubles
          t.set(a, b, c);
          // print triangle type for the triangle extracted from the line
          PrintTriangleAndResultForLine(line,
                                        std::string(
                                                    DoubleToString(a) + " " +
                                                    DoubleToString(b) + " " +
                                                    DoubleToString(c)),
                                        t.determine_type());
        }  // End of if (!(iss )) else
      }  // End of while (std::getline(input, line))
    }  // End of if (!input)
  }  // End of if (main_path.empty())
}  // End of void ProcessTriangleFile()

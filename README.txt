Author:
Dmitriy Markovich @ dmmrkovich@gmail.com

Triangle challenge:
given the lengths of the three sides of a triangle,
determine whether it is equilateral (all three sides are equal), isosceles
(two sides are equal) or scalene (all sides of different lenghts).

Design and Motivation:
A class Triangle is the abstraction for a real-world object triangle.

class Triangle {
 private:
  // the lengths of three sides of the triangle
  double a, b, c;
  // boolean variables showing 1) whether side lengths of the triangle are valid
  // (positive, non-zero, non-nan, non-inf) 2) whether the given lengths form a
  // triangle that satisfies the triangle inequality
  bool side_lengths_are_valid, is_triangle;
 ...
};

A const member function of the class Triangle::determine_type() determines the 
type of the triangle.

Compilation and usage:
 1) Make sure g++ is installed on Your system. If not, try $ sudo apt-get install g++.
 2) Make sure compile-and-run.sh is executable. If not, make it
  executable by running $ chmod +x compile-and-run.sh.
 3) Run the script $ ./compile-and-run.sh.  It will use the default
  file /data/test-scenarios.txt as the source of different test cases of
  triangle side lengths input. File will be displayed line-by-line together with
  the extracted triangle and its type determined by the program.  After the
  execution, the binary will be removed.
 4) Alternatively, create Your own triangle data file in the data
  folder (for example /data/new-test.txt), and run the script as 
  $ ./compile-and-run.sh new-test.txt to process it instead of the default one.

Further details:
Please have a look at README.pdf

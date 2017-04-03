#!/bin/bash
# specify the non-default name of the triangle data file for the program
data=$1;
# get path to include project header files and source files
path="$(pwd)/src";
# set compiler
CC="g++";
# set compiler flags
CCFLAGS="-ansi -pedantic-errors -Wall -std=c++14";
# compile to binary main.cc.bin
$CC $CCFLAGS main.cc src/triangle.cc src/helper_functions.cc -I$path -o main.cc.bin
# default data file with test scenarios
default_data="test-scenarios.txt";
# run binary if compiled
if [[ -f main.cc.bin ]]; then
    if [[ -z "$data" ]]; then
        echo ">>>> Running main.cc.bin with default data file for test scenarios.";
        ./main.cc.bin $default_data;
    else
        echo ">>>> Running main.cc.bin with $data data file for test scenarios.";
        ./main.cc.bin $data;
    fi
    # remove binary
    rm ./main.cc.bin;
else
    echo ">>>> Failed to compile!";
fi

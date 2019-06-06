#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd $DIR
cd test
cmake CMakeLists.txt
make
./runTests

rm -r CMakeCache.txt CMakeFiles/ Makefile cmake_install.cmake runTests

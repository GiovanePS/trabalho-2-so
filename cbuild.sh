#!/bin/bash
mkdir -p build
cd build
cmake --build . --config Debug --target all --
./main

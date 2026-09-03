#!/bin/bash

# Build with Cmake and Ninja
cmake -S . -B build -G Ninja
cmake --build build
# Test with CTest
ctest --test-dir build --output-on-failure
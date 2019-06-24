#!/bin/bash

c++ src/{proportion,statistics}.cpp tests/proportion.cpp -o test_proportion
c++ src/{mean,statistics}.cpp tests/mean.cpp -o test_mean
c++ src/{variance,statistics}.cpp tests/variance.cpp -o test_variance

echo "Running proportion tests..."
./test_proportion

echo "Running mean tests..."
./test_mean

echo "Running variance tests..."
./test_variance

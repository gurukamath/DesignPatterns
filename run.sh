#! /bin/zsh

cmake -S . -B build -DPRINCIPLE=$1

cmake --build build

echo "\nRunning the code...\n"
./build/design_principles
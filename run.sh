#! /bin/zsh

if [ $# -eq "1" ]
then
    cmake -S . -B build -DPRINCIPLE=$1 -DCMAKE_BUILD_TYPE=Debug
else
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
fi

if [ $? -eq 0 ]
then
    cmake --build build
fi

if [ $? -eq 0 ]
then
    echo "\nRunning the code...\n"
    ./build/design_principles
fi
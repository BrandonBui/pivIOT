#!/bin/bash
echo Compiling...
g++ main.cpp -o main
echo Finished compiling, runnning program...this may take a minute to see output
./main $1 > output.txt
echo Done! Results are in output.txt
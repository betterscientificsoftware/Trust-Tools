#!/bin/sh
# File pulls March Madness simulator form GitHub and executes with three different values for homefeild advantage (0,2,4). Resutls of each run is saved in output files.
echo "Executing madness.sh"

mkdir madness
cd ./madness
yes| apt-get install cmake 
git init
git pull  http://github.com/wbonsu/MarchMaddness.git
cmake . 
make
./March_Madness_Simulator 0 > output_no_advantage.txt
./March_Madness_Simulator 2 > output_2_advantage.txt
./March_Madness_Simulator 4 > output_4_advantage.txt



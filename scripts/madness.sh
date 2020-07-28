#!/bin/sh
# File pulls March Madness simulator form GitHub and executes with three different values for homefeild advantage (0,2,4). Resutls of each run is saved in output files.
echo "Executing madness.sh"
yes| apt-get install cmake 
mkdir madness
cd ./madness
git init
git pull https://github.com/phesse001/MarchMadness.git
mkdir build
mkdir lib
cp -arv /home/patrick/Trust-Tools/googletest /home/patrick/Trust-Tools/scripts/madness/lib
cd build
cmake ..
make
./src/march-madness_run 0 1 > output_no_advantage.txt
./src/march-madness_run 2 1 > output_2_advantage.txt
./src/march-madness_run 4 1 > output_4_advantage.txt
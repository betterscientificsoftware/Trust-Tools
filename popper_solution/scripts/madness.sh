#!/bin/sh
# File pulls March Madness simulator form GitHub and executes with three different values for homefeild advantage (0,2,4). Resutls of each run is saved in output files.
echo "Executing madness.sh"
#installs and sets up gtest
apt-get install libgtest-dev
yes| apt-get install cmake 
#link of where I left off https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
mkdir madness
cd ./madness
git init
git pull https://github.com/phesse001/March_Madness.git
mkdir build
mkdir lib
mv /googletest /workspace/madness/lib
cd build
cmake ..
make
./src/march-madness_run 0 1 > output_no_advantage.txt
./src/march-madness_run 2 1 > output_2_advantage.txt
./src/march-madness_run 4 1 > output_4_advantage.txt



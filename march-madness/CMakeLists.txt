cmake_minimum_required(VERSION 3.7)
project(March_Madness_Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(March_Madness_Simulator Simulator.cpp Team.cpp Team.h Game.h Simulator.h Game.cpp)

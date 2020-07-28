cmake_minimum_required(VERSION 3.7)
project(march-madness)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(../include/eigen ../include)

add_executable(${BINARY}_run Simulator.cpp Game.cpp Team.cpp main.cpp)

add_library(${BINARY}_lib STATIC Simulator.cpp Game.cpp Team.cpp)

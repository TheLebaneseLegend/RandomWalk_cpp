cmake_minimum_required(VERSION 4.0)
project(RandomWalk)

set(CMAKE_CXX_STANDARD 20)
set(SDL2_PATH /opt/homebrew)

include_directories(${SDL2_PATH}/include/SDL2)
link_directories(${SDL2_PATH}/lib)

file(GLOB_RECURSE SOURCES
        main.cpp
)

add_executable(RandomWalk ${SOURCES})

target_link_libraries(RandomWalk SDL2)

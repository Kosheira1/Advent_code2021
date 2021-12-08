cmake_minimum_required(VERSION 3.17)
project(Advent_Day1)

set(CMAKE_CXX_STANDARD 14)
#include_directories(${Boost_INCLUDE_DIR})

set(INCLUDE_BOOST "/home/dleonard/Documents/installs/Boost/include")
include_directories(${INCLUDE_BOOST})

set(LIBDIR_BOOST "/home/dleonard/Documents/installs/Boost/lib")
link_directories(${LIBDIR_BOOST})


add_executable(Advent_Day1 main.cpp)

target_link_libraries (Advent_Day1 ${LIBNAME_BOOST})
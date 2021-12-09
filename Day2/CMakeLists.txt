cmake_minimum_required(VERSION 3.17)
project(Day2)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_BOOST "/home/dleonard/Documents/installs/Boost/include")
include_directories(${INCLUDE_BOOST})

set(LIBDIR_BOOST "/home/dleonard/Documents/installs/Boost/lib")
link_directories(${LIBDIR_BOOST})

add_executable(Day2 main.cpp)
target_link_libraries (Day2 ${LIBNAME_BOOST})

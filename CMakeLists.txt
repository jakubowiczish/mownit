cmake_minimum_required(VERSION 3.13)
project(mownit C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(mownit "laboratory01/main.c" laboratory02/main.c laboratory03/main.c)

find_package(GSL REQUIRED)
target_link_libraries(mownit GSL::gsl GSL::gslcblas)
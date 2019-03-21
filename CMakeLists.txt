cmake_minimum_required(VERSION 3.13)
project(mownit C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(mownit "laboratory1/main.c" laboratory2/main.c laboratory3/main.c)

find_package(GSL REQUIRED)
target_link_libraries(mownit GSL::gsl GSL::gslcblas)
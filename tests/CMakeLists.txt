cmake_minimum_required(VERSION 3.15)
project(fastText)

set(CMAKE_CXX_STANDARD 14)

include_directories(../src)

file(GLOB src_all ../src/*.cc)

list(FILTER src_all EXCLUDE REGEX ".*main.cc$")

add_executable(fastTextTest load_test.cpp ${src_all})

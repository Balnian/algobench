cmake_minimum_required(VERSION 3.20)

project(algobench)

add_executable(bench src/main.cpp)
target_include_directories(bench PUBLIC include)
cmake_minimum_required(VERSION 3.24)
project(current_time)

set(CMAKE_CXX_STANDARD 11)

add_executable(current_time
    include/current_time.h  
    src/current_time.cpp      
    test/main.cpp
)
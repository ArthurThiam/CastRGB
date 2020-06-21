cmake_minimum_required(VERSION 3.15)
project(CastRGB)

set(CMAKE_CXX_STANDARD 14)

add_executable(CastRGB main.cpp Pixel.hpp Capture.hpp)
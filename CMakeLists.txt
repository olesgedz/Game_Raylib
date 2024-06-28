cmake_minimum_required(VERSION 3.22)

project(GameRayLib)

set(CMAKE_CXX_STANDARD 23)
find_package(raylib 3.0 REQUIRED)

add_subdirectory(src)
add_subdirectory(example)
cmake_minimum_required(VERSION 3.22)
set(Target Example02)

project(${Target})

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE source_files "src/*.cpp")
file(GLOB_RECURSE header_files "src/*.hpp")

# App
add_executable(${Target} ${source_files} ${header_files})
target_link_libraries(${Target} PRIVATE raylib)
#target_include_directories(${Target}
#        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/
#)

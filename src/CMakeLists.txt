set(Target CPP_Project_Template)

project(${Target})

file(GLOB_RECURSE source_files "*.cpp")
file(GLOB_RECURSE header_files "*.hpp")

add_executable(${Target} main.cpp)
cmake_minimum_required(VERSION 3.27)

file(GLOB sources_list LIST_DIRECTORIES true "example*")
foreach(dir ${sources_list})
    IF(IS_DIRECTORY ${dir})
        add_subdirectory(${dir})
    ELSE()
        CONTINUE()
    ENDIF()
endforeach()

message(STATUS "sources_list: ${sources_list}")
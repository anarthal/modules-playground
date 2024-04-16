cmake_minimum_required(VERSION 3.28..3.29)
project(consumer CXX)

find_package(asio REQUIRED)
find_package(mylib REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE asio mylib)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()
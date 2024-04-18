cmake_minimum_required(VERSION 3.28..3.29)
project(consumer CXX)

find_package(asio REQUIRED)
find_package(mylib REQUIRED)
find_package(charconv REQUIRED)

set_property(TARGET asio APPEND PROPERTY IMPORTED_CXX_MODULES_COMPILE_DEFINITIONS ASIO_USE_TS_EXECUTOR_AS_DEFAULT)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE asio mylib charconv)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()

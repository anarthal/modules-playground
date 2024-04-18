cmake_minimum_required(VERSION 3.28..3.29)
project(provider CXX)

add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(stdlib)
add_subdirectory(asio-module)
add_subdirectory(mylib)
add_subdirectory(charconv)

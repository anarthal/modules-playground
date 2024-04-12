cmake_minimum_required(VERSION 3.28..3.29)
project(provider CXX)

add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)

add_subdirectory(stdlib)
add_subdirectory(asio-module)

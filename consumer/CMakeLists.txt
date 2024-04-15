cmake_minimum_required(VERSION 3.28..3.29)
project(consumer CXX)

find_package(asio REQUIRED)
find_package(mylib REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE asio mylib)
target_compile_options(main PRIVATE -stdlib=libc++)
target_link_options(main PRIVATE -stdlib=libc++)
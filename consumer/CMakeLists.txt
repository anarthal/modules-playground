cmake_minimum_required(VERSION 3.28..3.29)
project(consumer CXX)

set(CMAKE_PREFIX_PATH /home/ruben/workspace/playgound-installed)
find_package(asio REQUIRED)
set_target_properties(asio PROPERTIES COMPILE_DEFINITIONS ASIO_USE_TS_EXECUTOR_AS_DEFAULT=1)
set_target_properties(asio PROPERTIES INTERFACE_COMPILE_DEFINITIONS ASIO_USE_TS_EXECUTOR_AS_DEFAULT=1)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE asio)
target_compile_options(main PRIVATE -stdlib=libc++)
target_link_options(main PRIVATE -stdlib=libc++)
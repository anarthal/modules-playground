cmake_minimum_required(VERSION 3.28.0)

file(
    GLOB_RECURSE STDLIB_HEADERS 
    CONFIGURE_DEPENDS
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    std/*
)

add_library(stdlib)
target_include_directories(stdlib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:.>
)
target_compile_features(stdlib PUBLIC cxx_std_23)
target_sources(stdlib
    PUBLIC
        FILE_SET CXX_MODULES FILES std.cppm
        FILE_SET HEADERS FILES ${STDLIB_HEADERS}
)

install(TARGETS stdlib
    EXPORT stdlib-targets
    FILE_SET CXX_MODULES
        DESTINATION lib/cmake/stdlib/module
    FILE_SET HEADERS DESTINATION .
)
install(EXPORT stdlib-targets
    DESTINATION lib/cmake/stdlib
    CXX_MODULES_DIRECTORY .
)
install(
    FILES stdlibConfig.cmake
    DESTINATION lib/cmake/stdlib
)

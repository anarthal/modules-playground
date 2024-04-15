
cmake_minimum_required(VERSION 3.28.0)

find_package(OpenSSL REQUIRED)

file(
    GLOB_RECURSE MYLIB_HEADERS 
    CONFIGURE_DEPENDS
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    include/*
)

add_library(mylib src/mylib.cpp)
target_include_directories(mylib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(mylib PUBLIC cxx_std_23)
target_sources(mylib
    PUBLIC
        FILE_SET CXX_MODULES FILES module/mylib.cxx
        FILE_SET HEADERS FILES ${MYLIB_HEADERS}
)
target_link_libraries(mylib PUBLIC stdlib)

install(TARGETS mylib
    EXPORT mylib-targets
    FILE_SET CXX_MODULES
        DESTINATION lib/cmake/mylib
    FILE_SET HEADERS DESTINATION .
)
install(EXPORT mylib-targets
    DESTINATION lib/cmake/mylib
    CXX_MODULES_DIRECTORY .
)
install(
    FILES mylibConfig.cmake
    DESTINATION lib/cmake/mylib
)

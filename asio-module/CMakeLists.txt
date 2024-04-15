cmake_minimum_required(VERSION 3.28.0)

find_package(OpenSSL REQUIRED)

file(
    GLOB_RECURSE ASIO_HEADERS 
    CONFIGURE_DEPENDS
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    include/*
)

add_library(asio)
target_include_directories(asio PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(asio PUBLIC cxx_std_23)
target_sources(asio
    PUBLIC
        FILE_SET CXX_MODULES FILES module/asio.cxx
        FILE_SET HEADERS FILES ${ASIO_HEADERS}
)
target_link_libraries(asio PUBLIC OpenSSL::SSL OpenSSL::Crypto stdlib)

install(TARGETS asio
    EXPORT asio-targets
    FILE_SET CXX_MODULES
        DESTINATION lib/cmake/asio
    FILE_SET HEADERS DESTINATION .
)
install(EXPORT asio-targets
    DESTINATION lib/cmake/asio
    CXX_MODULES_DIRECTORY .
)
install(
    FILES asioConfig.cmake
    DESTINATION lib/cmake/asio
)

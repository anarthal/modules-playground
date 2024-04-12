include(CMakeFindDependencyMacro)

find_dependency(stdlib)
find_dependency(OpenSSL)

include("${CMAKE_CURRENT_LIST_DIR}/asio-targets.cmake")
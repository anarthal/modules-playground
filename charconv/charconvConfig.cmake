include(CMakeFindDependencyMacro)

find_dependency(stdlib)
find_dependency(Boost COMPONENTS headers charconv)

include("${CMAKE_CURRENT_LIST_DIR}/charconv-targets.cmake")
target_link_libraries(charconv INTERFACE Boost::charconv)
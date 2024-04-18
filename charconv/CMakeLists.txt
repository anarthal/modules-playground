
find_package(Boost REQUIRED COMPONENTS headers)

file(
    GLOB_RECURSE CHARCONV_HEADERS 
    CONFIGURE_DEPENDS
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    include/*
)

add_library(charconv)
target_include_directories(charconv PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(charconv PUBLIC cxx_std_23)
target_compile_options(charconv PUBLIC -Wno-include-angled-in-module-purview)
target_sources(charconv
    PUBLIC
        FILE_SET CXX_MODULES FILES module/charconv.cxx
        FILE_SET HEADERS FILES ${CHARCONV_HEADERS}
)
target_link_libraries(charconv PUBLIC stdlib Boost::headers)

install(TARGETS charconv
    EXPORT charconv-targets
    FILE_SET CXX_MODULES
        DESTINATION lib/cmake/charconv
    FILE_SET HEADERS DESTINATION .
)
install(EXPORT charconv-targets
    DESTINATION lib/cmake/charconv
    CXX_MODULES_DIRECTORY .
)
install(
    FILES charconvConfig.cmake
    DESTINATION lib/cmake/charconv
)

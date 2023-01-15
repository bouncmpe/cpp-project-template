cmake_minimum_required(VERSION 3.20)

project("LIBBOUNCMPE" CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bouncmpe)
find_package(Boost 1.81 COMPONENTS json REQUIRED)

target_include_directories(
  bouncmpe
  PUBLIC 
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>/include
)
target_sources(
  bouncmpe
  PRIVATE 
    "src/jsonmerge.cpp"
)
target_link_libraries(
  bouncmpe
  PUBLIC 
    Boost::json
)

if (ENABLE_TESTS)
    add_subdirectory(tests)
    enable_testing()
endif()

if (BOUNCMPE_BUILD_APPS)
    add_subdirectory(apps)
endif()


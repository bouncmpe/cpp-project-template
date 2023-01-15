find_package(Catch2 REQUIRED)
include(Catch)
include(CTest)


add_executable(
  bouncmpe_tests 
    jsonmerge.test.cpp
)

target_link_libraries(
  bouncmpe_tests
    PRIVATE  
      bouncmpe
      Catch2::Catch2WithMain
)

catch_discover_tests(bouncmpe_tests)
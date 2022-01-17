cmake_minimum_required(VERSION 3.0.0)
project(median-calculator VERSION 0.1.0)

# require C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

include_directories(include)

# efficient median library
add_library(median src/MedianCalculator.cpp)

# example app
add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE median)

# testing binary
add_executable(unit-test test/test.cpp src/TestMedianCalculator.cpp)
target_link_libraries(unit-test PRIVATE median)

# define tests
add_test(
  NAME unit-test
  COMMAND $<TARGET_FILE:unit-test>
  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

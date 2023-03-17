cmake_minimum_required(VERSION 3.1)
project(test_func)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Python3 COMPONENTS Interpreter Development)

include_directories(
  ${Python3_INCLUDE_DIRS}
)

add_executable(main main.cpp)
target_link_libraries(main ${Python3_LIBRARIES})
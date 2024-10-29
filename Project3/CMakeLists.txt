cmake_minimum_required(VERSION 3.10)
project(a.out)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SOURCES src/*.cpp src/*.tpp)

add_executable(${PROJECT_NAME} ${SOURCES})

cmake_minimum_required(VERSION 3.5.1)

project(sandbox)

set(EXEC main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

add_library(cxxopts INTERFACE)

target_include_directories(cxxopts INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

target_link_libraries(${EXEC} cxxopts yaml-cpp)

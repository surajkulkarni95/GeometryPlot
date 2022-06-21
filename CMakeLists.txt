cmake_minimum_required(VERSION 3.1)

project(GeometryPlot)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(src/core src/writer)

add_executable(sketcher src/sketcher/main.cpp)

add_library(writer SHARED src/writer/ParametricWriter.cpp src/writer/TextWriter.cpp)

add_library(core SHARED src/core/Point.cpp src/core/Line.cpp src/core/Circle.cpp src/core/Polygon.cpp)

target_link_libraries(core writer)
target_link_libraries(sketcher core)

cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 14)

project(GeometryPlot)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" ON)

include_directories(src/core src/writer src/poly2tri src/matrix src/)

add_compile_definitions(P2T_SHARED_EXPORTS)

add_executable(sketcher src/sketcher/main.cpp)

add_library(writer SHARED src/writer/ParametricWriter.cpp src/writer/TextWriter.cpp src/writer/PrintPoint.cpp "src/writer/STLWriter.cpp")

add_library(core SHARED src/core/Point.cpp src/core/Line.cpp src/core/Circle.cpp src/core/Polygon.cpp src/core/SimpleShape.cpp "src/core/Triangle.cpp" src/core/ClosedShape.cpp src/core/Triangulation.cpp "src/core/Spline.cpp" "src/core/splineInternal.cpp")

add_library(poly2tri SHARED src/poly2tri/common/shapes.cc src/poly2tri/sweep/advancing_front.cc src/poly2tri/sweep/cdt.cc src/poly2tri/sweep/sweep.cc src/poly2tri/sweep/sweep_context.cc)

target_link_libraries(core poly2tri)
target_link_libraries(core writer)
target_link_libraries(sketcher core)
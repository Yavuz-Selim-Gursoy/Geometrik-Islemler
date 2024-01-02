cmake_minimum_required(VERSION 3.27)
project(ProgramlamaLab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProgramlamaLab1
        geometry.cpp
        TestCode.cpp
        Dot.h
        LineSegment.h
        Circle.h
        Triangle.h)

cmake_minimum_required(VERSION 3.12)
project(Bezier)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/python@3.7/3.7.8_1/Frameworks/Python.framework/Versions/3.7/include/python3.7m)
link_directories(/usr/local/Cellar/python@3.7/3.7.8_1/Frameworks/Python.framework/Versions/3.7/lib)

add_executable(Bezier curves.cpp Vector2.cpp Vector2.h BezierApproximator.cpp BezierApproximator.h)
target_link_libraries(Bezier Python)
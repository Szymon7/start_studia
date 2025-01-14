cmake_minimum_required(VERSION 3.29)
project(Projects)

set(CMAKE_CXX_STANDARD 26)

add_executable(Projects main.cpp
        Simple/Calculator.cpp
        Simple/Calculator.h
        Simple/Conversion.cpp
        Simple/Conversion.h
        Simple/Game.h
        Simple/Game.cpp
        Simple/Meteorologist.cpp
        Simple/Meteorologist.h
        Simple/Interest.cpp
        Simple/Interest.h
        Simple/FigureFields.cpp
        Simple/FigureFields.h
        Simple/QuadraticFunction.cpp
        Simple/QuadraticFunction.h
        Simple/Balance.cpp
        Simple/Balance.h)

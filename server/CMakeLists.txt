cmake_minimum_required(VERSION 3.23)
project(ex4_AP)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex4_AP main.cpp VectorCreation.cpp VectorCreation.h MasterDistance.cpp
        MasterDistance.h Minkowski.cpp Minkowski.h Euclidean.cpp Euclidean.h Manhattan.cpp Manhattan.h
        Canberra.cpp Canberra.h Chebyshev.cpp Chebyshev.h CsvReading.cpp CsvReading.h VectorBase.cpp VectorBase.h)

cmake_minimum_required(VERSION 3.15)
project(Monstres)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Monstres
        jeu.cpp
        jeu.hpp
        monstre.cpp
        monstre.hpp
        tableau.hpp
        tests.cpp)

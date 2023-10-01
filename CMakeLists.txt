cmake_minimum_required(VERSION 3.0.0)
project(labwork1-Vyacheslav_Atamanyuk VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(labwork1-Vyacheslav_Atamanyuk
        main.cpp
        comand_parser.h
        comand_parser.cpp
        file_parser.cpp
        file_parser.h)

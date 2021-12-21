cmake_minimum_required(VERSION 3.16)
project(Ex3)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER /usr/bin/g++ )


add_executable(Ex3
        parser.tab.cpp
        source.cpp
        SymbolsRepo.cpp
        Type.cpp
        hw3_output.cpp
        )
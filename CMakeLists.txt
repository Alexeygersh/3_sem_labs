cmake_minimum_required(VERSION 3.26)
project(3_sem_labs)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(3_sem_labs
        GTS.cpp
        GTS.h
        Lab2_GershAM.cpp
        pipe.cpp
        pipe.h
        station.cpp
        station.h
        utils.h
        1.txt)

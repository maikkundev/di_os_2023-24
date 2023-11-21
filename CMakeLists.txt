cmake_minimum_required(VERSION 3.26)
project(di_os_2023_24)

set(CMAKE_CXX_STANDARD 14)

add_executable(di_os_2023_24
        erg2/main.c)

set_target_properties(di_os_2023_24 PROPERTIES OUTPUT_NAME "mycp")
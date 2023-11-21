cmake_minimum_required(VERSION 3.10)
project(di_os_2023_24)

set(CMAKE_CXX_STANDARD 14)

add_executable(di_os_2023_24
        erg2/main.c
        erg2/mycp.c
        erg2/mycp.h)

set_target_properties(di_os_2023_24 PROPERTIES OUTPUT_NAME "mycp"
                        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/erg2)
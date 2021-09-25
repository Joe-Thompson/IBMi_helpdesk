cmake_minimum_required(VERSION 3.17)
project(IBMi_helpdesk C)

set(CMAKE_C_STANDARD 11)

add_executable(IBMi_helpdesk
        ibmihelp.c strcmp.h arraydb.h)

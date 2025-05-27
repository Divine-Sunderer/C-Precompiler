cmake_minimum_required(VERSION 3.15)
project(CMakePrecompiler C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Precompiler
        CheckDirettive.c
        DeleteComments.c
        VarChecker.c
        checkFileSize.c
)

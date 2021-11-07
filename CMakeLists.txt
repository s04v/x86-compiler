cmake_minimum_required(VERSION 3.10)

project(compiler)
set (CMAKE_CXX_FLAGS "-g")
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_C_COMPILER g++)

add_executable(compiler main.cpp frontend/lex.yy.c frontend/parser.tab.c ) 

cmake_minimum_required(VERSION 3.10)

project(compiler)
set (CMAKE_CXX_FLAGS " -g -Wno-all -Wextra -Wno-write-strings -Wreturn-type")
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_C_COMPILER g++)


add_executable(compiler main.cpp
                        frontend/lex.yy.c
                        frontend/parser.tab.c
                        backend/Emitter.cpp
                        backend/Reg.cpp
                        backend/Compiler.cpp
                        backend/TypeSystem.cpp
                        backend/scope/SymbolTable.cpp
                        backend/scope/FunctionTable.cpp
                        backend/scope/Scope.cpp
                        )

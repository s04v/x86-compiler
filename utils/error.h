#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

using namespace std;
inline void funcMainNotFound()
{
    printf("function \033[1;37m'main'\033[0m not found");
    exit(1);
}

inline void invalidConversionFrom(int line, string t1, string t2)
{
    printf("line %d: invalid conversion from '%s' to '%s'", line, t1, t2);
    exit(1);
}

inline void incorretType(int line)
{
    printf("line %d: incorrect type in expr", line);
    exit(1);
}

inline void symbolNotDefined(int line, string name)
{
    printf("line: %d: \033[1;31merror\033[0m: \033[1;37m'%s'\033[0m was not declared in this scope.\n", line, name.c_str());
    exit(1);
}

inline void tooFewArguments(int line, string name)
{
    printf("line %d: \033[1;31merror\033[0m: too few arguments to function \033[1;37m'%s'\033[0m\n", line, name.c_str());
    exit(1);
}

inline void tooManyArguments(int line, string name)
{
    printf("line %d: \033[1;31merror\033[0m: too many arguments to function \033[1;37m'%s'\033[0m\n", line, name.c_str());
    exit(1);
}

inline void invalidArgType(int line, string type)
{
    printf("line %d: invalid argument type, expect \033[1;37m'%s'\033[0m\n", line, type.c_str());
    exit(1);
}

inline void invalidConversion(int line, string from, string to)
{
    printf("line %d: invalid conversion from \033[1;37m'%s'\033[0m to \033[1;37m'%s'\033[0m", line, from.c_str(), to.c_str());
    exit(1);
}

inline void varAlreadyDeclared(int line, string name)
{
    printf("line %d: variable \033[1;37m'%s'\033[0m already declared\n", line, name.c_str());
    exit(1);
}

inline void funcAlreadyDeclared(int line, string name)
{
    printf("line %d: function \033[1;37m'%s'\033[0m already declared\n", line, name.c_str());
    exit(1);
}


inline void errorReport(char* text, ...)
{

    string s = "[ \033[1;37merror\033[0m ]";
    cout << s;

    printf(text);
    //s += text;

//    cout << s;

    va_list va;
    va_start (va, text);
    //printf (s.c_str(), va);
    va_end (va);

    //cout << "[" <<"\033[1;31mERROR\033[0m" << "] " << text << endl;
    exit(1);
}



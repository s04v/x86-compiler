# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Desktop/x86-compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Desktop/x86-compiler

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/user/Desktop/x86-compiler/CMakeFiles /home/user/Desktop/x86-compiler/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/user/Desktop/x86-compiler/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named compiler

# Build rule for target.
compiler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 compiler
.PHONY : compiler

# fast build rule for target.
compiler/fast:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/build
.PHONY : compiler/fast

ast/constant.o: ast/constant.cpp.o

.PHONY : ast/constant.o

# target to build an object file
ast/constant.cpp.o:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/ast/constant.cpp.o
.PHONY : ast/constant.cpp.o

ast/constant.i: ast/constant.cpp.i

.PHONY : ast/constant.i

# target to preprocess a source file
ast/constant.cpp.i:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/ast/constant.cpp.i
.PHONY : ast/constant.cpp.i

ast/constant.s: ast/constant.cpp.s

.PHONY : ast/constant.s

# target to generate assembly for a file
ast/constant.cpp.s:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/ast/constant.cpp.s
.PHONY : ast/constant.cpp.s

frontend/lex.yy.o: frontend/lex.yy.c.o

.PHONY : frontend/lex.yy.o

# target to build an object file
frontend/lex.yy.c.o:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/lex.yy.c.o
.PHONY : frontend/lex.yy.c.o

frontend/lex.yy.i: frontend/lex.yy.c.i

.PHONY : frontend/lex.yy.i

# target to preprocess a source file
frontend/lex.yy.c.i:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/lex.yy.c.i
.PHONY : frontend/lex.yy.c.i

frontend/lex.yy.s: frontend/lex.yy.c.s

.PHONY : frontend/lex.yy.s

# target to generate assembly for a file
frontend/lex.yy.c.s:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/lex.yy.c.s
.PHONY : frontend/lex.yy.c.s

frontend/parser.tab.o: frontend/parser.tab.c.o

.PHONY : frontend/parser.tab.o

# target to build an object file
frontend/parser.tab.c.o:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/parser.tab.c.o
.PHONY : frontend/parser.tab.c.o

frontend/parser.tab.i: frontend/parser.tab.c.i

.PHONY : frontend/parser.tab.i

# target to preprocess a source file
frontend/parser.tab.c.i:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/parser.tab.c.i
.PHONY : frontend/parser.tab.c.i

frontend/parser.tab.s: frontend/parser.tab.c.s

.PHONY : frontend/parser.tab.s

# target to generate assembly for a file
frontend/parser.tab.c.s:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/frontend/parser.tab.c.s
.PHONY : frontend/parser.tab.c.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/compiler.dir/build.make CMakeFiles/compiler.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... compiler"
	@echo "... ast/constant.o"
	@echo "... ast/constant.i"
	@echo "... ast/constant.s"
	@echo "... frontend/lex.yy.o"
	@echo "... frontend/lex.yy.i"
	@echo "... frontend/lex.yy.s"
	@echo "... frontend/parser.tab.o"
	@echo "... frontend/parser.tab.i"
	@echo "... frontend/parser.tab.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


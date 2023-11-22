# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrk/DevLinux/di_os_2023-24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrk/DevLinux/di_os_2023-24

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mrk/DevLinux/di_os_2023-24/CMakeFiles /home/mrk/DevLinux/di_os_2023-24//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mrk/DevLinux/di_os_2023-24/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named di_os_2023_24

# Build rule for target.
di_os_2023_24: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 di_os_2023_24
.PHONY : di_os_2023_24

# fast build rule for target.
di_os_2023_24/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/build
.PHONY : di_os_2023_24/fast

erg2/main.o: erg2/main.c.o
.PHONY : erg2/main.o

# target to build an object file
erg2/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/main.c.o
.PHONY : erg2/main.c.o

erg2/main.i: erg2/main.c.i
.PHONY : erg2/main.i

# target to preprocess a source file
erg2/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/main.c.i
.PHONY : erg2/main.c.i

erg2/main.s: erg2/main.c.s
.PHONY : erg2/main.s

# target to generate assembly for a file
erg2/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/main.c.s
.PHONY : erg2/main.c.s

erg2/mycp.o: erg2/mycp.c.o
.PHONY : erg2/mycp.o

# target to build an object file
erg2/mycp.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/mycp.c.o
.PHONY : erg2/mycp.c.o

erg2/mycp.i: erg2/mycp.c.i
.PHONY : erg2/mycp.i

# target to preprocess a source file
erg2/mycp.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/mycp.c.i
.PHONY : erg2/mycp.c.i

erg2/mycp.s: erg2/mycp.c.s
.PHONY : erg2/mycp.s

# target to generate assembly for a file
erg2/mycp.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/di_os_2023_24.dir/build.make CMakeFiles/di_os_2023_24.dir/erg2/mycp.c.s
.PHONY : erg2/mycp.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... di_os_2023_24"
	@echo "... erg2/main.o"
	@echo "... erg2/main.i"
	@echo "... erg2/main.s"
	@echo "... erg2/mycp.o"
	@echo "... erg2/mycp.i"
	@echo "... erg2/mycp.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


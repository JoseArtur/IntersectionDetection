# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /opt/cmake-3.28.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.28.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/ctw02488/Documents/Tests/Nitro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ctw02488/Documents/Tests/Nitro/cmake-build-debug

# Utility rule file for Experimental.

# Include any custom commands dependencies for this target.
include CMakeFiles/Experimental.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Experimental.dir/progress.make

CMakeFiles/Experimental:
	/opt/cmake-3.28.1-linux-x86_64/bin/ctest -D Experimental

Experimental: CMakeFiles/Experimental
Experimental: CMakeFiles/Experimental.dir/build.make
.PHONY : Experimental

# Rule to build all files generated by this target.
CMakeFiles/Experimental.dir/build: Experimental
.PHONY : CMakeFiles/Experimental.dir/build

CMakeFiles/Experimental.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Experimental.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Experimental.dir/clean

CMakeFiles/Experimental.dir/depend:
	cd /mnt/c/Users/ctw02488/Documents/Tests/Nitro/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ctw02488/Documents/Tests/Nitro /mnt/c/Users/ctw02488/Documents/Tests/Nitro /mnt/c/Users/ctw02488/Documents/Tests/Nitro/cmake-build-debug /mnt/c/Users/ctw02488/Documents/Tests/Nitro/cmake-build-debug /mnt/c/Users/ctw02488/Documents/Tests/Nitro/cmake-build-debug/CMakeFiles/Experimental.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Experimental.dir/depend


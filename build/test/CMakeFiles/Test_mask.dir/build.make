# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/lyc/workspace/mask_lyc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyc/workspace/mask_lyc/build

# Include any dependencies generated for this target.
include test/CMakeFiles/Test_mask.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Test_mask.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Test_mask.dir/flags.make

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o: test/CMakeFiles/Test_mask.dir/flags.make
test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o: ../test/mask_lyc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/workspace/mask_lyc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o"
	cd /home/lyc/workspace/mask_lyc/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test_mask.dir/mask_lyc.cpp.o -c /home/lyc/workspace/mask_lyc/test/mask_lyc.cpp

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_mask.dir/mask_lyc.cpp.i"
	cd /home/lyc/workspace/mask_lyc/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/workspace/mask_lyc/test/mask_lyc.cpp > CMakeFiles/Test_mask.dir/mask_lyc.cpp.i

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_mask.dir/mask_lyc.cpp.s"
	cd /home/lyc/workspace/mask_lyc/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/workspace/mask_lyc/test/mask_lyc.cpp -o CMakeFiles/Test_mask.dir/mask_lyc.cpp.s

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.requires:

.PHONY : test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.requires

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.provides: test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test_mask.dir/build.make test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.provides

test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.provides.build: test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o


# Object files for target Test_mask
Test_mask_OBJECTS = \
"CMakeFiles/Test_mask.dir/mask_lyc.cpp.o"

# External object files for target Test_mask
Test_mask_EXTERNAL_OBJECTS =

test/Test_mask: test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o
test/Test_mask: test/CMakeFiles/Test_mask.dir/build.make
test/Test_mask: test/CMakeFiles/Test_mask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyc/workspace/mask_lyc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test_mask"
	cd /home/lyc/workspace/mask_lyc/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_mask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Test_mask.dir/build: test/Test_mask

.PHONY : test/CMakeFiles/Test_mask.dir/build

test/CMakeFiles/Test_mask.dir/requires: test/CMakeFiles/Test_mask.dir/mask_lyc.cpp.o.requires

.PHONY : test/CMakeFiles/Test_mask.dir/requires

test/CMakeFiles/Test_mask.dir/clean:
	cd /home/lyc/workspace/mask_lyc/build/test && $(CMAKE_COMMAND) -P CMakeFiles/Test_mask.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Test_mask.dir/clean

test/CMakeFiles/Test_mask.dir/depend:
	cd /home/lyc/workspace/mask_lyc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyc/workspace/mask_lyc /home/lyc/workspace/mask_lyc/test /home/lyc/workspace/mask_lyc/build /home/lyc/workspace/mask_lyc/build/test /home/lyc/workspace/mask_lyc/build/test/CMakeFiles/Test_mask.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Test_mask.dir/depend


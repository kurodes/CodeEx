# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kuro/Desktop/codeEX/cmake/exProject/t3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/hello_static.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/hello_static.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/hello_static.dir/flags.make

lib/CMakeFiles/hello_static.dir/hello.o: lib/CMakeFiles/hello_static.dir/flags.make
lib/CMakeFiles/hello_static.dir/hello.o: ../lib/hello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/hello_static.dir/hello.o"
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello_static.dir/hello.o   -c /Users/kuro/Desktop/codeEX/cmake/exProject/t3/lib/hello.c

lib/CMakeFiles/hello_static.dir/hello.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello_static.dir/hello.i"
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kuro/Desktop/codeEX/cmake/exProject/t3/lib/hello.c > CMakeFiles/hello_static.dir/hello.i

lib/CMakeFiles/hello_static.dir/hello.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello_static.dir/hello.s"
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kuro/Desktop/codeEX/cmake/exProject/t3/lib/hello.c -o CMakeFiles/hello_static.dir/hello.s

# Object files for target hello_static
hello_static_OBJECTS = \
"CMakeFiles/hello_static.dir/hello.o"

# External object files for target hello_static
hello_static_EXTERNAL_OBJECTS =

lib/libhello.a: lib/CMakeFiles/hello_static.dir/hello.o
lib/libhello.a: lib/CMakeFiles/hello_static.dir/build.make
lib/libhello.a: lib/CMakeFiles/hello_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libhello.a"
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/hello_static.dir/cmake_clean_target.cmake
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/hello_static.dir/build: lib/libhello.a

.PHONY : lib/CMakeFiles/hello_static.dir/build

lib/CMakeFiles/hello_static.dir/clean:
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/hello_static.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/hello_static.dir/clean

lib/CMakeFiles/hello_static.dir/depend:
	cd /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kuro/Desktop/codeEX/cmake/exProject/t3 /Users/kuro/Desktop/codeEX/cmake/exProject/t3/lib /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib /Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib/CMakeFiles/hello_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/hello_static.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Code\DS\Wet1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Code\DS\Wet1\build

# Include any dependencies generated for this target.
include CMakeFiles/sorted_lists.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sorted_lists.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sorted_lists.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sorted_lists.dir/flags.make

CMakeFiles/sorted_lists.dir/main.cpp.obj: CMakeFiles/sorted_lists.dir/flags.make
CMakeFiles/sorted_lists.dir/main.cpp.obj: ../main.cpp
CMakeFiles/sorted_lists.dir/main.cpp.obj: CMakeFiles/sorted_lists.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Code\DS\Wet1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sorted_lists.dir/main.cpp.obj"
	C:\PROGRA~1\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sorted_lists.dir/main.cpp.obj -MF CMakeFiles\sorted_lists.dir\main.cpp.obj.d -o CMakeFiles\sorted_lists.dir\main.cpp.obj -c C:\Code\DS\Wet1\main.cpp

CMakeFiles/sorted_lists.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorted_lists.dir/main.cpp.i"
	C:\PROGRA~1\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Code\DS\Wet1\main.cpp > CMakeFiles\sorted_lists.dir\main.cpp.i

CMakeFiles/sorted_lists.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorted_lists.dir/main.cpp.s"
	C:\PROGRA~1\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Code\DS\Wet1\main.cpp -o CMakeFiles\sorted_lists.dir\main.cpp.s

# Object files for target sorted_lists
sorted_lists_OBJECTS = \
"CMakeFiles/sorted_lists.dir/main.cpp.obj"

# External object files for target sorted_lists
sorted_lists_EXTERNAL_OBJECTS =

sorted_lists.exe: CMakeFiles/sorted_lists.dir/main.cpp.obj
sorted_lists.exe: CMakeFiles/sorted_lists.dir/build.make
sorted_lists.exe: CMakeFiles/sorted_lists.dir/linklibs.rsp
sorted_lists.exe: CMakeFiles/sorted_lists.dir/objects1.rsp
sorted_lists.exe: CMakeFiles/sorted_lists.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Code\DS\Wet1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sorted_lists.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sorted_lists.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sorted_lists.dir/build: sorted_lists.exe
.PHONY : CMakeFiles/sorted_lists.dir/build

CMakeFiles/sorted_lists.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sorted_lists.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sorted_lists.dir/clean

CMakeFiles/sorted_lists.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Code\DS\Wet1 C:\Code\DS\Wet1 C:\Code\DS\Wet1\build C:\Code\DS\Wet1\build C:\Code\DS\Wet1\build\CMakeFiles\sorted_lists.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sorted_lists.dir/depend


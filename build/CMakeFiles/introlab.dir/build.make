# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anton/Документы/OOP/chumak_lab_0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/Документы/OOP/chumak_lab_0/build

# Include any dependencies generated for this target.
include CMakeFiles/introlab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/introlab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/introlab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/introlab.dir/flags.make

CMakeFiles/introlab.dir/main.cpp.o: CMakeFiles/introlab.dir/flags.make
CMakeFiles/introlab.dir/main.cpp.o: /home/anton/Документы/OOP/chumak_lab_0/main.cpp
CMakeFiles/introlab.dir/main.cpp.o: CMakeFiles/introlab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/Документы/OOP/chumak_lab_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/introlab.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/introlab.dir/main.cpp.o -MF CMakeFiles/introlab.dir/main.cpp.o.d -o CMakeFiles/introlab.dir/main.cpp.o -c /home/anton/Документы/OOP/chumak_lab_0/main.cpp

CMakeFiles/introlab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/introlab.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Документы/OOP/chumak_lab_0/main.cpp > CMakeFiles/introlab.dir/main.cpp.i

CMakeFiles/introlab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/introlab.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Документы/OOP/chumak_lab_0/main.cpp -o CMakeFiles/introlab.dir/main.cpp.s

# Object files for target introlab
introlab_OBJECTS = \
"CMakeFiles/introlab.dir/main.cpp.o"

# External object files for target introlab
introlab_EXTERNAL_OBJECTS =

introlab: CMakeFiles/introlab.dir/main.cpp.o
introlab: CMakeFiles/introlab.dir/build.make
introlab: CMakeFiles/introlab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/Документы/OOP/chumak_lab_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable introlab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/introlab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/introlab.dir/build: introlab
.PHONY : CMakeFiles/introlab.dir/build

CMakeFiles/introlab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/introlab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/introlab.dir/clean

CMakeFiles/introlab.dir/depend:
	cd /home/anton/Документы/OOP/chumak_lab_0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Документы/OOP/chumak_lab_0 /home/anton/Документы/OOP/chumak_lab_0 /home/anton/Документы/OOP/chumak_lab_0/build /home/anton/Документы/OOP/chumak_lab_0/build /home/anton/Документы/OOP/chumak_lab_0/build/CMakeFiles/introlab.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/introlab.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/c/code/unb-sc-proj2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/code/unb-sc-proj2/build

# Include any dependencies generated for this target.
include CMakeFiles/aes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aes.dir/flags.make

CMakeFiles/aes.dir/aes.cpp.o: CMakeFiles/aes.dir/flags.make
CMakeFiles/aes.dir/aes.cpp.o: ../aes.cpp
CMakeFiles/aes.dir/aes.cpp.o: CMakeFiles/aes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/code/unb-sc-proj2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aes.dir/aes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aes.dir/aes.cpp.o -MF CMakeFiles/aes.dir/aes.cpp.o.d -o CMakeFiles/aes.dir/aes.cpp.o -c /mnt/c/code/unb-sc-proj2/aes.cpp

CMakeFiles/aes.dir/aes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aes.dir/aes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/code/unb-sc-proj2/aes.cpp > CMakeFiles/aes.dir/aes.cpp.i

CMakeFiles/aes.dir/aes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aes.dir/aes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/code/unb-sc-proj2/aes.cpp -o CMakeFiles/aes.dir/aes.cpp.s

CMakeFiles/aes.dir/main.cpp.o: CMakeFiles/aes.dir/flags.make
CMakeFiles/aes.dir/main.cpp.o: ../main.cpp
CMakeFiles/aes.dir/main.cpp.o: CMakeFiles/aes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/code/unb-sc-proj2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aes.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aes.dir/main.cpp.o -MF CMakeFiles/aes.dir/main.cpp.o.d -o CMakeFiles/aes.dir/main.cpp.o -c /mnt/c/code/unb-sc-proj2/main.cpp

CMakeFiles/aes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/code/unb-sc-proj2/main.cpp > CMakeFiles/aes.dir/main.cpp.i

CMakeFiles/aes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/code/unb-sc-proj2/main.cpp -o CMakeFiles/aes.dir/main.cpp.s

# Object files for target aes
aes_OBJECTS = \
"CMakeFiles/aes.dir/aes.cpp.o" \
"CMakeFiles/aes.dir/main.cpp.o"

# External object files for target aes
aes_EXTERNAL_OBJECTS =

aes: CMakeFiles/aes.dir/aes.cpp.o
aes: CMakeFiles/aes.dir/main.cpp.o
aes: CMakeFiles/aes.dir/build.make
aes: CMakeFiles/aes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/code/unb-sc-proj2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable aes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aes.dir/build: aes
.PHONY : CMakeFiles/aes.dir/build

CMakeFiles/aes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aes.dir/clean

CMakeFiles/aes.dir/depend:
	cd /mnt/c/code/unb-sc-proj2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/code/unb-sc-proj2 /mnt/c/code/unb-sc-proj2 /mnt/c/code/unb-sc-proj2/build /mnt/c/code/unb-sc-proj2/build /mnt/c/code/unb-sc-proj2/build/CMakeFiles/aes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aes.dir/depend


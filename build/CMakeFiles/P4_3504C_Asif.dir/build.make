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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/asif/CLionProjects/P4-3504C-Asif

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/asif/CLionProjects/P4-3504C-Asif/build

# Include any dependencies generated for this target.
include CMakeFiles/P4_3504C_Asif.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/P4_3504C_Asif.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/P4_3504C_Asif.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P4_3504C_Asif.dir/flags.make

CMakeFiles/P4_3504C_Asif.dir/main.cpp.o: CMakeFiles/P4_3504C_Asif.dir/flags.make
CMakeFiles/P4_3504C_Asif.dir/main.cpp.o: ../main.cpp
CMakeFiles/P4_3504C_Asif.dir/main.cpp.o: CMakeFiles/P4_3504C_Asif.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P4_3504C_Asif.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P4_3504C_Asif.dir/main.cpp.o -MF CMakeFiles/P4_3504C_Asif.dir/main.cpp.o.d -o CMakeFiles/P4_3504C_Asif.dir/main.cpp.o -c /Users/asif/CLionProjects/P4-3504C-Asif/main.cpp

CMakeFiles/P4_3504C_Asif.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4_3504C_Asif.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asif/CLionProjects/P4-3504C-Asif/main.cpp > CMakeFiles/P4_3504C_Asif.dir/main.cpp.i

CMakeFiles/P4_3504C_Asif.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4_3504C_Asif.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asif/CLionProjects/P4-3504C-Asif/main.cpp -o CMakeFiles/P4_3504C_Asif.dir/main.cpp.s

CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o: CMakeFiles/P4_3504C_Asif.dir/flags.make
CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o: ../GameState.cpp
CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o: CMakeFiles/P4_3504C_Asif.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o -MF CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o.d -o CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o -c /Users/asif/CLionProjects/P4-3504C-Asif/GameState.cpp

CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asif/CLionProjects/P4-3504C-Asif/GameState.cpp > CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.i

CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asif/CLionProjects/P4-3504C-Asif/GameState.cpp -o CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.s

CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o: CMakeFiles/P4_3504C_Asif.dir/flags.make
CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o: ../Toolbox.cpp
CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o: CMakeFiles/P4_3504C_Asif.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o -MF CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o.d -o CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o -c /Users/asif/CLionProjects/P4-3504C-Asif/Toolbox.cpp

CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asif/CLionProjects/P4-3504C-Asif/Toolbox.cpp > CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.i

CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asif/CLionProjects/P4-3504C-Asif/Toolbox.cpp -o CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.s

CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o: CMakeFiles/P4_3504C_Asif.dir/flags.make
CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o: ../Button.cpp
CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o: CMakeFiles/P4_3504C_Asif.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o -MF CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o.d -o CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o -c /Users/asif/CLionProjects/P4-3504C-Asif/Button.cpp

CMakeFiles/P4_3504C_Asif.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4_3504C_Asif.dir/Button.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asif/CLionProjects/P4-3504C-Asif/Button.cpp > CMakeFiles/P4_3504C_Asif.dir/Button.cpp.i

CMakeFiles/P4_3504C_Asif.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4_3504C_Asif.dir/Button.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asif/CLionProjects/P4-3504C-Asif/Button.cpp -o CMakeFiles/P4_3504C_Asif.dir/Button.cpp.s

CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o: CMakeFiles/P4_3504C_Asif.dir/flags.make
CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o: ../Tile.cpp
CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o: CMakeFiles/P4_3504C_Asif.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o -MF CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o.d -o CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o -c /Users/asif/CLionProjects/P4-3504C-Asif/Tile.cpp

CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asif/CLionProjects/P4-3504C-Asif/Tile.cpp > CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.i

CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asif/CLionProjects/P4-3504C-Asif/Tile.cpp -o CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.s

# Object files for target P4_3504C_Asif
P4_3504C_Asif_OBJECTS = \
"CMakeFiles/P4_3504C_Asif.dir/main.cpp.o" \
"CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o" \
"CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o" \
"CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o" \
"CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o"

# External object files for target P4_3504C_Asif
P4_3504C_Asif_EXTERNAL_OBJECTS =

P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/main.cpp.o
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/GameState.cpp.o
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/Toolbox.cpp.o
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/Button.cpp.o
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/Tile.cpp.o
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/build.make
P4_3504C_Asif: /opt/homebrew/lib/libsfml-graphics.2.5.1.dylib
P4_3504C_Asif: /opt/homebrew/lib/libsfml-window.2.5.1.dylib
P4_3504C_Asif: /opt/homebrew/lib/libsfml-system.2.5.1.dylib
P4_3504C_Asif: CMakeFiles/P4_3504C_Asif.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable P4_3504C_Asif"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P4_3504C_Asif.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P4_3504C_Asif.dir/build: P4_3504C_Asif
.PHONY : CMakeFiles/P4_3504C_Asif.dir/build

CMakeFiles/P4_3504C_Asif.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P4_3504C_Asif.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P4_3504C_Asif.dir/clean

CMakeFiles/P4_3504C_Asif.dir/depend:
	cd /Users/asif/CLionProjects/P4-3504C-Asif/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/asif/CLionProjects/P4-3504C-Asif /Users/asif/CLionProjects/P4-3504C-Asif /Users/asif/CLionProjects/P4-3504C-Asif/build /Users/asif/CLionProjects/P4-3504C-Asif/build /Users/asif/CLionProjects/P4-3504C-Asif/build/CMakeFiles/P4_3504C_Asif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P4_3504C_Asif.dir/depend


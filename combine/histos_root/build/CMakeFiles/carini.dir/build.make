# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/nyykki/Scrivania/histos_root

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nyykki/Scrivania/histos_root/build

# Include any dependencies generated for this target.
include CMakeFiles/carini.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/carini.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/carini.dir/flags.make

CMakeFiles/carini.dir/src/carini.cpp.o: CMakeFiles/carini.dir/flags.make
CMakeFiles/carini.dir/src/carini.cpp.o: ../src/carini.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/carini.dir/src/carini.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/carini.dir/src/carini.cpp.o -c /home/nyykki/Scrivania/histos_root/src/carini.cpp

CMakeFiles/carini.dir/src/carini.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carini.dir/src/carini.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nyykki/Scrivania/histos_root/src/carini.cpp > CMakeFiles/carini.dir/src/carini.cpp.i

CMakeFiles/carini.dir/src/carini.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carini.dir/src/carini.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nyykki/Scrivania/histos_root/src/carini.cpp -o CMakeFiles/carini.dir/src/carini.cpp.s

# Object files for target carini
carini_OBJECTS = \
"CMakeFiles/carini.dir/src/carini.cpp.o"

# External object files for target carini
carini_EXTERNAL_OBJECTS =

carini: CMakeFiles/carini.dir/src/carini.cpp.o
carini: CMakeFiles/carini.dir/build.make
carini: /home/nyykki/root/lib/libCore.so
carini: /home/nyykki/root/lib/libImt.so
carini: /home/nyykki/root/lib/libRIO.so
carini: /home/nyykki/root/lib/libNet.so
carini: /home/nyykki/root/lib/libHist.so
carini: /home/nyykki/root/lib/libGraf.so
carini: /home/nyykki/root/lib/libGraf3d.so
carini: /home/nyykki/root/lib/libGpad.so
carini: /home/nyykki/root/lib/libROOTDataFrame.so
carini: /home/nyykki/root/lib/libTree.so
carini: /home/nyykki/root/lib/libTreePlayer.so
carini: /home/nyykki/root/lib/libRint.so
carini: /home/nyykki/root/lib/libPostscript.so
carini: /home/nyykki/root/lib/libMatrix.so
carini: /home/nyykki/root/lib/libPhysics.so
carini: /home/nyykki/root/lib/libMathCore.so
carini: /home/nyykki/root/lib/libThread.so
carini: /home/nyykki/root/lib/libMultiProc.so
carini: CMakeFiles/carini.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable carini"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/carini.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/carini.dir/build: carini

.PHONY : CMakeFiles/carini.dir/build

CMakeFiles/carini.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/carini.dir/cmake_clean.cmake
.PHONY : CMakeFiles/carini.dir/clean

CMakeFiles/carini.dir/depend:
	cd /home/nyykki/Scrivania/histos_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build/CMakeFiles/carini.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/carini.dir/depend


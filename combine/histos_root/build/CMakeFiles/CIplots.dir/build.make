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
include CMakeFiles/CIplots.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CIplots.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CIplots.dir/flags.make

CMakeFiles/CIplots.dir/src/CIplots.cpp.o: CMakeFiles/CIplots.dir/flags.make
CMakeFiles/CIplots.dir/src/CIplots.cpp.o: ../src/CIplots.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CIplots.dir/src/CIplots.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CIplots.dir/src/CIplots.cpp.o -c /home/nyykki/Scrivania/histos_root/src/CIplots.cpp

CMakeFiles/CIplots.dir/src/CIplots.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CIplots.dir/src/CIplots.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nyykki/Scrivania/histos_root/src/CIplots.cpp > CMakeFiles/CIplots.dir/src/CIplots.cpp.i

CMakeFiles/CIplots.dir/src/CIplots.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CIplots.dir/src/CIplots.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nyykki/Scrivania/histos_root/src/CIplots.cpp -o CMakeFiles/CIplots.dir/src/CIplots.cpp.s

# Object files for target CIplots
CIplots_OBJECTS = \
"CMakeFiles/CIplots.dir/src/CIplots.cpp.o"

# External object files for target CIplots
CIplots_EXTERNAL_OBJECTS =

CIplots: CMakeFiles/CIplots.dir/src/CIplots.cpp.o
CIplots: CMakeFiles/CIplots.dir/build.make
CIplots: /home/nyykki/root/lib/libCore.so
CIplots: /home/nyykki/root/lib/libImt.so
CIplots: /home/nyykki/root/lib/libRIO.so
CIplots: /home/nyykki/root/lib/libNet.so
CIplots: /home/nyykki/root/lib/libHist.so
CIplots: /home/nyykki/root/lib/libGraf.so
CIplots: /home/nyykki/root/lib/libGraf3d.so
CIplots: /home/nyykki/root/lib/libGpad.so
CIplots: /home/nyykki/root/lib/libROOTDataFrame.so
CIplots: /home/nyykki/root/lib/libTree.so
CIplots: /home/nyykki/root/lib/libTreePlayer.so
CIplots: /home/nyykki/root/lib/libRint.so
CIplots: /home/nyykki/root/lib/libPostscript.so
CIplots: /home/nyykki/root/lib/libMatrix.so
CIplots: /home/nyykki/root/lib/libPhysics.so
CIplots: /home/nyykki/root/lib/libMathCore.so
CIplots: /home/nyykki/root/lib/libThread.so
CIplots: /home/nyykki/root/lib/libMultiProc.so
CIplots: CMakeFiles/CIplots.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CIplots"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CIplots.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CIplots.dir/build: CIplots

.PHONY : CMakeFiles/CIplots.dir/build

CMakeFiles/CIplots.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CIplots.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CIplots.dir/clean

CMakeFiles/CIplots.dir/depend:
	cd /home/nyykki/Scrivania/histos_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build/CMakeFiles/CIplots.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CIplots.dir/depend


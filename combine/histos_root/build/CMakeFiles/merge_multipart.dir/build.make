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
include CMakeFiles/merge_multipart.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/merge_multipart.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/merge_multipart.dir/flags.make

CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o: CMakeFiles/merge_multipart.dir/flags.make
CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o: ../src/merge_multipart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o -c /home/nyykki/Scrivania/histos_root/src/merge_multipart.cpp

CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nyykki/Scrivania/histos_root/src/merge_multipart.cpp > CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.i

CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nyykki/Scrivania/histos_root/src/merge_multipart.cpp -o CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.s

# Object files for target merge_multipart
merge_multipart_OBJECTS = \
"CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o"

# External object files for target merge_multipart
merge_multipart_EXTERNAL_OBJECTS =

merge_multipart: CMakeFiles/merge_multipart.dir/src/merge_multipart.cpp.o
merge_multipart: CMakeFiles/merge_multipart.dir/build.make
merge_multipart: /home/nyykki/root/lib/libCore.so
merge_multipart: /home/nyykki/root/lib/libImt.so
merge_multipart: /home/nyykki/root/lib/libRIO.so
merge_multipart: /home/nyykki/root/lib/libNet.so
merge_multipart: /home/nyykki/root/lib/libHist.so
merge_multipart: /home/nyykki/root/lib/libGraf.so
merge_multipart: /home/nyykki/root/lib/libGraf3d.so
merge_multipart: /home/nyykki/root/lib/libGpad.so
merge_multipart: /home/nyykki/root/lib/libROOTDataFrame.so
merge_multipart: /home/nyykki/root/lib/libTree.so
merge_multipart: /home/nyykki/root/lib/libTreePlayer.so
merge_multipart: /home/nyykki/root/lib/libRint.so
merge_multipart: /home/nyykki/root/lib/libPostscript.so
merge_multipart: /home/nyykki/root/lib/libMatrix.so
merge_multipart: /home/nyykki/root/lib/libPhysics.so
merge_multipart: /home/nyykki/root/lib/libMathCore.so
merge_multipart: /home/nyykki/root/lib/libThread.so
merge_multipart: /home/nyykki/root/lib/libMultiProc.so
merge_multipart: ../libExRootAnalysis.so
merge_multipart: CMakeFiles/merge_multipart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable merge_multipart"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/merge_multipart.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/merge_multipart.dir/build: merge_multipart

.PHONY : CMakeFiles/merge_multipart.dir/build

CMakeFiles/merge_multipart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/merge_multipart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/merge_multipart.dir/clean

CMakeFiles/merge_multipart.dir/depend:
	cd /home/nyykki/Scrivania/histos_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build/CMakeFiles/merge_multipart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/merge_multipart.dir/depend

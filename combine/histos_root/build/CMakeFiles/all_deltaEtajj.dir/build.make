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
include CMakeFiles/all_deltaEtajj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/all_deltaEtajj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/all_deltaEtajj.dir/flags.make

CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o: CMakeFiles/all_deltaEtajj.dir/flags.make
CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o: ../src/all_deltaEtajj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o -c /home/nyykki/Scrivania/histos_root/src/all_deltaEtajj.cpp

CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nyykki/Scrivania/histos_root/src/all_deltaEtajj.cpp > CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.i

CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nyykki/Scrivania/histos_root/src/all_deltaEtajj.cpp -o CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.s

# Object files for target all_deltaEtajj
all_deltaEtajj_OBJECTS = \
"CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o"

# External object files for target all_deltaEtajj
all_deltaEtajj_EXTERNAL_OBJECTS =

all_deltaEtajj: CMakeFiles/all_deltaEtajj.dir/src/all_deltaEtajj.cpp.o
all_deltaEtajj: CMakeFiles/all_deltaEtajj.dir/build.make
all_deltaEtajj: /home/nyykki/root/lib/libCore.so
all_deltaEtajj: /home/nyykki/root/lib/libImt.so
all_deltaEtajj: /home/nyykki/root/lib/libRIO.so
all_deltaEtajj: /home/nyykki/root/lib/libNet.so
all_deltaEtajj: /home/nyykki/root/lib/libHist.so
all_deltaEtajj: /home/nyykki/root/lib/libGraf.so
all_deltaEtajj: /home/nyykki/root/lib/libGraf3d.so
all_deltaEtajj: /home/nyykki/root/lib/libGpad.so
all_deltaEtajj: /home/nyykki/root/lib/libROOTDataFrame.so
all_deltaEtajj: /home/nyykki/root/lib/libTree.so
all_deltaEtajj: /home/nyykki/root/lib/libTreePlayer.so
all_deltaEtajj: /home/nyykki/root/lib/libRint.so
all_deltaEtajj: /home/nyykki/root/lib/libPostscript.so
all_deltaEtajj: /home/nyykki/root/lib/libMatrix.so
all_deltaEtajj: /home/nyykki/root/lib/libPhysics.so
all_deltaEtajj: /home/nyykki/root/lib/libMathCore.so
all_deltaEtajj: /home/nyykki/root/lib/libThread.so
all_deltaEtajj: /home/nyykki/root/lib/libMultiProc.so
all_deltaEtajj: ../libExRootAnalysis.so
all_deltaEtajj: CMakeFiles/all_deltaEtajj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable all_deltaEtajj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/all_deltaEtajj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/all_deltaEtajj.dir/build: all_deltaEtajj

.PHONY : CMakeFiles/all_deltaEtajj.dir/build

CMakeFiles/all_deltaEtajj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/all_deltaEtajj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/all_deltaEtajj.dir/clean

CMakeFiles/all_deltaEtajj.dir/depend:
	cd /home/nyykki/Scrivania/histos_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build/CMakeFiles/all_deltaEtajj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/all_deltaEtajj.dir/depend


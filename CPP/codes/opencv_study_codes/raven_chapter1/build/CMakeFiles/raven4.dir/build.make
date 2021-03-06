# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build

# Include any dependencies generated for this target.
include CMakeFiles/raven4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raven4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raven4.dir/flags.make

CMakeFiles/raven4.dir/raven4.cpp.o: CMakeFiles/raven4.dir/flags.make
CMakeFiles/raven4.dir/raven4.cpp.o: ../raven4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raven4.dir/raven4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raven4.dir/raven4.cpp.o -c /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/raven4.cpp

CMakeFiles/raven4.dir/raven4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raven4.dir/raven4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/raven4.cpp > CMakeFiles/raven4.dir/raven4.cpp.i

CMakeFiles/raven4.dir/raven4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raven4.dir/raven4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/raven4.cpp -o CMakeFiles/raven4.dir/raven4.cpp.s

CMakeFiles/raven4.dir/raven4.cpp.o.requires:

.PHONY : CMakeFiles/raven4.dir/raven4.cpp.o.requires

CMakeFiles/raven4.dir/raven4.cpp.o.provides: CMakeFiles/raven4.dir/raven4.cpp.o.requires
	$(MAKE) -f CMakeFiles/raven4.dir/build.make CMakeFiles/raven4.dir/raven4.cpp.o.provides.build
.PHONY : CMakeFiles/raven4.dir/raven4.cpp.o.provides

CMakeFiles/raven4.dir/raven4.cpp.o.provides.build: CMakeFiles/raven4.dir/raven4.cpp.o


# Object files for target raven4
raven4_OBJECTS = \
"CMakeFiles/raven4.dir/raven4.cpp.o"

# External object files for target raven4
raven4_EXTERNAL_OBJECTS =

../bin/raven4: CMakeFiles/raven4.dir/raven4.cpp.o
../bin/raven4: CMakeFiles/raven4.dir/build.make
../bin/raven4: /usr/local/lib/libopencv_videostab.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_ts.a
../bin/raven4: /usr/local/lib/libopencv_superres.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_stitching.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_contrib.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_nonfree.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_ocl.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_gpu.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_photo.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_objdetect.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_legacy.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_video.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_ml.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_calib3d.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_features2d.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_highgui.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_imgproc.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_flann.so.2.4.13
../bin/raven4: /usr/local/lib/libopencv_core.so.2.4.13
../bin/raven4: CMakeFiles/raven4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/raven4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raven4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raven4.dir/build: ../bin/raven4

.PHONY : CMakeFiles/raven4.dir/build

CMakeFiles/raven4.dir/requires: CMakeFiles/raven4.dir/raven4.cpp.o.requires

.PHONY : CMakeFiles/raven4.dir/requires

CMakeFiles/raven4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raven4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raven4.dir/clean

CMakeFiles/raven4.dir/depend:
	cd /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1 /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1 /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build /home/shadow_raven/MyDataBase/CPP/opencv/study/cppcodes/raven_chapter1/build/CMakeFiles/raven4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raven4.dir/depend


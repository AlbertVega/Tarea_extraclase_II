# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /snap/clion/209/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/209/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/albert/Documentos/GitHub/Tarea_extraclase_II

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/Server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server.cpp.o: ../Server.cpp
CMakeFiles/Server.dir/Server.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/Server.cpp.o -MF CMakeFiles/Server.dir/Server.cpp.o.d -o CMakeFiles/Server.dir/Server.cpp.o -c /home/albert/Documentos/GitHub/Tarea_extraclase_II/Server.cpp

CMakeFiles/Server.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/albert/Documentos/GitHub/Tarea_extraclase_II/Server.cpp > CMakeFiles/Server.dir/Server.cpp.i

CMakeFiles/Server.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/albert/Documentos/GitHub/Tarea_extraclase_II/Server.cpp -o CMakeFiles/Server.dir/Server.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/Server.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/Server.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: /usr/local/lib/libopencv_gapi.so.4.6.0
Server: /usr/local/lib/libopencv_highgui.so.4.6.0
Server: /usr/local/lib/libopencv_ml.so.4.6.0
Server: /usr/local/lib/libopencv_objdetect.so.4.6.0
Server: /usr/local/lib/libopencv_photo.so.4.6.0
Server: /usr/local/lib/libopencv_stitching.so.4.6.0
Server: /usr/local/lib/libopencv_video.so.4.6.0
Server: /usr/local/lib/libopencv_videoio.so.4.6.0
Server: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
Server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
Server: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.74.0
Server: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
Server: /usr/local/lib/libopencv_dnn.so.4.6.0
Server: /usr/local/lib/libopencv_calib3d.so.4.6.0
Server: /usr/local/lib/libopencv_features2d.so.4.6.0
Server: /usr/local/lib/libopencv_flann.so.4.6.0
Server: /usr/local/lib/libopencv_imgproc.so.4.6.0
Server: /usr/local/lib/libopencv_core.so.4.6.0
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server
.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/albert/Documentos/GitHub/Tarea_extraclase_II /home/albert/Documentos/GitHub/Tarea_extraclase_II /home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug /home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug /home/albert/Documentos/GitHub/Tarea_extraclase_II/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend


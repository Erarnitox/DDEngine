# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/me/Projects/CPP/GameEngine/GameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/me/Projects/CPP/GameEngine/GameEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/gameengine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameengine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameengine.dir/flags.make

CMakeFiles/gameengine.dir/engine/engine.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/engine.cpp.o: ../engine/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gameengine.dir/engine/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/engine.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/engine.cpp

CMakeFiles/gameengine.dir/engine/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/engine.cpp > CMakeFiles/gameengine.dir/engine/engine.cpp.i

CMakeFiles/gameengine.dir/engine/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/engine.cpp -o CMakeFiles/gameengine.dir/engine/engine.cpp.s

CMakeFiles/gameengine.dir/engine/Display.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/Display.cpp.o: ../engine/Display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gameengine.dir/engine/Display.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/Display.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/Display.cpp

CMakeFiles/gameengine.dir/engine/Display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/Display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/Display.cpp > CMakeFiles/gameengine.dir/engine/Display.cpp.i

CMakeFiles/gameengine.dir/engine/Display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/Display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/Display.cpp -o CMakeFiles/gameengine.dir/engine/Display.cpp.s

CMakeFiles/gameengine.dir/engine/Shader.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/Shader.cpp.o: ../engine/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gameengine.dir/engine/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/Shader.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/Shader.cpp

CMakeFiles/gameengine.dir/engine/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/Shader.cpp > CMakeFiles/gameengine.dir/engine/Shader.cpp.i

CMakeFiles/gameengine.dir/engine/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/Shader.cpp -o CMakeFiles/gameengine.dir/engine/Shader.cpp.s

CMakeFiles/gameengine.dir/engine/Mesh.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/Mesh.cpp.o: ../engine/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gameengine.dir/engine/Mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/Mesh.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/Mesh.cpp

CMakeFiles/gameengine.dir/engine/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/Mesh.cpp > CMakeFiles/gameengine.dir/engine/Mesh.cpp.i

CMakeFiles/gameengine.dir/engine/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/Mesh.cpp -o CMakeFiles/gameengine.dir/engine/Mesh.cpp.s

CMakeFiles/gameengine.dir/engine/Texture.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/Texture.cpp.o: ../engine/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gameengine.dir/engine/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/Texture.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/Texture.cpp

CMakeFiles/gameengine.dir/engine/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/Texture.cpp > CMakeFiles/gameengine.dir/engine/Texture.cpp.i

CMakeFiles/gameengine.dir/engine/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/Texture.cpp -o CMakeFiles/gameengine.dir/engine/Texture.cpp.s

CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o: CMakeFiles/gameengine.dir/flags.make
CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o: ../engine/obj_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o -c /home/me/Projects/CPP/GameEngine/GameEngine/engine/obj_loader.cpp

CMakeFiles/gameengine.dir/engine/obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameengine.dir/engine/obj_loader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/CPP/GameEngine/GameEngine/engine/obj_loader.cpp > CMakeFiles/gameengine.dir/engine/obj_loader.cpp.i

CMakeFiles/gameengine.dir/engine/obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameengine.dir/engine/obj_loader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/CPP/GameEngine/GameEngine/engine/obj_loader.cpp -o CMakeFiles/gameengine.dir/engine/obj_loader.cpp.s

# Object files for target gameengine
gameengine_OBJECTS = \
"CMakeFiles/gameengine.dir/engine/engine.cpp.o" \
"CMakeFiles/gameengine.dir/engine/Display.cpp.o" \
"CMakeFiles/gameengine.dir/engine/Shader.cpp.o" \
"CMakeFiles/gameengine.dir/engine/Mesh.cpp.o" \
"CMakeFiles/gameengine.dir/engine/Texture.cpp.o" \
"CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o"

# External object files for target gameengine
gameengine_EXTERNAL_OBJECTS =

libgameengine.so: CMakeFiles/gameengine.dir/engine/engine.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/engine/Display.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/engine/Shader.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/engine/Mesh.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/engine/Texture.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/engine/obj_loader.cpp.o
libgameengine.so: CMakeFiles/gameengine.dir/build.make
libgameengine.so: /usr/lib/libOpenGL.so
libgameengine.so: /usr/lib/libGLEW.so
libgameengine.so: /usr/lib/libSDL2-2.0.so.0.14.0
libgameengine.so: CMakeFiles/gameengine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library libgameengine.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameengine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameengine.dir/build: libgameengine.so

.PHONY : CMakeFiles/gameengine.dir/build

CMakeFiles/gameengine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameengine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameengine.dir/clean

CMakeFiles/gameengine.dir/depend:
	cd /home/me/Projects/CPP/GameEngine/GameEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/me/Projects/CPP/GameEngine/GameEngine /home/me/Projects/CPP/GameEngine/GameEngine /home/me/Projects/CPP/GameEngine/GameEngine/build /home/me/Projects/CPP/GameEngine/GameEngine/build /home/me/Projects/CPP/GameEngine/GameEngine/build/CMakeFiles/gameengine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameengine.dir/depend

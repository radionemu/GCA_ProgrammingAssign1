# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build

# Include any dependencies generated for this target.
include CMakeFiles/GLA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GLA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GLA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GLA.dir/flags.make

CMakeFiles/GLA.dir/Sample_main.cpp.obj: CMakeFiles/GLA.dir/flags.make
CMakeFiles/GLA.dir/Sample_main.cpp.obj: CMakeFiles/GLA.dir/includes_CXX.rsp
CMakeFiles/GLA.dir/Sample_main.cpp.obj: C:/Users/s_radionemu/.vscode/projects/OpenGLA_LABS_Assign1/Sample_main.cpp
CMakeFiles/GLA.dir/Sample_main.cpp.obj: CMakeFiles/GLA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GLA.dir/Sample_main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GLA.dir/Sample_main.cpp.obj -MF CMakeFiles\GLA.dir\Sample_main.cpp.obj.d -o CMakeFiles\GLA.dir\Sample_main.cpp.obj -c C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\Sample_main.cpp

CMakeFiles/GLA.dir/Sample_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GLA.dir/Sample_main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\Sample_main.cpp > CMakeFiles\GLA.dir\Sample_main.cpp.i

CMakeFiles/GLA.dir/Sample_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GLA.dir/Sample_main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\Sample_main.cpp -o CMakeFiles\GLA.dir\Sample_main.cpp.s

CMakeFiles/GLA.dir/general/resolution.cpp.obj: CMakeFiles/GLA.dir/flags.make
CMakeFiles/GLA.dir/general/resolution.cpp.obj: CMakeFiles/GLA.dir/includes_CXX.rsp
CMakeFiles/GLA.dir/general/resolution.cpp.obj: C:/Users/s_radionemu/.vscode/projects/OpenGLA_LABS_Assign1/general/resolution.cpp
CMakeFiles/GLA.dir/general/resolution.cpp.obj: CMakeFiles/GLA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GLA.dir/general/resolution.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GLA.dir/general/resolution.cpp.obj -MF CMakeFiles\GLA.dir\general\resolution.cpp.obj.d -o CMakeFiles\GLA.dir\general\resolution.cpp.obj -c C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\general\resolution.cpp

CMakeFiles/GLA.dir/general/resolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GLA.dir/general/resolution.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\general\resolution.cpp > CMakeFiles\GLA.dir\general\resolution.cpp.i

CMakeFiles/GLA.dir/general/resolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GLA.dir/general/resolution.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\general\resolution.cpp -o CMakeFiles\GLA.dir\general\resolution.cpp.s

# Object files for target GLA
GLA_OBJECTS = \
"CMakeFiles/GLA.dir/Sample_main.cpp.obj" \
"CMakeFiles/GLA.dir/general/resolution.cpp.obj"

# External object files for target GLA
GLA_EXTERNAL_OBJECTS =

GLA.exe: CMakeFiles/GLA.dir/Sample_main.cpp.obj
GLA.exe: CMakeFiles/GLA.dir/general/resolution.cpp.obj
GLA.exe: CMakeFiles/GLA.dir/build.make
GLA.exe: CMakeFiles/GLA.dir/linkLibs.rsp
GLA.exe: CMakeFiles/GLA.dir/objects1.rsp
GLA.exe: CMakeFiles/GLA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GLA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GLA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GLA.dir/build: GLA.exe
.PHONY : CMakeFiles/GLA.dir/build

CMakeFiles/GLA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GLA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GLA.dir/clean

CMakeFiles/GLA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1 C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1 C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build C:\Users\s_radionemu\.vscode\projects\OpenGLA_LABS_Assign1\build\CMakeFiles\GLA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GLA.dir/depend


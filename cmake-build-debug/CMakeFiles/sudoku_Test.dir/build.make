# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/Tobi/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Tobi/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Entwicklung/Studium/AlgoDat2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sudoku_Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku_Test.dir/flags.make

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o: CMakeFiles/sudoku_Test.dir/flags.make
CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o: ../test/testMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o -c /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/testMain.cpp

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku_Test.dir/test/testMain.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/testMain.cpp > CMakeFiles/sudoku_Test.dir/test/testMain.cpp.i

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku_Test.dir/test/testMain.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/testMain.cpp -o CMakeFiles/sudoku_Test.dir/test/testMain.cpp.s

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.requires:

.PHONY : CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.requires

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.provides: CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/sudoku_Test.dir/build.make CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.provides.build
.PHONY : CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.provides

CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.provides.build: CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o


CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o: CMakeFiles/sudoku_Test.dir/flags.make
CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o: ../test/test_sudokuGitter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o -c /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_sudokuGitter.cpp

CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_sudokuGitter.cpp > CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.i

CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_sudokuGitter.cpp -o CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.s

CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.requires:

.PHONY : CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.requires

CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.provides: CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.requires
	$(MAKE) -f CMakeFiles/sudoku_Test.dir/build.make CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.provides.build
.PHONY : CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.provides

CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.provides.build: CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o


CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o: CMakeFiles/sudoku_Test.dir/flags.make
CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o: ../SudokuGitter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o -c /cygdrive/d/Entwicklung/Studium/AlgoDat2/SudokuGitter.cpp

CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Entwicklung/Studium/AlgoDat2/SudokuGitter.cpp > CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.i

CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Entwicklung/Studium/AlgoDat2/SudokuGitter.cpp -o CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.s

CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.requires:

.PHONY : CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.requires

CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.provides: CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.requires
	$(MAKE) -f CMakeFiles/sudoku_Test.dir/build.make CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.provides.build
.PHONY : CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.provides

CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.provides.build: CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o


CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o: CMakeFiles/sudoku_Test.dir/flags.make
CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o: ../test/test_SudokuGitterColRow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o -c /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_SudokuGitterColRow.cpp

CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_SudokuGitterColRow.cpp > CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.i

CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Entwicklung/Studium/AlgoDat2/test/test_SudokuGitterColRow.cpp -o CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.s

CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.requires:

.PHONY : CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.requires

CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.provides: CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.requires
	$(MAKE) -f CMakeFiles/sudoku_Test.dir/build.make CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.provides.build
.PHONY : CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.provides

CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.provides.build: CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o


# Object files for target sudoku_Test
sudoku_Test_OBJECTS = \
"CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o" \
"CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o" \
"CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o" \
"CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o"

# External object files for target sudoku_Test
sudoku_Test_EXTERNAL_OBJECTS =

sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o
sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o
sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o
sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o
sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/build.make
sudoku_Test.exe: googletest/libgtest.a
sudoku_Test.exe: googletest/libgtest_main.a
sudoku_Test.exe: googletest/libgtest.a
sudoku_Test.exe: CMakeFiles/sudoku_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sudoku_Test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sudoku_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku_Test.dir/build: sudoku_Test.exe

.PHONY : CMakeFiles/sudoku_Test.dir/build

CMakeFiles/sudoku_Test.dir/requires: CMakeFiles/sudoku_Test.dir/test/testMain.cpp.o.requires
CMakeFiles/sudoku_Test.dir/requires: CMakeFiles/sudoku_Test.dir/test/test_sudokuGitter.cpp.o.requires
CMakeFiles/sudoku_Test.dir/requires: CMakeFiles/sudoku_Test.dir/SudokuGitter.cpp.o.requires
CMakeFiles/sudoku_Test.dir/requires: CMakeFiles/sudoku_Test.dir/test/test_SudokuGitterColRow.cpp.o.requires

.PHONY : CMakeFiles/sudoku_Test.dir/requires

CMakeFiles/sudoku_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sudoku_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sudoku_Test.dir/clean

CMakeFiles/sudoku_Test.dir/depend:
	cd /cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Entwicklung/Studium/AlgoDat2 /cygdrive/d/Entwicklung/Studium/AlgoDat2 /cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug /cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug /cygdrive/d/Entwicklung/Studium/AlgoDat2/cmake-build-debug/CMakeFiles/sudoku_Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sudoku_Test.dir/depend


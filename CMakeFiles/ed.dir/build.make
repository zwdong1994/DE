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
CMAKE_SOURCE_DIR = /home/victor/zwd/ecc_dedup/ed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/zwd/ecc_dedup/ed

# Include any dependencies generated for this target.
include CMakeFiles/ed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ed.dir/flags.make

CMakeFiles/ed.dir/main.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ed.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/main.cpp.o -c /home/victor/zwd/ecc_dedup/ed/main.cpp

CMakeFiles/ed.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/main.cpp > CMakeFiles/ed.dir/main.cpp.i

CMakeFiles/ed.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/main.cpp -o CMakeFiles/ed.dir/main.cpp.s

CMakeFiles/ed.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/main.cpp.o.requires

CMakeFiles/ed.dir/main.cpp.o.provides: CMakeFiles/ed.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/main.cpp.o.provides

CMakeFiles/ed.dir/main.cpp.o.provides.build: CMakeFiles/ed.dir/main.cpp.o


CMakeFiles/ed.dir/src/bch.c.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/bch.c.o: src/bch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ed.dir/src/bch.c.o"
	g++  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ed.dir/src/bch.c.o   -c /home/victor/zwd/ecc_dedup/ed/src/bch.c

CMakeFiles/ed.dir/src/bch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed.dir/src/bch.c.i"
	g++  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/bch.c > CMakeFiles/ed.dir/src/bch.c.i

CMakeFiles/ed.dir/src/bch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed.dir/src/bch.c.s"
	g++  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/bch.c -o CMakeFiles/ed.dir/src/bch.c.s

CMakeFiles/ed.dir/src/bch.c.o.requires:

.PHONY : CMakeFiles/ed.dir/src/bch.c.o.requires

CMakeFiles/ed.dir/src/bch.c.o.provides: CMakeFiles/ed.dir/src/bch.c.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bch.c.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/bch.c.o.provides

CMakeFiles/ed.dir/src/bch.c.o.provides.build: CMakeFiles/ed.dir/src/bch.c.o


CMakeFiles/ed.dir/src/com_t.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/com_t.cpp.o: src/com_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ed.dir/src/com_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/src/com_t.cpp.o -c /home/victor/zwd/ecc_dedup/ed/src/com_t.cpp

CMakeFiles/ed.dir/src/com_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/src/com_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/com_t.cpp > CMakeFiles/ed.dir/src/com_t.cpp.i

CMakeFiles/ed.dir/src/com_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/src/com_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/com_t.cpp -o CMakeFiles/ed.dir/src/com_t.cpp.s

CMakeFiles/ed.dir/src/com_t.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/src/com_t.cpp.o.requires

CMakeFiles/ed.dir/src/com_t.cpp.o.provides: CMakeFiles/ed.dir/src/com_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/com_t.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/com_t.cpp.o.provides

CMakeFiles/ed.dir/src/com_t.cpp.o.provides.build: CMakeFiles/ed.dir/src/com_t.cpp.o


CMakeFiles/ed.dir/src/bloom_func.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/bloom_func.cpp.o: src/bloom_func.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ed.dir/src/bloom_func.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/src/bloom_func.cpp.o -c /home/victor/zwd/ecc_dedup/ed/src/bloom_func.cpp

CMakeFiles/ed.dir/src/bloom_func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/src/bloom_func.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/bloom_func.cpp > CMakeFiles/ed.dir/src/bloom_func.cpp.i

CMakeFiles/ed.dir/src/bloom_func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/src/bloom_func.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/bloom_func.cpp -o CMakeFiles/ed.dir/src/bloom_func.cpp.s

CMakeFiles/ed.dir/src/bloom_func.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/src/bloom_func.cpp.o.requires

CMakeFiles/ed.dir/src/bloom_func.cpp.o.provides: CMakeFiles/ed.dir/src/bloom_func.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bloom_func.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/bloom_func.cpp.o.provides

CMakeFiles/ed.dir/src/bloom_func.cpp.o.provides.build: CMakeFiles/ed.dir/src/bloom_func.cpp.o


CMakeFiles/ed.dir/src/cache.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/cache.cpp.o: src/cache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ed.dir/src/cache.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/src/cache.cpp.o -c /home/victor/zwd/ecc_dedup/ed/src/cache.cpp

CMakeFiles/ed.dir/src/cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/src/cache.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/cache.cpp > CMakeFiles/ed.dir/src/cache.cpp.i

CMakeFiles/ed.dir/src/cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/src/cache.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/cache.cpp -o CMakeFiles/ed.dir/src/cache.cpp.s

CMakeFiles/ed.dir/src/cache.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/src/cache.cpp.o.requires

CMakeFiles/ed.dir/src/cache.cpp.o.provides: CMakeFiles/ed.dir/src/cache.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/cache.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/cache.cpp.o.provides

CMakeFiles/ed.dir/src/cache.cpp.o.provides.build: CMakeFiles/ed.dir/src/cache.cpp.o


CMakeFiles/ed.dir/src/dedup.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/dedup.cpp.o: src/dedup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ed.dir/src/dedup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/src/dedup.cpp.o -c /home/victor/zwd/ecc_dedup/ed/src/dedup.cpp

CMakeFiles/ed.dir/src/dedup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/src/dedup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/dedup.cpp > CMakeFiles/ed.dir/src/dedup.cpp.i

CMakeFiles/ed.dir/src/dedup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/src/dedup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/dedup.cpp -o CMakeFiles/ed.dir/src/dedup.cpp.s

CMakeFiles/ed.dir/src/dedup.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/src/dedup.cpp.o.requires

CMakeFiles/ed.dir/src/dedup.cpp.o.provides: CMakeFiles/ed.dir/src/dedup.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/dedup.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/dedup.cpp.o.provides

CMakeFiles/ed.dir/src/dedup.cpp.o.provides.build: CMakeFiles/ed.dir/src/dedup.cpp.o


CMakeFiles/ed.dir/src/mt.cpp.o: CMakeFiles/ed.dir/flags.make
CMakeFiles/ed.dir/src/mt.cpp.o: src/mt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ed.dir/src/mt.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ed.dir/src/mt.cpp.o -c /home/victor/zwd/ecc_dedup/ed/src/mt.cpp

CMakeFiles/ed.dir/src/mt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ed.dir/src/mt.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/victor/zwd/ecc_dedup/ed/src/mt.cpp > CMakeFiles/ed.dir/src/mt.cpp.i

CMakeFiles/ed.dir/src/mt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ed.dir/src/mt.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/victor/zwd/ecc_dedup/ed/src/mt.cpp -o CMakeFiles/ed.dir/src/mt.cpp.s

CMakeFiles/ed.dir/src/mt.cpp.o.requires:

.PHONY : CMakeFiles/ed.dir/src/mt.cpp.o.requires

CMakeFiles/ed.dir/src/mt.cpp.o.provides: CMakeFiles/ed.dir/src/mt.cpp.o.requires
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/mt.cpp.o.provides.build
.PHONY : CMakeFiles/ed.dir/src/mt.cpp.o.provides

CMakeFiles/ed.dir/src/mt.cpp.o.provides.build: CMakeFiles/ed.dir/src/mt.cpp.o


# Object files for target ed
ed_OBJECTS = \
"CMakeFiles/ed.dir/main.cpp.o" \
"CMakeFiles/ed.dir/src/bch.c.o" \
"CMakeFiles/ed.dir/src/com_t.cpp.o" \
"CMakeFiles/ed.dir/src/bloom_func.cpp.o" \
"CMakeFiles/ed.dir/src/cache.cpp.o" \
"CMakeFiles/ed.dir/src/dedup.cpp.o" \
"CMakeFiles/ed.dir/src/mt.cpp.o"

# External object files for target ed
ed_EXTERNAL_OBJECTS =

ed: CMakeFiles/ed.dir/main.cpp.o
ed: CMakeFiles/ed.dir/src/bch.c.o
ed: CMakeFiles/ed.dir/src/com_t.cpp.o
ed: CMakeFiles/ed.dir/src/bloom_func.cpp.o
ed: CMakeFiles/ed.dir/src/cache.cpp.o
ed: CMakeFiles/ed.dir/src/dedup.cpp.o
ed: CMakeFiles/ed.dir/src/mt.cpp.o
ed: CMakeFiles/ed.dir/build.make
ed: /usr/lib/x86_64-linux-gnu/librt.so
ed: /usr/lib/x86_64-linux-gnu/libcrypto.a
ed: CMakeFiles/ed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/victor/zwd/ecc_dedup/ed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ed.dir/build: ed

.PHONY : CMakeFiles/ed.dir/build

CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/main.cpp.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/bch.c.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/com_t.cpp.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/bloom_func.cpp.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/cache.cpp.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/dedup.cpp.o.requires
CMakeFiles/ed.dir/requires: CMakeFiles/ed.dir/src/mt.cpp.o.requires

.PHONY : CMakeFiles/ed.dir/requires

CMakeFiles/ed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ed.dir/clean

CMakeFiles/ed.dir/depend:
	cd /home/victor/zwd/ecc_dedup/ed && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/victor/zwd/ecc_dedup/ed /home/victor/zwd/ecc_dedup/ed /home/victor/zwd/ecc_dedup/ed /home/victor/zwd/ecc_dedup/ed /home/victor/zwd/ecc_dedup/ed/CMakeFiles/ed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ed.dir/depend

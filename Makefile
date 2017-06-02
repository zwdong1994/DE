# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/victor/zwd/ecc_dedup/ed/CMakeFiles /home/victor/zwd/ecc_dedup/ed/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/victor/zwd/ecc_dedup/ed/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ed

# Build rule for target.
ed: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ed
.PHONY : ed

# fast build rule for target.
ed/fast:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/build
.PHONY : ed/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/main.cpp.s
.PHONY : main.cpp.s

src/bch.o: src/bch.c.o

.PHONY : src/bch.o

# target to build an object file
src/bch.c.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bch.c.o
.PHONY : src/bch.c.o

src/bch.i: src/bch.c.i

.PHONY : src/bch.i

# target to preprocess a source file
src/bch.c.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bch.c.i
.PHONY : src/bch.c.i

src/bch.s: src/bch.c.s

.PHONY : src/bch.s

# target to generate assembly for a file
src/bch.c.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bch.c.s
.PHONY : src/bch.c.s

src/bloom_func.o: src/bloom_func.cpp.o

.PHONY : src/bloom_func.o

# target to build an object file
src/bloom_func.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bloom_func.cpp.o
.PHONY : src/bloom_func.cpp.o

src/bloom_func.i: src/bloom_func.cpp.i

.PHONY : src/bloom_func.i

# target to preprocess a source file
src/bloom_func.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bloom_func.cpp.i
.PHONY : src/bloom_func.cpp.i

src/bloom_func.s: src/bloom_func.cpp.s

.PHONY : src/bloom_func.s

# target to generate assembly for a file
src/bloom_func.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/bloom_func.cpp.s
.PHONY : src/bloom_func.cpp.s

src/cache.o: src/cache.cpp.o

.PHONY : src/cache.o

# target to build an object file
src/cache.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/cache.cpp.o
.PHONY : src/cache.cpp.o

src/cache.i: src/cache.cpp.i

.PHONY : src/cache.i

# target to preprocess a source file
src/cache.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/cache.cpp.i
.PHONY : src/cache.cpp.i

src/cache.s: src/cache.cpp.s

.PHONY : src/cache.s

# target to generate assembly for a file
src/cache.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/cache.cpp.s
.PHONY : src/cache.cpp.s

src/com_t.o: src/com_t.cpp.o

.PHONY : src/com_t.o

# target to build an object file
src/com_t.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/com_t.cpp.o
.PHONY : src/com_t.cpp.o

src/com_t.i: src/com_t.cpp.i

.PHONY : src/com_t.i

# target to preprocess a source file
src/com_t.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/com_t.cpp.i
.PHONY : src/com_t.cpp.i

src/com_t.s: src/com_t.cpp.s

.PHONY : src/com_t.s

# target to generate assembly for a file
src/com_t.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/com_t.cpp.s
.PHONY : src/com_t.cpp.s

src/dedup.o: src/dedup.cpp.o

.PHONY : src/dedup.o

# target to build an object file
src/dedup.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/dedup.cpp.o
.PHONY : src/dedup.cpp.o

src/dedup.i: src/dedup.cpp.i

.PHONY : src/dedup.i

# target to preprocess a source file
src/dedup.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/dedup.cpp.i
.PHONY : src/dedup.cpp.i

src/dedup.s: src/dedup.cpp.s

.PHONY : src/dedup.s

# target to generate assembly for a file
src/dedup.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/dedup.cpp.s
.PHONY : src/dedup.cpp.s

src/mt.o: src/mt.cpp.o

.PHONY : src/mt.o

# target to build an object file
src/mt.cpp.o:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/mt.cpp.o
.PHONY : src/mt.cpp.o

src/mt.i: src/mt.cpp.i

.PHONY : src/mt.i

# target to preprocess a source file
src/mt.cpp.i:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/mt.cpp.i
.PHONY : src/mt.cpp.i

src/mt.s: src/mt.cpp.s

.PHONY : src/mt.s

# target to generate assembly for a file
src/mt.cpp.s:
	$(MAKE) -f CMakeFiles/ed.dir/build.make CMakeFiles/ed.dir/src/mt.cpp.s
.PHONY : src/mt.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ed"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/bch.o"
	@echo "... src/bch.i"
	@echo "... src/bch.s"
	@echo "... src/bloom_func.o"
	@echo "... src/bloom_func.i"
	@echo "... src/bloom_func.s"
	@echo "... src/cache.o"
	@echo "... src/cache.i"
	@echo "... src/cache.s"
	@echo "... src/com_t.o"
	@echo "... src/com_t.i"
	@echo "... src/com_t.s"
	@echo "... src/dedup.o"
	@echo "... src/dedup.i"
	@echo "... src/dedup.s"
	@echo "... src/mt.o"
	@echo "... src/mt.i"
	@echo "... src/mt.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/evgenijk/CLionProjects/msu_cmc_cg_2021-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evgenijk/CLionProjects/msu_cmc_cg_2021-master

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/evgenijk/CLionProjects/msu_cmc_cg_2021-master/CMakeFiles /home/evgenijk/CLionProjects/msu_cmc_cg_2021-master/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/evgenijk/CLionProjects/msu_cmc_cg_2021-master/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

Image.o: Image.cpp.o

.PHONY : Image.o

# target to build an object file
Image.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.o
.PHONY : Image.cpp.o

Image.i: Image.cpp.i

.PHONY : Image.i

# target to preprocess a source file
Image.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.i
.PHONY : Image.cpp.i

Image.s: Image.cpp.s

.PHONY : Image.s

# target to generate assembly for a file
Image.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.s
.PHONY : Image.cpp.s

MovingSprite.o: MovingSprite.cpp.o

.PHONY : MovingSprite.o

# target to build an object file
MovingSprite.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/MovingSprite.cpp.o
.PHONY : MovingSprite.cpp.o

MovingSprite.i: MovingSprite.cpp.i

.PHONY : MovingSprite.i

# target to preprocess a source file
MovingSprite.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/MovingSprite.cpp.i
.PHONY : MovingSprite.cpp.i

MovingSprite.s: MovingSprite.cpp.s

.PHONY : MovingSprite.s

# target to generate assembly for a file
MovingSprite.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/MovingSprite.cpp.s
.PHONY : MovingSprite.cpp.s

Player.o: Player.cpp.o

.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i

.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s

.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.s
.PHONY : Player.cpp.s

SnowBall.o: SnowBall.cpp.o

.PHONY : SnowBall.o

# target to build an object file
SnowBall.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SnowBall.cpp.o
.PHONY : SnowBall.cpp.o

SnowBall.i: SnowBall.cpp.i

.PHONY : SnowBall.i

# target to preprocess a source file
SnowBall.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SnowBall.cpp.i
.PHONY : SnowBall.cpp.i

SnowBall.s: SnowBall.cpp.s

.PHONY : SnowBall.s

# target to generate assembly for a file
SnowBall.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SnowBall.cpp.s
.PHONY : SnowBall.cpp.s

Sprite.o: Sprite.cpp.o

.PHONY : Sprite.o

# target to build an object file
Sprite.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Sprite.cpp.o
.PHONY : Sprite.cpp.o

Sprite.i: Sprite.cpp.i

.PHONY : Sprite.i

# target to preprocess a source file
Sprite.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Sprite.cpp.i
.PHONY : Sprite.cpp.i

Sprite.s: Sprite.cpp.s

.PHONY : Sprite.s

# target to generate assembly for a file
Sprite.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Sprite.cpp.s
.PHONY : Sprite.cpp.s

SpriteManager.o: SpriteManager.cpp.o

.PHONY : SpriteManager.o

# target to build an object file
SpriteManager.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SpriteManager.cpp.o
.PHONY : SpriteManager.cpp.o

SpriteManager.i: SpriteManager.cpp.i

.PHONY : SpriteManager.i

# target to preprocess a source file
SpriteManager.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SpriteManager.cpp.i
.PHONY : SpriteManager.cpp.i

SpriteManager.s: SpriteManager.cpp.s

.PHONY : SpriteManager.s

# target to generate assembly for a file
SpriteManager.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/SpriteManager.cpp.s
.PHONY : SpriteManager.cpp.s

glad.o: glad.c.o

.PHONY : glad.o

# target to build an object file
glad.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.o
.PHONY : glad.c.o

glad.i: glad.c.i

.PHONY : glad.i

# target to preprocess a source file
glad.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.i
.PHONY : glad.c.i

glad.s: glad.c.s

.PHONY : glad.s

# target to generate assembly for a file
glad.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.s
.PHONY : glad.c.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... Image.o"
	@echo "... Image.i"
	@echo "... Image.s"
	@echo "... MovingSprite.o"
	@echo "... MovingSprite.i"
	@echo "... MovingSprite.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... SnowBall.o"
	@echo "... SnowBall.i"
	@echo "... SnowBall.s"
	@echo "... Sprite.o"
	@echo "... Sprite.i"
	@echo "... Sprite.s"
	@echo "... SpriteManager.o"
	@echo "... SpriteManager.i"
	@echo "... SpriteManager.s"
	@echo "... glad.o"
	@echo "... glad.i"
	@echo "... glad.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


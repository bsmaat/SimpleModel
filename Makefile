# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/billy/geant/model2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/billy/geant/model2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/opt/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/billy/geant/model2/CMakeFiles /home/billy/geant/model2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/billy/geant/model2/CMakeFiles 0
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
# Target rules for targets named model

# Build rule for target.
model: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 model
.PHONY : model

# fast build rule for target.
model/fast:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/build
.PHONY : model/fast

model.o: model.cc.o

.PHONY : model.o

# target to build an object file
model.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/model.cc.o
.PHONY : model.cc.o

model.i: model.cc.i

.PHONY : model.i

# target to preprocess a source file
model.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/model.cc.i
.PHONY : model.cc.i

model.s: model.cc.s

.PHONY : model.s

# target to generate assembly for a file
model.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/model.cc.s
.PHONY : model.cc.s

src/ActionInitialization.o: src/ActionInitialization.cc.o

.PHONY : src/ActionInitialization.o

# target to build an object file
src/ActionInitialization.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ActionInitialization.cc.o
.PHONY : src/ActionInitialization.cc.o

src/ActionInitialization.i: src/ActionInitialization.cc.i

.PHONY : src/ActionInitialization.i

# target to preprocess a source file
src/ActionInitialization.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ActionInitialization.cc.i
.PHONY : src/ActionInitialization.cc.i

src/ActionInitialization.s: src/ActionInitialization.cc.s

.PHONY : src/ActionInitialization.s

# target to generate assembly for a file
src/ActionInitialization.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ActionInitialization.cc.s
.PHONY : src/ActionInitialization.cc.s

src/DetectorConstruction.o: src/DetectorConstruction.cc.o

.PHONY : src/DetectorConstruction.o

# target to build an object file
src/DetectorConstruction.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorConstruction.cc.o
.PHONY : src/DetectorConstruction.cc.o

src/DetectorConstruction.i: src/DetectorConstruction.cc.i

.PHONY : src/DetectorConstruction.i

# target to preprocess a source file
src/DetectorConstruction.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorConstruction.cc.i
.PHONY : src/DetectorConstruction.cc.i

src/DetectorConstruction.s: src/DetectorConstruction.cc.s

.PHONY : src/DetectorConstruction.s

# target to generate assembly for a file
src/DetectorConstruction.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorConstruction.cc.s
.PHONY : src/DetectorConstruction.cc.s

src/DetectorHit.o: src/DetectorHit.cc.o

.PHONY : src/DetectorHit.o

# target to build an object file
src/DetectorHit.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorHit.cc.o
.PHONY : src/DetectorHit.cc.o

src/DetectorHit.i: src/DetectorHit.cc.i

.PHONY : src/DetectorHit.i

# target to preprocess a source file
src/DetectorHit.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorHit.cc.i
.PHONY : src/DetectorHit.cc.i

src/DetectorHit.s: src/DetectorHit.cc.s

.PHONY : src/DetectorHit.s

# target to generate assembly for a file
src/DetectorHit.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/DetectorHit.cc.s
.PHONY : src/DetectorHit.cc.s

src/ModelRunAction.o: src/ModelRunAction.cc.o

.PHONY : src/ModelRunAction.o

# target to build an object file
src/ModelRunAction.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ModelRunAction.cc.o
.PHONY : src/ModelRunAction.cc.o

src/ModelRunAction.i: src/ModelRunAction.cc.i

.PHONY : src/ModelRunAction.i

# target to preprocess a source file
src/ModelRunAction.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ModelRunAction.cc.i
.PHONY : src/ModelRunAction.cc.i

src/ModelRunAction.s: src/ModelRunAction.cc.s

.PHONY : src/ModelRunAction.s

# target to generate assembly for a file
src/ModelRunAction.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/ModelRunAction.cc.s
.PHONY : src/ModelRunAction.cc.s

src/PrimaryGeneratorAction.o: src/PrimaryGeneratorAction.cc.o

.PHONY : src/PrimaryGeneratorAction.o

# target to build an object file
src/PrimaryGeneratorAction.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/PrimaryGeneratorAction.cc.o
.PHONY : src/PrimaryGeneratorAction.cc.o

src/PrimaryGeneratorAction.i: src/PrimaryGeneratorAction.cc.i

.PHONY : src/PrimaryGeneratorAction.i

# target to preprocess a source file
src/PrimaryGeneratorAction.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/PrimaryGeneratorAction.cc.i
.PHONY : src/PrimaryGeneratorAction.cc.i

src/PrimaryGeneratorAction.s: src/PrimaryGeneratorAction.cc.s

.PHONY : src/PrimaryGeneratorAction.s

# target to generate assembly for a file
src/PrimaryGeneratorAction.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/PrimaryGeneratorAction.cc.s
.PHONY : src/PrimaryGeneratorAction.cc.s

src/SensitiveDetector.o: src/SensitiveDetector.cc.o

.PHONY : src/SensitiveDetector.o

# target to build an object file
src/SensitiveDetector.cc.o:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/SensitiveDetector.cc.o
.PHONY : src/SensitiveDetector.cc.o

src/SensitiveDetector.i: src/SensitiveDetector.cc.i

.PHONY : src/SensitiveDetector.i

# target to preprocess a source file
src/SensitiveDetector.cc.i:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/SensitiveDetector.cc.i
.PHONY : src/SensitiveDetector.cc.i

src/SensitiveDetector.s: src/SensitiveDetector.cc.s

.PHONY : src/SensitiveDetector.s

# target to generate assembly for a file
src/SensitiveDetector.cc.s:
	$(MAKE) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/SensitiveDetector.cc.s
.PHONY : src/SensitiveDetector.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... model"
	@echo "... model.o"
	@echo "... model.i"
	@echo "... model.s"
	@echo "... src/ActionInitialization.o"
	@echo "... src/ActionInitialization.i"
	@echo "... src/ActionInitialization.s"
	@echo "... src/DetectorConstruction.o"
	@echo "... src/DetectorConstruction.i"
	@echo "... src/DetectorConstruction.s"
	@echo "... src/DetectorHit.o"
	@echo "... src/DetectorHit.i"
	@echo "... src/DetectorHit.s"
	@echo "... src/ModelRunAction.o"
	@echo "... src/ModelRunAction.i"
	@echo "... src/ModelRunAction.s"
	@echo "... src/PrimaryGeneratorAction.o"
	@echo "... src/PrimaryGeneratorAction.i"
	@echo "... src/PrimaryGeneratorAction.s"
	@echo "... src/SensitiveDetector.o"
	@echo "... src/SensitiveDetector.i"
	@echo "... src/SensitiveDetector.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


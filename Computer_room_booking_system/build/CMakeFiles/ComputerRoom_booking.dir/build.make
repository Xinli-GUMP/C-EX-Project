# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\cmake-3.27.5-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.27.5-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Documents\C++\MyProjects\Computer_room_booking_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Documents\C++\MyProjects\Computer_room_booking_system\build

# Include any dependencies generated for this target.
include CMakeFiles/ComputerRoom_booking.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ComputerRoom_booking.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ComputerRoom_booking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComputerRoom_booking.dir/flags.make

CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/admin.cpp
CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\admin.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\admin.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\admin.cpp

CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\admin.cpp > CMakeFiles\ComputerRoom_booking.dir\src\admin.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\admin.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\admin.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/file_operator.cpp
CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\file_operator.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\file_operator.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\file_operator.cpp

CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\file_operator.cpp > CMakeFiles\ComputerRoom_booking.dir\src\file_operator.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\file_operator.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\file_operator.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/main.cpp
CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\main.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\main.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\main.cpp

CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\main.cpp > CMakeFiles\ComputerRoom_booking.dir\src\main.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\main.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\main.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/manager.cpp
CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\manager.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\manager.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\manager.cpp

CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\manager.cpp > CMakeFiles\ComputerRoom_booking.dir\src\manager.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\manager.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\manager.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/order.cpp
CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\order.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\order.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\order.cpp

CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\order.cpp > CMakeFiles\ComputerRoom_booking.dir\src\order.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\order.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\order.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/student.cpp
CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\student.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\student.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\student.cpp

CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\student.cpp > CMakeFiles\ComputerRoom_booking.dir\src\student.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\student.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\student.cpp.s

CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/flags.make
CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/includes_CXX.rsp
CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj: F:/Documents/C++/MyProjects/Computer_room_booking_system/src/teacher.cpp
CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj: CMakeFiles/ComputerRoom_booking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj -MF CMakeFiles\ComputerRoom_booking.dir\src\teacher.cpp.obj.d -o CMakeFiles\ComputerRoom_booking.dir\src\teacher.cpp.obj -c F:\Documents\C++\MyProjects\Computer_room_booking_system\src\teacher.cpp

CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.i"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Documents\C++\MyProjects\Computer_room_booking_system\src\teacher.cpp > CMakeFiles\ComputerRoom_booking.dir\src\teacher.cpp.i

CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.s"
	C:\Compiler\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Documents\C++\MyProjects\Computer_room_booking_system\src\teacher.cpp -o CMakeFiles\ComputerRoom_booking.dir\src\teacher.cpp.s

# Object files for target ComputerRoom_booking
ComputerRoom_booking_OBJECTS = \
"CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj" \
"CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj"

# External object files for target ComputerRoom_booking
ComputerRoom_booking_EXTERNAL_OBJECTS =

bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/admin.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/file_operator.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/main.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/manager.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/order.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/student.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/src/teacher.cpp.obj
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/build.make
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/linkLibs.rsp
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/objects1.rsp
bin/ComputerRoom_booking.exe: CMakeFiles/ComputerRoom_booking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable bin\ComputerRoom_booking.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ComputerRoom_booking.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComputerRoom_booking.dir/build: bin/ComputerRoom_booking.exe
.PHONY : CMakeFiles/ComputerRoom_booking.dir/build

CMakeFiles/ComputerRoom_booking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ComputerRoom_booking.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ComputerRoom_booking.dir/clean

CMakeFiles/ComputerRoom_booking.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Documents\C++\MyProjects\Computer_room_booking_system F:\Documents\C++\MyProjects\Computer_room_booking_system F:\Documents\C++\MyProjects\Computer_room_booking_system\build F:\Documents\C++\MyProjects\Computer_room_booking_system\build F:\Documents\C++\MyProjects\Computer_room_booking_system\build\CMakeFiles\ComputerRoom_booking.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ComputerRoom_booking.dir/depend


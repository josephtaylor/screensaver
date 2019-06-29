cmake_minimum_required(VERSION 3.10.2)  # CMake version check
project(screensaver)               # Create project "screensaver"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

find_package(X11 REQUIRED)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES screensaver.c vroot.h screensaver.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(screensaver ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} X11)

install (TARGETS screensaver DESTINATION bin)
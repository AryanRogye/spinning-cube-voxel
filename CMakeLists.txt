cmake_minimum_required(VERSION 3.10)

# Set the project name
project(voxel LANGUAGES C)

# Set the C standard to C11 or newer
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Add include directories
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

# Add your executable
add_executable(build src/main.c src/voxel.c src/renderer.c src/window.c)

# Link SDL2 to your executable
target_link_libraries(build ${SDL2_LIBRARIES})

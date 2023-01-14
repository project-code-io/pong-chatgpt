cmake_minimum_required(VERSION 3.10)
project(pong)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Find SDL2 library
find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)

# Add source files
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Create executable
add_executable(pong ${SRC_FILES})

# Link SDL2 library
target_link_libraries(pong SDL2::SDL2 SDL2_gfx)

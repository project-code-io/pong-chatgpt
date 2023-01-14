cmake_minimum_required(VERSION 3.10)
project(pong)

# Find SDL2 library
find_package(SDL2 REQUIRED)

# Add source files
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Create executable
add_executable(pong ${SRC_FILES})

# Link SDL2 library
target_link_libraries(pong SDL2::SDL2)

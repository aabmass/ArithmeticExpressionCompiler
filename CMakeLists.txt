cmake_minimum_required(VERSION 2.8.11)

project(symbolicmath)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Some variables
set(EXEC_NAME main)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Find sources and headers by globbing
file(GLOB SRC . src/*.cpp)
file(GLOB HEADERS . src/*.h)

# Tell CMake to create the executable
add_executable(${EXEC_NAME} ${SRC})

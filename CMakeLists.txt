cmake_minimum_required(VERSION 2.8.11)

project(symbolicmath)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# All warnings, from stackoverflow
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

# Some variables
set(EXEC_NAME main)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Find sources and headers by globbing
file(GLOB SRC . src/*.cpp)
file(GLOB HEADERS . src/*.h)

# Tell CMake to create the executable
add_executable(${EXEC_NAME} ${SRC})

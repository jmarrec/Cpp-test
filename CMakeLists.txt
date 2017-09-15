project (CppTest)

cmake_minimum_required (VERSION 2.6)

# The version number.
set( CMAKE_VERSION_MAJOR 0 )
set( CMAKE_VERSION_MINOR 1 )
set( CMAKE_VERSION_PATCH 0 )

set( CPPTEST_VERSION "${CMAKE_VERSION_MAJOR}.${CMAKE_VERSION_MINOR}.${CMAKE_VERSION_PATCH}" )

# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
  #"${PROJECT_SOURCE_DIR}/CppTestConfig.h.in"
  #"${PROJECT_BINARY_DIR}/CppTestConfig.h"
  #)
 
# add the binary tree to the search path for include files
# so that we will find CppTestConfig.h
INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/src )

# C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

# add the executable
add_executable(CppTest src/main.cpp)


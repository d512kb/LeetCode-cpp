﻿# CMakeList.txt : CMake project for LeetCode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCode")

# Add source to this project's executable.
add_executable (LeetCode "LeetCode.cpp" "LeetCode.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCode PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.

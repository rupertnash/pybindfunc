# Copyright (C) 2018 Rupert Nash, The University of Edinburgh

cmake_minimum_required(VERSION 3.2)

project(pybindtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Make sure you execute "conan install .." in the build directory
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)

find_package(pybind11 REQUIRED)

# make relocatable binaries
if (APPLE)
  set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
  set(CMAKE_MACOSX_RPATH TRUE)
else()
  set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif()

enable_testing()

pybind11_add_module(example example.cpp interface.cpp)

# add_test(NAME basic
#   COMMAND env PYTHONPATH=${CMAKE_BINARY_DIR}/lib:$$PYTHONPATH python ${CMAKE_SOURCE_DIR}/test.py
#   )

add_test(NAME basic
  COMMAND env PYTHONPATH=${CMAKE_BINARY_DIR}/lib:$PYTHONPATH pytest
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

cmake_minimum_required(VERSION 3.15)

project(obsidian_chest CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (sources
	source/oc.cpp
	)


add_library(obsidian_chest
	${sources}
	)

target_include_directories(obsidian_chest PRIVATE
	include
	)

target_include_directories(obsidian_chest INTERFACE
	include
	)

set_target_properties(obsidian_chest PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
	)

add_subdirectory(tests)

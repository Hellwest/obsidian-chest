cmake_minimum_required(VERSION 3.15)

project(obsidian_chest CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (sources
	main.cpp
	oc.cpp
	)

add_executable(obsidian_test
	${sources}
	)

set_target_properties(obsidian_test PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
	)

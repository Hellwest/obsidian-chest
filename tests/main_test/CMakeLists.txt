project(oc_test CXX)

set(sources
	main.cpp
	)

add_executable(obsidian_test
	${sources}
	)

target_link_libraries(obsidian_test
	obsidian_chest
	)

set_target_properties(obsidian_test PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
	)

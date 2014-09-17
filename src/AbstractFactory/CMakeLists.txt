cmake_minimum_required(VERSION 2.8.11)

project(MyFirstCliSoft)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(
	GLOB_RECURSE
	source_files
	src/*
)

add_executable(
	my_exe
	${source_files}
)
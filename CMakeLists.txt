cmake_minimum_required(VERSION 2.8.11)

project(SelfGoverningShip)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_COMPILER cross/x-tools7h/arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++)
include_directories(library/usr/include/jsoncpp)
include_directories(library/usr/include/python3.4m)
link_directories(library/usr/lib)

# include_directories(/usr/include/jsoncpp)
# include_directories(/usr/include/python3.4m)
# link_directories(/usr/lib)


file(
	GLOB_RECURSE
	source_files
	src/*
)

add_executable(
	my_exe
	${source_files}
)

target_link_libraries(
	my_exe
	jsoncpp
	python3.4m
)
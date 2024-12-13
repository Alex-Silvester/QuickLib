
#Thanks to hapaxia the SelbaWard library for the cmake bits
#https://github.com/Hapaxia/SelbaWard

cmake_minimum_required(VERSION 3.8)
project(QuickLib LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare (
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b
)
FetchContent_MakeAvailable(SFML)

add_library(QuickLib
	src/Button.cpp
)

add_library(QuickLib::QuickLib ALIAS QuickLib)
target_include_directories(QuickLib PUBLIC src)
target_link_libraries(QuickLib PUBLIC sfml-graphics)
target_compile_features(QuickLib PUBLIC cxx_std_11)

if(NOT PROJECT_IS_TOP_LEVEL)
	return()
endif()

option(BUILD_EXAMPLES "build examples" OFF)
if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()


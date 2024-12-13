
#Thanks to hapaxia the SelbaWard library for the cmake bits
#https://github.com/Hapaxia/SelbaWard

cmake_minimum_required(VERSION 3.16)
project(QuickLib LANGUAGES CXX)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics)

add_library(QuickLib
    src/QuickLib/Button.cpp
)
add_library(QuickLib::QuickLib ALIAS QuickLib)
target_include_directories(QuickLib PUBLIC src)
target_link_libraries(QuickLib PUBLIC sfml-graphics)
target_compile_features(QuickLib PUBLIC cxx_std_11)

# Stop configuration if being consumed by a higher level project
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

option(BUILD_EXAMPLES "Build examples" OFF)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()


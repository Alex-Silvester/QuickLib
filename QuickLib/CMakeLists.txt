# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project (QuickLib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare (
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b
)

FetchContent_MakeAvailable(SFML)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)

# Include sub-projects.
set(SOURCE_FILES src/main.cpp src/QuickLib.h src/QuickLib "src/Button.h")
add_executable(QuickLib ${SOURCE_FILES})

target_link_libraries(QuickLib PUBLIC sfml-graphics)

cmake_minimum_required(VERSION 3.14)
set (CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")
project(raylib_cpp_example)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
    endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is the main part:

file(GLOB SOURCES 
    src/*.cpp 
    src/Object/*.cpp
    src/Object/Movable/*.cpp
    src/Object/Pickable/*.cpp
    src/Object/Container/*.cpp
    src/Map/*.cpp
    src/Application/*.cpp
    src/Scene/*.cpp
    src/Mediator/*.cpp
    src/Other/*.cpp
)

include_directories(src)
include_directories(src/Object)
include_directories(src/Object/Movable)
include_directories(src/Object/Pickable)
include_directories(src/Map)
include_directories(src/Application)
include_directories(src/Scene)
include_directories(src/Mediator)

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)
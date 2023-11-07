cmake_minimum_required(VERSION 3.7)

project(Game-of-Life VERSION 1.0)

option(WASM, "Compile to Wasm" OFF)

if(WASM)

endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE src CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

add_executable(game-of-life ${src})
target_link_libraries(game-of-life ${SDL2_LIBRARIES})

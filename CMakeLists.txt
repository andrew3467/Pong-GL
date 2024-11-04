cmake_minimum_required(VERSION 3.29)
project(Pong_GL)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Tungsten)


file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_executable(
        Pong_GL
        ${SRC}
        ${HEADERS}
)

target_link_libraries(
        Pong_GL
        PRIVATE
        Tungsten
)

target_include_directories(
        Pong_GL
        PRIVATE
        src/Pong-GL
        Tungsten/src
)

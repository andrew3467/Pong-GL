cmake_minimum_required(VERSION 3.29)
project(Pong_GL_Game)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(../Tungsten ../bin)


file(GLOB_RECURSE SRC *.cpp)
file(GLOB_RECURSE HEADERS *.h)

add_executable(
        Pong_GL_Game
        ${SRC}
        ${HEADERS}
)

target_link_libraries(
        Pong_GL_Game
        PRIVATE
        Tungsten
)

target_include_directories(
        Pong_GL_Game
        PRIVATE
        Pong-GL
        ../Tungsten/src
)

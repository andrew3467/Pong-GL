set(CMAKE_CXX_STANDARD 23)
cmake_minimum_required(VERSION 3.29)

project(Pong_GL)


find_package(spdlog CONFIG REQUIRED)


add_subdirectory(src)
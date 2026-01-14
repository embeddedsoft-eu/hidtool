cmake_minimum_required(VERSION 3.15)
project(hidtool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hidtool main.cpp)

target_include_directories(hidtool PRIVATE
    /mingw64/include
)

target_link_directories(hidtool PRIVATE
    /mingw64/lib
)

target_link_libraries(hidtool PRIVATE
    hidapi
)

cmake_minimum_required(VERSION 3.5.1)
project (tetris)

include_directories(/control/headers /model/headers /view/headers)

set(SOURCES /control/src /model/src /view/src)

add_executable(tetris main.cpp)

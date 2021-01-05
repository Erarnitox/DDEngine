cmake_minimum_required(VERSION 3.0)

project(gameengine)

add_executable(gameengine main.cpp)

install(TARGETS gameengine RUNTIME DESTINATION bin)

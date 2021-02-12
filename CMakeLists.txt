cmake_minimum_required(VERSION 3.8)

project(gameengine)
add_library(
	${PROJECT_NAME} SHARED
	./engine/engine.cpp 
	./engine/Display.cpp 
	./engine/Shader.cpp 
	./engine/Mesh.cpp 
	./engine/Texture.cpp 
	./engine/obj_loader.cpp)


find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
message(FATAL_ERROR "OpenGL not found!")
endif(NOT OPENGL_FOUND)
target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL)


find_package(GLEW REQUIRED)
if(NOT GLEW_FOUND)
message(FATAL_ERROR "GLEW not found!")
endif(NOT GLEW_FOUND)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)


find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
message(FATAL_ERROR "SDL2 not found!")
endif(NOT SDL2_FOUND)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)


find_package(assimp CONFIG REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIRS})
link_directories(${ASSIMP_LIBRARY_DIRS})

add_executable(
	sandbox
	./game/Sandbox.cpp
)

target_link_libraries(sandbox PRIVATE ${PROJECT_NAME})







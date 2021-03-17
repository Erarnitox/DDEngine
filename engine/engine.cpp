#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

#include "engine.h"
	
namespace tox{
	App::App(int width, int height, std::string title)
	:camera(glm::vec3(0, 0, -3), 90.0f, 800.0f/600.0f, 0.001f, 1000.0f),
	screen(width, height, title){}
	
	App::~App(){}
	
	void App::init(){
		this->Start();
	
		while(!screen.isClosed){
			this->screen.startFrame();
			this->Update();
			this->GUI();
			this->screen.endFrame();
		}
	}
}

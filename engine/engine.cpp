#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <chrono>

#include "engine.h"
	
//Timing:
static std::chrono::duration<float> deltaTime;

//GameObject List:
static std::vector<GameObject*> objects;

float Time::deltaTimeSec(){
	return deltaTime.count();
}

ImGuiIO io;

namespace drop{
	Camera App::MainCamera{glm::vec3(0, 0, -3), 90.0f, 800.0f/600.0f, 0.001f, 1000.0f};
	
	App::App(int width, int height, std::string title)
	:screen(width, height, title){}
	
	App::~App(){}
	
	void App::init(){
		io = this->screen.getIO();
		this->Start();
		auto lastTime = std::chrono::high_resolution_clock::now();
		auto tmpTime  = lastTime;
		
		while(!screen.isClosed){
			//Calculate Time since last Frame:
			tmpTime   = std::chrono::high_resolution_clock::now();
			deltaTime = tmpTime - lastTime;
			lastTime  = tmpTime;
	
			this->screen.startFrame();
			
			this->Update();
			this->DrawGameObjects();
			this->GUI();
			
			this->screen.startGUI();
			this->FullScreenUI();
			this->screen.endGUI();
			
			this->screen.endFrame();
		}
	}
	
	void App::DrawGameObjects(){
		for(unsigned i{}; i<objects.size(); ++i){
			if(objects[i]->isActive()) objects[i]->_Draw();
		}
	}
}


void Instatiate(GameObject& obj){
	objects.emplace_back(&obj);
}

ImGuiIO& getIO(){
	
}

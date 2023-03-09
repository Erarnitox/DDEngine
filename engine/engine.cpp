#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <chrono>

#include "engine.h"
	
//Timing:
static std::chrono::duration<float> deltaTime;
static constexpr unsigned FPS{ 30 };
static constexpr unsigned MAX_ITERATIONS{ 10 };
static constexpr float FRAME_LENGTH{ 1.0f/FPS };

//GameObject List:
static std::vector<GameObject*> objects;

float Time::deltaTimeSec(){
	auto tmp{deltaTime.count()};
	return (tmp < 0.15f ? 0.15f : tmp);
}

namespace drop{
	Camera App::MainCamera{ Vector3(0, 0, -3), 90.0f, 16.0f/9, 0.001f, 1000.0f };
	
	App::App(int width, int height, std::string title)
	:screen(width, height, title){}
	
	App::~App(){}
	
	void App::init(){
		
		this->Start();
		auto lastTime = std::chrono::high_resolution_clock::now();
		auto tmpTime  = lastTime;
		
		float cumulativeTime{0};
		
		while(!screen.isClosed){
			//Calculate Time since last Frame:
			tmpTime   = std::chrono::high_resolution_clock::now();
			deltaTime = tmpTime - lastTime;
			
			cumulativeTime += Time::deltaTimeSec();
			lastTime  = tmpTime;
	
			this->screen.startFrame();
			
			this->Update();
			
			while(cumulativeTime > FRAME_LENGTH){
				unsigned iterations{0};
				this->FixedUpdate();
				cumulativeTime -= FRAME_LENGTH;
				if(++iterations > MAX_ITERATIONS){
					break;
				}
			}
			
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

void Instantiate(GameObject& obj){
	objects.emplace_back(&obj);
}

void Destroy(GameObject& obj){
	//remove object from queue
}

bool isKeyDown(int key){
	return ImGui::IsKeyDown(key);
}

bool isKeyPressed(int key){
	return ImGui::IsKeyPressed(key);
}

bool isKeyReleased(int key){
	return ImGui::IsKeyReleased(key);
}

float mouseMovedX(){
	return ImGui::GetMouseDragDelta().x;
}

float mouseMovedY(){
	return ImGui::GetMouseDragDelta().y;
}

void toggleCursor(){
	static bool isShown{true};
	
	if(isShown){
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}else{
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	
	isShown = !isShown;
}



float approach(float destination, float current, float speed){
	float dif{destination-current};
	
	if(dif > speed) return current + speed;
	else return current - speed;
}

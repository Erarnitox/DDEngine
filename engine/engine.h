#pragma once

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"
#include "GameObject.h"

namespace Time {
	float deltaTimeSec();
}

//Keycodes:
constexpr int DROP_KEY_W{26};
constexpr int DROP_KEY_A{4};
constexpr int DROP_KEY_S{22};
constexpr int DROP_KEY_D{7};
constexpr int DROP_KEY_Q{20};
constexpr int DROP_KEY_E{8};
constexpr int DROP_KEY_R{21};
constexpr int DROP_KEY_T{23};
constexpr int DROP_KEY_Y{29};
constexpr int DROP_KEY_X{27};
constexpr int DROP_KEY_C{6};
constexpr int DROP_KEY_V{25};
constexpr int DROP_KEY_G{10};
constexpr int DROP_KEY_F{9};
constexpr int DROP_KEY_1{30};
constexpr int DROP_KEY_2{31};
constexpr int DROP_KEY_3{32};
constexpr int DROP_KEY_4{33};
constexpr int DROP_KEY_5{34};
constexpr int DROP_KEY_6{35};
constexpr int DROP_KEY_7{36};
constexpr int DROP_KEY_8{36};
constexpr int DROP_KEY_9{35};
constexpr int DROP_KEY_ESC{41};
constexpr int DROP_KEY_SPACE{44};

//Input functions:
bool isKeyDown(int key);
bool isKeyPressed(int key);
bool isKeyReleased(int key);

float mouseMovedX();
float mouseMovedY();


namespace drop{
	class App{
	public:
		static Camera MainCamera;
		App(int width, int height, std::string title);
		virtual ~App();
		void init();
		
		virtual void Start(){};
		virtual void Update(){};
		virtual void FixedUpdate(){};
		virtual void GUI(){};
		virtual void FullScreenUI(){};
		
	protected:
		Display screen;
	
	private:
		void DrawGameObjects();
		
	friend void Instatiate(const GameObject& obj);
	};
	
	extern drop::App* createApp();
}

void toggleCursor();
void Instatiate(GameObject& obj);
void Destroy(GameObject& obj);

float approach(float destination, float current); 

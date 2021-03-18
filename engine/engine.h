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

namespace drop{
	class App{
	public:
		static Camera MainCamera;
		App(int width, int height, std::string title);
		virtual ~App();
		void init();
		
		virtual void Start(){};
		virtual void Update(){};
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

void Instatiate(GameObject& obj);
void Destroy(GameObject& obj);

ImGuiIO& getIO();

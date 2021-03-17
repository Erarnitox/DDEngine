#pragma once

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"

namespace tox{
	class App{
	public:
		App(int width, int height, std::string title);
		virtual ~App();
		void init();
		
		virtual void Start(){};
		virtual void Update(){};
		virtual void GUI(){};
		
	protected:
		Camera  camera;
		Display screen;
	};
	
	extern tox::App* createApp();
}

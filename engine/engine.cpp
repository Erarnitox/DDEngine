#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

#include "toxengine.h"

#include "Display.hpp"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"
	
namespace tox{
	
	int start(){
		Display dist(800, 600, "Title!");
	
		Shader basicShader("../res/shaders/basicShader");
	
		vertex verteces[]{
			{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
			{glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec2(0.5f, 1.0f)},
			{glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)}
		};
	
		unsigned indeces[]{0, 1, 2};
	
		Mesh mesh(verteces, sizeof(verteces)/sizeof(vertex), 
				   indeces, sizeof(indeces)/sizeof(indeces[0]));
	
		Mesh suzanneObj("../res/models/suzanne.obj");
	
		Texture simpleTexture("../res/textures/Wall/albedo.png");
	
		Transform simpleTrans;
	
		Camera cam(glm::vec3(0, 0, -3), 90.0f, 800.0f/600.0f, 0.001f, 1000.0f);
	
		float count{};
	
		while(!dist.isClosed){
			dist.startFrame();
		
			simpleTrans.getPos().z = sinf(count*0.2f);
			simpleTrans.getRot().y = count*0.3f;
		
			basicShader.Bind();
			basicShader.Update(simpleTrans, cam);
			simpleTexture.Bind();
		
			//mesh.Draw();
			suzanneObj.Draw();
		
			dist.endFrame();
			count += 0.1f;
		}
		return 0;
	}
}

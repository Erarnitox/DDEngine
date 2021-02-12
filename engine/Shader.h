#pragma once

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader{
private:
	static const unsigned NUM_SHADERS = 2;
	Shader& operator=(const Shader& other) = delete;
	
	enum{
		TRANSFORM_U,
		NUM_UNIFORMS
	};
	
	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
	
public:
    Shader(const std::string& fileName);
    ~Shader();
	
	void Bind();
	void Update(const Transform& transform, const Camera& cam);
};

#pragma once

#include <string>
#include <GL/glew.h>

class Texture{
private:
	GLuint texture;
public:
    Texture(const std::string& fileName);
    ~Texture();
	
	Texture(const Texture& other) = delete;
    Texture& operator=(const Texture& other) = delete;
	
	void Bind(unsigned unit = 0);
};


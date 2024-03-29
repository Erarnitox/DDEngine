#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cassert>
#include <iostream>

Texture::Texture(const std::string& fileName){
	int width, height;
	int numComponents;
	
	unsigned char* imgData{ stbi_load(fileName.c_str(), &width, &height, &numComponents, 4) };
	
	if(!imgData){
		std::cerr << "Error: was not able to load image: " << fileName << std::endl;
	}
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, 
	GL_UNSIGNED_BYTE, imgData);
	
	stbi_image_free(imgData);
}

Texture::~Texture(){
	glDeleteTextures(1, &texture);
}

void Texture::Bind(unsigned unit){
	assert(unit < 32);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texture);
}

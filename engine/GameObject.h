#pragma once

#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Shader.h"

class GameObject{
private:
	static size_t count;
	size_t id;
	
	Mesh mesh;
	Texture texture;
	Shader shader;
	
	bool active{true};
	
public:
	Transform transform;
	
    GameObject(std::string pathToMesh, std::string pathToTexture, const Shader& shader);
    //GameObject(const GameObject& other);

    ~GameObject();
    //GameObject& operator=(const GameObject& other);

    //bool operator==(const GameObject& other) const;
    //bool operator!=(const GameObject& other) const;
	
	void setActive(bool active);
	bool isActive();
	void _Draw();
};

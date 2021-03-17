#pragma once

#include "Mesh.h"
#include "Texture.h"

class GameObject{
private:
	//Mesh mesh;
	//Texture texture;
	
public:

    GameObject();
    GameObject(const GameObject& other);

    ~GameObject();
    GameObject& operator=(const GameObject& other);

    bool operator==(const GameObject& other) const;
    bool operator!=(const GameObject& other) const;
};

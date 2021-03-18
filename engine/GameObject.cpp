#include "GameObject.h"
#include "engine.h"

size_t GameObject::count{0};

GameObject::GameObject(std::string pathToMesh, std::string pathToTexture, const Shader& shader)
	:id{++count}, mesh{pathToMesh}, texture{pathToTexture}, shader{ shader }, transform{}{

}

/*
GameObject::GameObject(const GameObject& other){

}*/

GameObject::~GameObject(){

}

/*
GameObject& GameObject::operator=(const GameObject& other){

}

bool GameObject::operator==(const GameObject& other) const {

}

bool GameObject::operator!=(const GameObject& other) const {

}*/

void GameObject::setActive(bool active){
	this->active = active;
}

bool GameObject::isActive(){
	return this->active;
}

void GameObject::_Draw(){
	this->shader.Bind();
	this->shader.Update(this->transform, drop::App::MainCamera);
	this->texture.Bind();
	this->mesh.Draw();
}

#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform{
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
	
public:
	
	Transform(
		const glm::vec3& pos   = glm::vec3{ 0.0f, 0.0f, 0.0f }, 
		const glm::vec3& rot   = glm::vec3{ 0.0f, 0.0f, 0.0f }, 
		const glm::vec3& scale = glm::vec3{ 1.0f, 1.0f, 1.0f }
	)
	:pos{pos}, rot{rot}, scale{scale} {
		
	}
	~Transform() = default;
   
	glm::vec3& getPos(){ return pos; };
	glm::vec3& getRot(){ return rot; };
	glm::vec3& getScale(){ return scale; };
   
	void setPos(const glm::vec3& pos){ this->pos = pos; }
	void setRot(const glm::vec3& rot){ this->rot = rot; }
	void setScale(const glm::vec3& scale){ this->scale = scale; }

	glm::mat4 getModel() const{
		glm::mat4 posMatrix{ glm::translate(pos) };
		glm::mat4 rotXMatrix{ glm::rotate(rot.x, glm::vec3(1, 0 , 0)) };
		glm::mat4 rotYMatrix{ glm::rotate(rot.y, glm::vec3(0, 1 , 0)) };
		glm::mat4 rotZMatrix{ glm::rotate(rot.z, glm::vec3(0, 0 , 1)) };
		glm::mat4 scaleMatrix{ glm::scale(scale) };
		
		glm::mat4 rotMatrix{ rotZMatrix * rotYMatrix * rotXMatrix };
		
		return posMatrix * rotMatrix * scaleMatrix;
	}
};


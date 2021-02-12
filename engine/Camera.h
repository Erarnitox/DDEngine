#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera{
private:
	glm::mat4 mPerspective;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
	
public:
	Camera(const glm::vec3& pos, float fov, float aspect, 
		   float cNear, float cFar){
		mPerspective = glm::perspective(fov, aspect, cNear, cFar);
		position = pos;
		
		forward = glm::vec3(0, 0, 1);
		up = glm::vec3(0, 1, 0);
	}
	
	glm::mat4 getViewProjection() const{
		return mPerspective * glm::lookAt(position, position + forward, up);
	}
	
};

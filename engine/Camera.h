#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera{
private:
	glm::mat4 mPerspective;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
	glm::mat4 rotation;
	
	float fov;
	float aspect;
	float cNear;
	float cFar;
	
	float pitch;
	float yaw;
	
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float cNear, float cFar)
	:fov{fov}, aspect{aspect}, cNear{cNear}, cFar{cFar}{
		mPerspective = glm::perspective(fov, aspect, cNear, cFar);
		position = pos;
		forward = glm::vec3(0, 0, 1);
		up = glm::vec3(0, 1, 0);
		rotation = glm::mat4(1.0f);
		pitch = 0;
		yaw = 0;
	}
	
	void rotate(float pitch, float yaw){
		this->pitch = pitch;
		this->yaw = yaw;
		glm::mat4 rotPitch{ glm::rotate(this->pitch, glm::vec3(1, 0, 0)) };
		glm::mat4 rotYaw{ glm::rotate(this->yaw, glm::vec3(0, 1, 0)) };
		rotation = rotPitch * rotYaw;
	}
	
	void setPerspective(float fieldOfView, float aspectRatio=16.0f/9.0f, float near=0.1f, float far=1000.0f){
		mPerspective = glm::perspective(fieldOfView, aspectRatio, near, far);
	}
	
	void setFOV(float degree){
		mPerspective = glm::perspective(degree, aspect, cNear, cFar);
	}
	
	void setNear(float near){
		mPerspective = glm::perspective(fov, aspect, near, cFar);
	}
	
	void setFar(float far){
		mPerspective = glm::perspective(fov, aspect, cNear, far);
	}
	
	void setAspect(float aspectRatio){
		mPerspective = glm::perspective(fov, aspectRatio, cNear, cFar);
	}
	
	glm::vec3& getPos(){
		return position;
	}
	
	glm::mat4 getViewProjection() const{
		return mPerspective * rotation * glm::lookAt(position, position + forward, up);
	}
	
};

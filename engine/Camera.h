#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Vector3.h"
#include <math.h>

class Camera{
private:
	glm::mat4 mPerspective;
	Vector3 position;
	Vector3 forward;
	Vector3 up;
	glm::mat4 rotation;
	
	float fov;
	float aspect;
	float cNear;
	float cFar;
	
	float pitch;
	float yaw;
	float gravity{0.6f};
	float speed{1.0f};
	float mouseSensitivity{0.01f};
	float jumpTime{1.0f};
	
	Vector3 velocity;
	Vector3 velocityGoal;
	
	
public:
	bool isGrounded{true};
	float cooldown{0.0f};
	
	Camera(const Vector3& pos, float fov, float aspect, float cNear, float cFar)
	:fov{fov}, aspect{aspect}, cNear{cNear}, cFar{cFar}{
		mPerspective = glm::perspective(fov, aspect, cNear, cFar);
		position = pos;
		forward = Vector3(0, 0, 1);
		up = Vector3(0, 1, 0);
		rotation = glm::mat4(1.0f);
		pitch = 0;
		yaw = 0;
	}
	
	void deltaRotate(float pitch, float yaw){
		this->pitch += pitch*mouseSensitivity;
		this->yaw += yaw*mouseSensitivity;
		
		if(this->pitch > 89.0f){
			this->pitch = 89.0f;
		}else if(this->pitch < -89.0f){
			this->pitch = -89.0f;
		}
		
		while(this->yaw < -180){
			this->yaw += 360;
		}
		
		while(this->yaw > 180){
			this->yaw -= 360;
		}
		
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
	
	Vector3& getPos(){
		return position;
	}
	
	Vector3& getVelocity(){
		return velocity;
	}
	
	Vector3& getVelocityGoal(){
		return velocityGoal;
	}
	
	glm::mat4 getViewProjection() const{
		return mPerspective * rotation * glm::lookAt(position.toGlm(), (position + forward).toGlm(), up.toGlm());
	}
	
	void setVelocity(const Vector3& velocity){
		this->velocity = velocity;
	}
	
	float approach(float goal, float current, float speed){
		float dif{goal-current};
		
		if(dif > speed){
			return current + speed;
		}
		if(dif < -speed){
			return current - speed;
		}
		
		return goal;
	}
	
	void UpdatePosition(float delta){
		float scaledSpeed{speed*delta};
		
		velocity.x = approach(velocityGoal.x, velocity.x, scaledSpeed);
		velocity.z = approach(velocityGoal.z, velocity.z, scaledSpeed);
		
		Vector3 right{up.crossProduct(forward)};
		
		velocity = forward*velocity.z + right*velocity.x + up*velocity.y;
		
		//gravity:
		if(position.y > 0){
			velocity.y -= gravity * delta;
			isGrounded = false;
		}
		
		//update Position:
		position = position + (velocity * delta);
		
		if(cooldown > 0.0f) 
			cooldown - delta;
			
		//fix to ground:
		if(position.y < 0){ 
			position.y = 0.1f;
			isGrounded = true;
		}else if(position.y > 0.2f){
			cooldown = jumpTime;
		}
	}
	
};

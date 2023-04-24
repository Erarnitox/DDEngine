#include "Vector3.h"
#include <math.h>


Vector3::Vector3(glm::vec3 org):x{org.x}, y{org.y}, z{org.z} {}

Vector3::Vector3(float x, float y, float z):x{x}, y{y}, z{z}{}

float Vector3::magnitude() const{
	return sqrt(squareMagnitude());
}

float Vector3::squareMagnitude() const{
	return (x*x + y*y + z*z);
}

Vector3 Vector3::add(const Vector3& other) const{
	return Vector3 {
		this->x + other.x,
		this->y + other.y,
		this->z + other.z
	};
}

Vector3 Vector3::scale(const float& scalar)const{
	return Vector3 {
		this->x * scalar,
		this->y * scalar,
		this->z * scalar
	};
}

Vector3 Vector3::divide(const float& div) const{
	return Vector3 {
		this->x / div,
		this->y / div,
		this->z / div
	};
}


Vector3 Vector3::sub(const Vector3& other) const{
	return Vector3 {
		this->x - other.x,
		this->y - other.y,
		this->z - other.z
	};
}

Vector3 Vector3::operator+(const Vector3& other) const{
	return this->add(other);
}

Vector3 Vector3::operator-(const Vector3& other) const{
	return this->sub(other);
}

Vector3 Vector3::operator*(const float& scalar) const{
	return this->scale(scalar);
}

Vector3 Vector3::operator/(const float& div) const{
	return this->divide(div);
}

Vector3 Vector3::normalize() const{
	return ((*this) / this->magnitude());
}

float Vector3::dotProduct(const Vector3& other) const{
	return ( 
		  this->x * other.x
		+ this->y * other.y
		+ this->z * other.z
	);
}

Vector3 Vector3::vectorTo(const Vector3& other) const{
	return other - *this;
}

bool Vector3::isBehind(const Vector3& other, const float& threshold) const{
	return (other.vectorTo(*this).dotProduct(other) < -threshold);
}

glm::vec3 Vector3::toGlm() const{
	return glm::vec3(x, y, z);	
}

void Vector3::operator=(const Vector3& other){
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3 Vector3::crossProduct(const Vector3& other) const{
	return Vector3{
		y*other.z - z*other.y,
		z*other.x - x*other.z,
		y*other.y - y*other.x
	};
}





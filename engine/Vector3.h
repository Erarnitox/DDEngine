#ifndef VECTOR3_H
#define VECTOR3_H

#include <glm/vec3.hpp>

class Vector3{
public:
	float x, y, z;
	
	Vector3(float x = 0, float y = 0, float z = 0);
	Vector3(glm::vec3 org);
	
	float magnitude() const;
	float squareMagnitude() const;
	Vector3 add(const Vector3& other) const;
	Vector3 sub(const Vector3& other) const;
	Vector3 scale(const float& scalar) const;
	Vector3 divide(const float& div) const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const float& scalar) const;
	Vector3 operator/(const float& div) const;
	Vector3 normalize() const;
	void operator=(const Vector3& other);
	float dotProduct(const Vector3& other) const;
	Vector3 crossProduct(const Vector3& other) const;
	Vector3 vectorTo(const Vector3& other) const;
	bool isBehind(const Vector3& other, const float& threshold = 0.5f) const;
	glm::vec3 toGlm() const;
};

#endif

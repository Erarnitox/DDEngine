#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
#include <vector>
#include <assimp/Importer.hpp>

#include "obj_loader.h"

typedef struct{
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
} vertex;


class Mesh{
private:
	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};
	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned drawCount;
	
	void initMesh(const IndexedModel& model);
	
public:
	Mesh(vertex* verteces, unsigned numVerts, unsigned* indices, unsigned numIds);
	Mesh(const std::string& fileName);
    ~Mesh();
	Mesh(const Mesh& other) = delete;
    Mesh& operator=(const Mesh& other) = delete;
	
	void Draw();
	static bool wireframe;
};


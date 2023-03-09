#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Texture.h"

struct baseMesh{
	unsigned numIndices;
	unsigned baseVertex;
	unsigned baseIndex;
	unsigned matIndex;
	
	baseMesh(){
		numIndices = 0;
		baseVertex = 0;
		baseIndex  = 0;
		matIndex   = 0;
	}
};

class Mesh {
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
	
	std::vector<baseMesh> meshes;
	std::vector<Texture*> textures;
	std::vector<unsigned> indices;
	
	std::vector<glm::vec3> pos;
	std::vector<glm::vec2> texCoord;
	std::vector<glm::vec3> normal;
	
	void initFromScene(const aiScene* scene, const std::string& fileName);
	void countVerticesAndIndices(const aiScene* scene, unsigned& numVerts, unsigned& numIndices);
	void initSingleMesh(const aiMesh* mesh);
	void initAllMeshes(const aiScene* scene);
	void initMaterials(const aiScene* scene, const std::string& fileName);
	void populateBuffers();
	
public:
	Mesh(const std::string& fileName);
    ~Mesh();
	Mesh(const Mesh& other) = delete;
    Mesh& operator=(const Mesh& other) = delete;
	
	void Draw();
};


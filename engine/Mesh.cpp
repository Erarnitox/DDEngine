#include "Mesh.h"

Mesh::Mesh(const std::string& fileName){
	glGenVertexArrays(1, &this->vertexArrayObject);
	glBindVertexArray(this->vertexArrayObject);
	
	glGenBuffers(sizeof(this->vertexArrayBuffers)/sizeof(this->vertexArrayBuffers[0]), this->vertexArrayBuffers);
	
	bool ret{ false };
	Assimp::Importer importer;
	
	const aiScene* scene{ importer.ReadFile(fileName.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices) };
	
	this->initFromScene(scene, fileName);
	
	glBindVertexArray(0);
}

void Mesh::countVerticesAndIndices(const aiScene* scene, unsigned& numVerts, unsigned& numIndices) {
	for(unsigned i{ 0 }; i < this->meshes.size(); ++i) {
		this->meshes[i].matIndex = scene->mMeshes[i]->mMaterialIndex;
		this->meshes[i].numIndices = scene->mMeshes[i]->mNumFaces * 3;
		this->meshes[i].baseVertex = numVerts;
		this->meshes[i].baseIndex = numIndices;
		
		numVerts += scene->mMeshes[i]->mNumVertices;
		numIndices += this->meshes[i].numIndices;
	}
}

void Mesh::reserveSpace(unsigned numVertices, unsigned numIndices) {
    this->pos.reserve(numVertices);
    this->normal.reserve(numVertices);
    this->texCoord.reserve(numVertices);
    this->indices.reserve(numIndices);
    //m_Bones.resize(numVertices);
}

void Mesh::initSingleMesh(const aiMesh* mesh){
	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);
	
	for( unsigned i{ 0 }; i < mesh->mNumVertices; ++i){
		const aiVector3D& pPos{ mesh->mVertices[i] };
		const aiVector3D& pNormal{ mesh->mNormals[i]};
		const aiVector3D& pTextCord{ mesh->HasTextureCoords(0) ? mesh->mTextureCoords[0][i] : Zero3D };
		
		
		this->pos.push_back(glm::vec3(pPos.x, pPos.y, pPos.z));
		this->texCoord.push_back(glm::vec2(pTextCord.x, pTextCord.y)),
		this->normal.push_back(glm::vec3(pNormal.x, pNormal.y, pNormal.z));
		
	}
	
	for( unsigned i{ 0 }; i < mesh->mNumFaces; ++i){
		const aiFace& face{ mesh->mFaces[i] };
		
		this->indices.push_back(face.mIndices[0]);
		this->indices.push_back(face.mIndices[1]);
		this->indices.push_back(face.mIndices[2]);
	}
}

void Mesh::initAllMeshes(const aiScene* scene) {
	for(unsigned i{ 0 }; i < this->meshes.size(); ++i){
		initSingleMesh(scene->mMeshes[i]);
	}
}

void Mesh::initMaterials(const aiScene* scene, const std::string& fileName){
	std::string::size_type slashIndex{ fileName.find_last_of("/") };
	std::string dir;
	
	if (slashIndex == std::string::npos) {
		dir = std::string(".");
	} else if (slashIndex == 0) {
		dir = std::string("/");
	} else {
		dir = fileName.substr(0, slashIndex);
	}
		
	for(unsigned i{ 0 }; i < scene->mNumMaterials; ++i){
		const aiMaterial* pMaterial{ scene->mMaterials[i] };
		
		this->textures[i] = NULL;
		
		if(pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
			aiString path;
			
			if(pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
				std::string p(path.data);
				
				if(p.substr(0, 2) == ".\\") {
					p = p.substr(2, p.size()-2);
				}
				
				std::string fullPath = dir + "/" + p;
				
				this->textures[i] = new Texture(fullPath.c_str());
			}
		}
	}
}

void Mesh::populateBuffers()
{
	// position
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->pos[0]) * this->pos.size(), &this->pos[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	// tex coord location
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->texCoord[0]) * this->texCoord.size(), &this->texCoord[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	// normal location
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->normal[0]) * this->normal.size(), &this->normal[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices[0]) * this->indices.size(), &this->indices[0], GL_STATIC_DRAW);

}

void Mesh::initFromScene(const aiScene* scene, const std::string& fileName){
	this->meshes.resize(scene->mNumMeshes);
	this->textures.resize(scene->mNumMaterials);
	
	unsigned numVerts{ 0 };
	unsigned numIndices{ 0 };
	
	countVerticesAndIndices(scene, numVerts, numIndices);
	
	initAllMeshes(scene);
	
	initMaterials(scene, fileName);
	populateBuffers();
	
	return;
}

void Mesh::clear()
{
    if (this->vertexArrayBuffers[0] != 0) {
        glDeleteBuffers(sizeof(
			this->vertexArrayBuffers)/sizeof(this->vertexArrayBuffers[0]),
			this->vertexArrayBuffers
		);
    }

    if (this->vertexArrayObject != 0) {
        glDeleteVertexArrays(1, &this->vertexArrayObject);
        this->vertexArrayObject = 0;
    }
}

Mesh::~Mesh(){
	this->clear();
}

void Mesh::Draw(){
	glBindVertexArray(vertexArrayObject);
	
	for(unsigned i{ 0 }; i < this->meshes.size(); ++i) {
		unsigned matIndex{ this->meshes[i].matIndex };
		
		if(this->textures[matIndex])
			this->textures[matIndex]->Bind(GL_TEXTURE0);
		
		glDrawElementsBaseVertex(GL_TRIANGLES,
			this->meshes[i].numIndices,
			GL_UNSIGNED_INT,
			(void*)(sizeof(unsigned) * this->meshes[i].baseIndex),
			this->meshes[i].baseVertex
		  );
	}
	
	glBindVertexArray(0);
}

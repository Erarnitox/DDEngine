#include "Mesh.h"

Mesh::Mesh(const std::string& fileName){
	//Assimp::Importer importer;
	//importer.ReadFile(fileName, aiProcess_Triangulate);
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	initMesh(model);
}

Mesh::Mesh(vertex* verteces, unsigned numVerts, unsigned* indeces, unsigned numIds){
	IndexedModel model;
	
	for(unsigned i{0}; i < numVerts; ++i){
		model.positions.push_back(verteces[i].pos);
		model.texCoords.push_back(verteces[i].texCoord);
		model.normals.push_back(verteces[i].normal);
	}
	
	for(unsigned i{0}; i < numIds; ++i){
		model.indices.push_back(indeces[i]);
	}
	
	
	initMesh(model);
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::Draw(){
	glBindVertexArray(vertexArrayObject);
	
	//glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	
	glBindVertexArray(0);
}


void Mesh::initMesh(const IndexedModel& model){
	drawCount = model.indices.size();
	
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);
	
	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.positions[0]), 
	&model.positions[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size()*sizeof(model.texCoords[0]), 
	&model.texCoords[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size()*sizeof(model.normals[0]), 
	&model.normals[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size()*sizeof(model.indices[0]), 
	&model.indices[0], GL_STATIC_DRAW);
	
	glBindVertexArray(0);
}

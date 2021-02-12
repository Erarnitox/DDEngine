#include "Shader.h"

#include <iostream>
#include <fstream>

static std::string LoadShader(const std::string& fileName){
	std::ifstream file;
	file.open(fileName);
	
	std::string output;
	std::string line;
	
	if(file.is_open()){
		while(file.good()){
			getline(file, line);
			output.append(line+"\n");
			std::cout << line << std::endl;
		}
	}else{
		std::cerr << "unable to load shader: " << fileName << std::endl;
	}
	return output;
}

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, 
const std::string& errorMessage){
	 GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

static GLuint CreateShader(const std::string& text, unsigned type){
	GLuint shader = glCreateShader(type);

    if(shader == 0)
		std::cerr << "Error compiling shader type " << type << std::endl;

    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();

    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, 
    "Error compiling shader!");

    return shader;
}

Shader::Shader(const std::string& fileName){
	program = glCreateProgram();
	shaders[0] = CreateShader(LoadShader(fileName+".vert"), GL_VERTEX_SHADER);
	
	shaders[1] = CreateShader(LoadShader(fileName+".frag"), GL_FRAGMENT_SHADER);
	
	for(unsigned i{0}; i < NUM_SHADERS; ++i){
		glAttachShader(program, shaders[i]);
	}
	
	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");
	glBindAttribLocation(program, 2, "normal");
	
	glLinkProgram(program);
	checkShaderError(program, GL_LINK_STATUS, true, 
		"Error: Program failed to link! ");
	
	glValidateProgram(program);
	checkShaderError(program, GL_VALIDATE_STATUS, true,
		"Error: Program invalid! ");
	
	uniforms[TRANSFORM_U] = glGetUniformLocation(program, "transform");
}

Shader::~Shader(){
	for(unsigned i{0}; i < NUM_SHADERS; ++i){
		glDetachShader(program, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(program);
}

void Shader::Bind(){
	glUseProgram(program);
}

void Shader::Update(const Transform& transform, const Camera& cam){
	glm::mat4 model = cam.getViewProjection() * transform.getModel();
	glUniformMatrix4fv(uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

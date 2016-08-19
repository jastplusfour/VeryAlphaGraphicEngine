#pragma once

#include <gl\glew.h>
#include <string>
#include <iostream>
#include <fstream>

class Shader
{
public:
	Shader(const std::string& fileName);
	virtual ~Shader();
	void Bind();

private:
	static const unsigned int NUM_SHADERS  = 2;
	static const unsigned int NUM_UNIFORMS = 2;
	
	GLuint m_shaderProgram;
	GLuint m_Shaders[NUM_SHADERS];
	//GLuint m_Uniforms[NUM_UNIFORMS];

	std::string loadShader(const std::string& fileName);
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint createShader(const std::string& text, unsigned int type);
};
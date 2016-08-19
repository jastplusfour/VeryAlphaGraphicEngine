#pragma once
#include <GL\glew.h>
#include <iostream>
#include <string>
#include <SOIL.h>

class Texture
{
public:
	Texture(const std::string& FileName);
	virtual ~Texture();

	void Bind();

private:
	GLuint m_textureTarget;
};
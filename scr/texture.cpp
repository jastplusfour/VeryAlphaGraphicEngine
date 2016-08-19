#include "texture.h"

Texture::Texture(const std::string& fileName) {

	m_textureTarget = SOIL_load_OGL_texture(
		fileName.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y);

	if (m_textureTarget == 0)
		std::cerr << "Error loading texture" << std::endl;

	glGenTextures(1, &m_textureTarget);
	glBindTexture(GL_TEXTURE_2D, m_textureTarget);

	glBindTexture(m_textureTarget, GL_TEXTURE_2D);
	glTexParameteri(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, m_textureTarget);
}

Texture::~Texture() {
	glDeleteTextures(1, &m_textureTarget);
}
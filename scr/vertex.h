#pragma once
#include "glm\glm.hpp"

class Vertex
{
public:
	Vertex(const glm::vec3& _vertexCoords);
	Vertex(glm::vec3 _vertexCoords, glm::vec2 _textureCoords);
	~Vertex();

	inline glm::vec3 getVertexCoord() const;
	inline glm::vec2 getTextureCoord() const;

private:
	glm::vec3 vertexCoord;
	glm::vec2 textureCoord;
};
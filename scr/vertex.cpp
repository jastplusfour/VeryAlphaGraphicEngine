#include "vertex.h"

Vertex::Vertex(glm::vec3 _vertexCoords, glm::vec2 _textureCoords) :

	vertexCoord(_vertexCoords),
	textureCoord(_textureCoords) {

}

Vertex::Vertex(const glm::vec3& _vertexCoords) :

	vertexCoord(_vertexCoords) {

}

inline glm::vec3 Vertex::getVertexCoord() const {
	return vertexCoord;
}

inline glm::vec2 Vertex::getTextureCoord() const {
	return textureCoord;
}		

Vertex::~Vertex() {}

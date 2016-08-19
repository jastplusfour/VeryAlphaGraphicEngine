#pragma once

#include "GL\glew.h"
#include "vertex.h"
#include <vector>

class Mesh
{
public:
	Mesh();
	Mesh(Vertex* vertices, unsigned int numVertices);
	virtual ~Mesh();

	void draw();

private:

	enum {
		POSITION_VB,
		TEXCOORD_VB,

		NUM_BUFFERS
	};

	GLuint m_VertexArrayObject;
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

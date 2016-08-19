#include <Windows.h>
#include <GL\glew.h> //наши glew и freeglut
#include <GL\freeglut.h>
#include <iostream>
#include <glm\glm.hpp>
#include "vertex.h"
#include "texture.h"
#include "shader.h"
#include "mesh.h"
#include "display.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int args, char* argv[]) {
	
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "SUNFALL");

	Vertex vertices[] = {
		Vertex(glm::vec3(0.5f, 0.1f, 0.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.0f)),
		Vertex(glm::vec3(0.1f, 0.5f, 0.0f))
	};

	Shader shader("./res/Shader/Shader");
	Mesh mesh(vertices, 3);
	Texture texture("./test.png");

	while (!display.isClosed())	{
		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Bind();
		mesh.draw();
		texture.Bind();
		display.Update();
	}

	


	return 0;
}
#pragma once

#include <SDL.h>
#include <GL\glew.h>
#include <string>
#include <iostream>

class Display
{
public:
	Display(const int width, const int height,const std::string& title);

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();
	void Update();
	bool isClosed();

	virtual ~Display();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool m_isClosed;
};

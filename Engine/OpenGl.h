#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Shaders.h"

	
const GLfloat points[] = {
	0.0f,  0.5f,   0.0f,
	0.5f, -0.5f,   0.0f,
	-0.5f, -0.5f,   0.0f	
};

class OpenGl
{
	private:
		OpenGl()
		{
			
		};
		GLFWwindow* window;
		const GLubyte* renderer;
		const GLubyte* version;
		GLuint vao;
		GLuint vbo;
		int SetUpOpenGl();
		Shader* useShader;
	public:
	static OpenGl* CreateGraphicsSystem();
	int Draw();
	int ShouldClose();
	void Close();
};

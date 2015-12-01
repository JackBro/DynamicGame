#ifndef _OPEN_GL_H_
#define _OPEN_GL_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


	
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
		GLuint vs;
		GLuint fs;
		GLuint shader_programme;
		int SetUpOpenGl();
		
	public:
	static OpenGl* CreateGraphicsSystem();
	int Draw();
	int ShouldClose();
	void Close();
};

#endif

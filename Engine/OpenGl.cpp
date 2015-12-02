#include "OpenGl.h"


OpenGl* OpenGl::CreateGraphicsSystem()
{
	OpenGl* opengl = new OpenGl();
	opengl->SetUpOpenGl();
	return opengl;
}

int OpenGl::SetUpOpenGl()
{
	const char* vertex_shader =
	"#version 330\n"
	"attribute vec3 vp;"
	"void main () {"
	"	gl_Position = vec4 (vp, 1.0);"
	"}";
	
	const char* fragment_shader =
	"#version 330\n"
	"void main () {"
	"	gl_FragColor = vec4 (0.5, 0.0, 0.5, 1.0);"
	"}";
	
	if(!glfwInit())
	{
		fprintf(stderr, "Error: could not start GLFW3\n");
		return 1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	
	window = glfwCreateWindow(640, 480, "Engine", NULL, NULL);
	if(!window)
	{
		fprintf(stderr, "ErrorL Could Not open Window\n");
		glfwTerminate();
		return 1;
	}
	
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	
	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	useShader = Shaders::Instance()->getShader("text");
	if(useShader->shader_program == 0)
	{
		printf("fuck OFF MATE");
	}	
	return 0;
	
}
int OpenGl::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void OpenGl::Close()
{
	glfwTerminate();
}

int OpenGl::Draw()
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(useShader->shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(window);
		
		return 0;
}
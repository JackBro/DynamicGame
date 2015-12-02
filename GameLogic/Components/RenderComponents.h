#pragma once
#include "Component.h"
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Shader;

using namespace std;

class RenderComponent : public Component
{
	private:
		Shader* useShader;
		int verticesCount;
		GLuint vao;
		GLuint vbo;
	public:
	virtual string ComponentName() override
	{
		return "RenderComponent";
	}
	
	public:
		void SetUpRenderComponent(GLfloat* points, int verts);
		int GetVertCount()
		{
			return verticesCount;
		}
		GLuint GetVao()
		{
			return vao;
		}
	
};
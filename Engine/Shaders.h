#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <unordered_map>
#include <string>

using namespace std;

struct Shader
{
	GLuint vs;
	GLuint fs;
	GLuint shader_program;
};

//A singleton class that will handle loading and serving shaders

class Shaders
{
	private:
		static Shaders *instance;
		unordered_map<string, Shader*> allshaders;
		Shaders()
		{
			
		}
		
		const char* GL_type_to_string (GLenum type)
		{
			switch(type)
			{
			case GL_BOOL: return "bool";
			case GL_INT: return "int";
			case GL_FLOAT: return "float";
			case GL_FLOAT_VEC2: return "vec2";
			case GL_FLOAT_VEC3: return "vec3";
			case GL_FLOAT_VEC4: return "vec4";
			case GL_FLOAT_MAT2: return "mat2";
			case GL_FLOAT_MAT3: return "mat3";
			case GL_FLOAT_MAT4: return "mat4";
			case GL_SAMPLER_2D: return "sampler2D";
			case GL_SAMPLER_3D: return "sampler3D";
			case GL_SAMPLER_CUBE: return "samplerCube";
			case GL_SAMPLER_2D_SHADOW: return "sampler2DShader";
			default: break;
			}
			return "other";
		}
		
		bool validate(GLuint sp);
		bool parse_file_into_string(string str, char* shader_str, int max_len);
	
	public:
		Shader* getShader(string shaderName);
		static Shaders* Instance(){
			if(!instance)
			{
				instance = new Shaders;
			}
			return instance;
		}
};
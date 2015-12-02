#include "Shaders.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

Shaders* Shaders::instance = 0;

bool Shaders::validate(GLuint sp)
{
	int params = -1;
	glValidateProgram(sp);
	glGetProgramiv(sp, GL_VALIDATE_STATUS, &params);
	printf("program %i GL_VALIDATE_STATUS = %i\n", sp, params);
	if(GL_TRUE != params)
	{
		printf("Shit is fucked up\n");
		return false;
	}
	return true;
}



bool Shaders::parse_file_into_string(string file_name, char* shader_str, int max_len)
{
	FILE* file = fopen(file_name.c_str(), "r");
	if(!file)
	{
		printf("Error opening file : %s\n", strerror(errno));
		printf("%s\n", file_name.c_str());
		printf("shits on fire bro\n");
		return false;
	}
	size_t cnt = fread(shader_str, 1, max_len -1, file);
	if(cnt >= max_len - 1)
	{
		printf("Really on fire bro\n");
		return false;
	}
	if(ferror(file))
	{
		
		fclose(file);
		return false;
	}
	shader_str[cnt] = 0;
	fclose(file);
	return true;
}

Shader* Shaders::getShader(string shaderName)
{
	if(allshaders.count(shaderName) == 0)
	{
		char vs[2048];
		char fs[2048];
		parse_file_into_string("Engine/" + shaderName + "_vs.glsl", vs, 2048);
		parse_file_into_string("Engine/" + shaderName + "_fs.glsl", fs, 2048);
		
		Shader* newShader = (Shader*)malloc(sizeof(Shader));
		newShader->vs = glCreateShader(GL_VERTEX_SHADER);
		const GLchar* p = (const GLchar*)vs;
		glShaderSource(newShader->vs, 1, &p, NULL);
		glCompileShader(newShader->vs);
		
		newShader->fs = glCreateShader(GL_FRAGMENT_SHADER);
		p = (const GLchar*)fs;
		glShaderSource(newShader->fs, 1, &p, NULL);
		glCompileShader(newShader->fs);
		
		newShader->shader_program = glCreateProgram();
		glAttachShader(newShader->shader_program, newShader->fs);
		glAttachShader(newShader->shader_program, newShader->vs);
		glLinkProgram(newShader->shader_program);
		
		allshaders.emplace(shaderName, newShader);
		return newShader;
	}
	else
	{
		return allshaders[shaderName];
	}
}
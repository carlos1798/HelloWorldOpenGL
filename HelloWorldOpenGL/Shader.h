#pragma once

#ifndef SHADER_H

#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Shader {
public:
	unsigned int ID; //Program ID

	Shader(const char* vertexName, const char* fragmentName);

	void use();

	void setBool(const std::string& name, bool value)const;

	void setInt(const std::string& name, int value)const;

	void setFloat(const std::string& name, float value)const;
private:

	int compile_shader(const char* vertexShaderSource, int ShaderCompilationType);

	void checkCompilerErrors(GLuint shader, std::string type);

	int getCompiledShader(int ShaderCompilationType, const char* shader_name);
};
#endif

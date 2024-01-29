#include "Shader.h"

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "FileReader.h"

Shader::Shader(const char* vertexName, const char* fragmentName) {
	unsigned int vertexShader = getCompiledShader(GL_VERTEX_SHADER, vertexName);
	unsigned int fragmentShader = getCompiledShader(GL_FRAGMENT_SHADER, fragmentName);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	checkCompilerErrors(ID, "PROGRAM");
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
};

void Shader::use() {
	glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value)const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value)const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value)const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

int Shader::compile_shader(const char* vertexShaderSource, int ShaderCompilationType) {
	unsigned int _shader;
	_shader = glCreateShader(ShaderCompilationType);
	glShaderSource(_shader, 1, &vertexShaderSource, NULL);
	glCompileShader(_shader);
	if (ShaderCompilationType == GL_FRAGMENT_SHADER) {
		checkCompilerErrors(_shader, "FRAGMENT");
	}
	else {
		checkCompilerErrors(_shader, "VERTEX");
	}

	return _shader;
}

void Shader::checkCompilerErrors(GLuint shader, std::string type) {
	GLint success;
	char infoLog[1024];

	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED of type " << type << "\n" << infoLog << "\n  -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}
int Shader::getCompiledShader(int ShaderCompilationType, const char* shader_name) {
	unsigned int shader;
	shader = compile_shader(read_file(shader_name), ShaderCompilationType);
	return shader;
}
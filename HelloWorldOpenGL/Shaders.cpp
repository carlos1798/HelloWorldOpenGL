#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "FileReader.h"

int compile_shaders(const char* vertexShaderSource, int ShaderCompilationType) {
	unsigned int vertexShader;
	vertexShader = glCreateShader(ShaderCompilationType);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED \n" << infoLog << "\n";
	}
	std::cout << "SUCCESFULLY::COMPILED:SHADERS \n";
	return vertexShader;
}

int getCompiledShaders(int ShaderCompilationType, const char* shader_name) {
	unsigned int shader;
	shader = compile_shaders(read_file(shader_name), ShaderCompilationType);
	return shader;
}
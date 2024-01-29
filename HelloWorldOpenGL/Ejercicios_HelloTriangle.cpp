//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include "FileReader.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//
//void process_input(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//int EJercicio3() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OPENGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create window \n";
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD";
//		return -1;
//	}
//
//	unsigned int vertexshader = getCompiledShaders(GL_VERTEX_SHADER, "Triangle.glsl");
//	unsigned int fragmentOrangeShader = getCompiledShaders(GL_FRAGMENT_SHADER, "Orange_Fragment.glsl");
//	unsigned int fragmentYellowShader = getCompiledShaders(GL_FRAGMENT_SHADER, "Yellow_Fragment.glsl");
//
//	int success = {};
//	char infoLog[512];
//
//	unsigned int shaderYellowProgram;
//	shaderYellowProgram = glCreateProgram();
//	glAttachShader(shaderYellowProgram, vertexshader);
//	glAttachShader(shaderYellowProgram, fragmentYellowShader);
//
//	glLinkProgram(shaderYellowProgram);
//
//	glGetProgramiv(shaderYellowProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(shaderYellowProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::LINKING_ERROR \n" << infoLog << "\n";
//	};
//
//	unsigned int shaderOrangeProgram;
//	shaderOrangeProgram = glCreateProgram();
//	glAttachShader(shaderOrangeProgram, vertexshader);
//	glAttachShader(shaderOrangeProgram, fragmentOrangeShader);
//
//	glLinkProgram(shaderOrangeProgram);
//
//	glGetProgramiv(shaderOrangeProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(shaderOrangeProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::LINKING_ERROR \n" << infoLog << "\n";
//	};
//
//	glDeleteShader(vertexshader);
//	glDeleteShader(fragmentOrangeShader);
//	glDeleteShader(fragmentYellowShader);
//
//	float Triangle1[]{
//	0.0f, 0.9f, 0.0f, // top right
//	0.0f, -0.9f, 0.0f, // bottom right
//	-0.9f, 0.0f, 0.0f }; // top left
//
//	float Triangle2[]{
//	0.0f, 0.9f, 0.0f, // top right
//	0.9f, 0.0f, 0.0f, // bottom right
//	0.0f, -0.9f, 0.0f, // top left
//	};
//
//	unsigned int VBOs[2];
//	unsigned int VAOs[2];
//
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle1), Triangle1, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle2), Triangle2, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	while (!glfwWindowShouldClose(window)) {
//		process_input(window);
//
//		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderOrangeProgram);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glUseProgram(shaderYellowProgram);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, VAOs);
//	glDeleteBuffers(1, VBOs);
//	glDeleteProgram(shaderYellowProgram);
//	glDeleteProgram(shaderOrangeProgram);
//
//	glfwTerminate();
//	return 0;
//}
//
//int Exercise2() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OPENGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create window \n";
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD";
//		return -1;
//	}
//
//	unsigned int vertexshader = getCompiledShaders(GL_VERTEX_SHADER, "Triangle.glsl");
//	unsigned int fragmentShader = getCompiledShaders(GL_FRAGMENT_SHADER, "Orange_Fragment.glsl");
//
//	int success = {};
//	char infoLog[512];
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexshader);
//	glAttachShader(shaderProgram, fragmentShader);
//
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::LINKING_ERROR \n" << infoLog << "\n";
//	};
//	glDeleteShader(vertexshader);
//	glDeleteShader(fragmentShader);
//
//	float Triangle1[]{
//	-0.5f, 0.8f, 0.0f, // top right
//	0.0f, 0.0f, 0.0f, // bottom right
//	-0.9f, 0.0f, 0.0f }; // top left
//
//	float Triangle2[]{
//	0.5f, 0.8f, 0.0f, // top right
//	0.9f, 0.0f, 0.0f, // bottom right
//	0.0f, 0.0f, 0.0f, // top left
//	};
//
//	unsigned int VBOs[2];
//	unsigned int VAOs[2];
//
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle1), Triangle1, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle2), Triangle2, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	while (!glfwWindowShouldClose(window)) {
//		process_input(window);
//
//		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, VAOs);
//	glDeleteBuffers(1, VBOs);
//	glDeleteProgram(shaderProgram);
//
//	glfwTerminate();
//	return 0;
//}
//
//int Draw2Trianglesmain() {
//	const char* vertexShaderSource = read_file("Triangle.glsl");
//	const char* fragmentVertexShaderSource = read_file("Orange_Fragment.glsl");
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OPENGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create window \n";
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD";
//		return -1;
//	}
//
//	unsigned int vertexshader = compile_shaders(vertexShaderSource, GL_VERTEX_SHADER);
//	unsigned int fragmentShader = compile_shaders(fragmentVertexShaderSource, GL_FRAGMENT_SHADER);
//
//	int success = {};
//	char infoLog[512];
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexshader);
//	glAttachShader(shaderProgram, fragmentShader);
//
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::LINKING_ERROR \n" << infoLog << "\n";
//	};
//	glDeleteShader(vertexshader);
//	glDeleteShader(fragmentShader);
//
//	float vertices[]{
//	-0.5f, 0.8f, 0.0f, // top right
//	0.0f, 0.0f, 0.0f, // bottom right
//	-0.9f, 0.0f, 0.0f, // top left
//
//	0.5f, 0.8f, 0.0f, // top right
//	0.9f, 0.0f, 0.0f, // bottom right
//	0.0f, 0.0f, 0.0f, // top left
//	};
//
//	unsigned int VBO;
//	unsigned int VAO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	while (!glfwWindowShouldClose(window)) {
//		process_input(window);
//
//		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteProgram(shaderProgram);
//
//	glfwTerminate();
//	return 0;
//}
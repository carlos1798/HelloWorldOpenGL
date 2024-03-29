//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//void _framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//
//void _process_input(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
//int sdmain() {
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
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes
//		<< std::endl;
//
//	unsigned int vertexshader = {};
//	unsigned int fragmentShader = {};
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
//	0.0f, 0.5f, 0.0f, // top right
//	0.5f,  -0.5f, 0.0f, // bottom right
//	-0.5f,  -0.5f, 0.0f, // top left
//	};
//
//	unsigned int VBO;
//	unsigned int VAO;
//	unsigned int EBO;
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
//	glfwSetFramebufferSizeCallback(window, _framebuffer_size_callback);
//	while (!glfwWindowShouldClose(window)) {
//		_process_input(window);
//
//		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 1.5f) + 0.8f;
//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		glUseProgram(shaderProgram);
//		glUniform4f(vertexColorLocation, 0.4f, greenValue, 0.0f, 1.0f);
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
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
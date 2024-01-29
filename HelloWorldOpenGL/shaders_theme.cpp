#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"

void _framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void _process_input(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "OPENGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window \n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD";
		return -1;
	}

	float vertices[]{
		// positions         // colors
				0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
			   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
				0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
	};

	Shader sh("Triangle.vert", "Color_Fragment.frag");

	float offset = 0.5f;

	unsigned int VBO;
	unsigned int VAO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	sh.use();

	glfwSetFramebufferSizeCallback(window, _framebuffer_size_callback);
	while (!glfwWindowShouldClose(window)) {
		_process_input(window);

		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		double  timeValue = -2.8f - glfwGetTime();
		float greenValue = static_cast<float>(sin(timeValue) / 2 + 0.5);

		sh.setFloat("xOffset", greenValue);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

const char* read_file(const char* file_path) {
	std::string path = "./Shaders/" + std::string(file_path);
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cerr << "Error opening file: " << file_path << std::endl;
		return nullptr;
	}

	std::stringstream buffer;
	buffer << in.rdbuf();

	std::string content = buffer.str();

	char* value = new char[content.size() + 1];

	std::copy(content.begin(), content.end(), value);
	value[content.size()] = '\0'; // Null-terminate the char array

	return value;
}
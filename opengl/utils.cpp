#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "utils.h"

const GLchar* readFromFile(const GLchar* pathToFile) {
	std::ifstream fileStream(pathToFile, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << pathToFile << ". File does not exist." << std::endl;
		return nullptr;
	}

	std::stringstream buffer;
	buffer << fileStream.rdbuf();
	fileStream.close();

	std::string content = buffer.str();
	GLchar* source = new GLchar[content.size() + 1];
	std::copy(content.begin(), content.end(), source);
	source[content.size()] = '\0';

	return source;
}
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

struct Vertex {
	glm::vec4 Position;
	glm::vec4 Color;
	glm::vec2 UV;
	glm::vec4 Normal;
};

#endif
#include "Cube.h"

std::vector<Vertex> Cube::getCubeVertices() {
    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ -1.0f, -1.00f,  0.0f, 1.0f }, this->Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}},// A 0
        Vertex{ glm::vec4{ -1.0f, 1.00f,  0.0f, 1.0f }, this->Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // B 1
        Vertex{ glm::vec4{ 1.00f, -1.0f,  0.0f, 1.0f }, this->Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // C 2
        Vertex{ glm::vec4{ 1.00f, 1.0f,  0.0f, 1.0f }, this->Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // D 3
    };

    return Vertices;
}

std::vector<glm::ivec3> Cube::getCubeIndices() {

    std::vector<glm::ivec3> ElementsIndexesCube = {
        glm::ivec3{0, 3, 1}, //Triangulo1
        glm::ivec3{0, 2, 3}, //Triangulo2
    };

    return ElementsIndexesCube;
}

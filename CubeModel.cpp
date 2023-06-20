#include "Cube.h"

std::vector<Vertex> Cube::getCubeVertices() {

    glm::vec4 Branco{ 1.0, 1.0f, 1.0f, 1.0f };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ -1.0f, -1.00f,  0.0f, 1.0f }, Branco},// A 0
        Vertex{ glm::vec4{ -1.0f, 1.00f,  0.0f, 1.0f }, Branco }, // B 1
        Vertex{ glm::vec4{ 1.00f, -1.0f,  0.0f, 1.0f }, Branco }, // C 2
        Vertex{ glm::vec4{ 1.00f, 1.0f,  0.0f, 1.0f }, Branco }, // D 3
    };

    return Vertices;
}

std::vector<glm::ivec3> Cube::getCubeIndices() {

    std::vector<glm::ivec3> ElementsIndexesCube = {
        glm::ivec3{0, 1, 3}, //Triangulo1
        glm::ivec3{0, 3, 2}, //Triangulo2
    };

    return ElementsIndexesCube;
}

#include "Smoke.h"

std::vector<Vertex> Smoke::getSmokeVertices() {

    // Cores
    glm::vec4 Cor{ 0.8f , 0.8f , 0.8f , 1.0f };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ -0.002f, -0.002f,  0.0f, 1.0f }, Cor},// A 0
        Vertex{ glm::vec4{ -0.002f,  0.002f,  0.0f, 1.0f }, Cor }, // B 1
        Vertex{ glm::vec4{  0.002f,  0.002f,  0.0f, 1.0f }, Cor }, // C 2
        Vertex{ glm::vec4{  0.002f, -0.002f,  0.0f, 1.0f }, Cor }, // D 3
    };

    return Vertices;
}

std::vector<glm::ivec3> Smoke::getSmokeIndices() {

    std::vector<glm::ivec3> ElementsIndexes = {
        glm::ivec3{0, 1, 2}, 
        glm::ivec3{0, 2, 3}, 
    };

    return ElementsIndexes;
}

#include "Stars.h"

std::vector<Vertex> Stars::getStarsVertices(int Brilho) {

    // Ajusta o brilho para a escala correta
    float BrilhoDaEstrela = static_cast<float>(Brilho) / 100.0f;

    // Cores
    glm::vec4 Branco = { 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ 0.0f, 0.02f,  0.0f, 1.0f }, Branco, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}},// A 0
        Vertex{ glm::vec4{ -0.01f,   -0.01f,  0.0f, 1.0f }, Branco, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // B 1
        Vertex{ glm::vec4{ 0.01f, -0.01f,  0.0f, 1.0f }, Branco , glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}}, // C 2
        Vertex{ glm::vec4{ -0.01f, 0.01f,  0.0f, 1.0f }, Branco, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // D 3
        Vertex{ glm::vec4{ 0.0f, -0.02f,  0.0f, 1.0f }, Branco, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // E 4
        Vertex{ glm::vec4{ 0.01f,  0.01f,   0.0f, 1.0f }, Branco , glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}}, // F 5
    };

    return Vertices;
}

std::vector<glm::ivec3> Stars::getStarsIndices() {

    std::vector<glm::ivec3> ElementsIndexes = {
        glm::ivec3{0, 1, 2},
        glm::ivec3{3, 4, 5},
    };

    return ElementsIndexes;
}

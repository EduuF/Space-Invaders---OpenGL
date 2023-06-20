#include "Bomba.h"

std::vector<Vertex> Bomba::getBombaVertices() {

    glm::vec4 CorAleta{ 0.65f, 0.18f, 0.18f, 1.0f };
    glm::vec4 CorCorpo{ 0.65f, 0.20f, 0.50f, 1.0f };
    glm::vec4 CorCorpo2{ 0.75f, 0.25f, 0.60f, 1.0f };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ -0.04f, 0.00f,  0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, -1.0f, 0.0f} }, // A 0
        Vertex{ glm::vec4{ -0.04f,   0.04f,  0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // B 1
        Vertex{ glm::vec4{ 0.02f, 0.0f,  0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // C 2
        Vertex{ glm::vec4{ -0.02f, 0.0f,  0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // D 3
        Vertex{ glm::vec4{ 0.04f, 0.04f,  0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // E 4
        Vertex{ glm::vec4{ 0.04f,  0.0f,   0.0f, 1.0f }, CorAleta, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // F 5
        Vertex{ glm::vec4{ 0.0f,  -0.1f,   0.0f, 1.0f }, CorCorpo, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // G 6
        Vertex{ glm::vec4{ -0.04f, -0.06f,  0.0f, 1.0f }, CorCorpo, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // H 7
        Vertex{ glm::vec4{ 0.0f, 0.0f,  0.0f, 1.0f }, CorCorpo, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // I 8
        Vertex{ glm::vec4{ 0.04f, -0.06f,  0.0f, 1.0f }, CorCorpo2, glm::vec2{1.0f, 1.0f}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // J 9
    };

    return Vertices;
}

std::vector<glm::ivec3> Bomba::getBombaIndices() {

    std::vector<glm::ivec3> ElementsIndexesBomba = {
        glm::ivec3{0, 2, 1}, //AletaEsquerda
        glm::ivec3{3, 5, 4}, //AletaDireita
        glm::ivec3{6, 8, 7}, //Corpo1
        glm::ivec3{6, 9, 8}, //Corpo2
    };

    return ElementsIndexesBomba;
}

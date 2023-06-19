#include "Life.h"

std::vector<Vertex> Life::getLifeVertices() {

    // Cores
    glm::vec4 VermelhoEscuro{ 0.70f, 0.10f, 0.10f, 1.0f };
    glm::vec4 VermelhoClaro{ 0.85f, 0.25f, 0.25f, 1.0f };
    glm::vec4 VermelhoMaisClaro{ 1.0f, 0.40f, 0.40f, 1.0f };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ 0.0f,  0.1f,  0.0f, 1.0f }, VermelhoEscuro},// A 0
        Vertex{ glm::vec4{ 0.0f, -0.35f,  0.0f, 1.0f }, VermelhoEscuro }, // B 1
        Vertex{ glm::vec4{ -0.35f, 0.0f,  0.0f, 1.0f }, VermelhoEscuro }, // C 2
        Vertex{ glm::vec4{ -0.1f, 0.2f,  0.0f, 1.0f }, VermelhoEscuro }, // D 3
        Vertex{ glm::vec4{ -0.25f, 0.2f,  0.0f, 1.0f }, VermelhoEscuro }, // E 4
        Vertex{ glm::vec4{ 0.35f, 0.0f,  0.0f, 1.0f }, VermelhoClaro }, // AntiC 5
        Vertex{ glm::vec4{ 0.1f, 0.2f,  0.0f, 1.0f }, VermelhoClaro }, // AntiD 6
        Vertex{ glm::vec4{ 0.25f, 0.2f,  0.0f, 1.0f }, VermelhoMaisClaro }, // AntiE 7
    };

    return Vertices;
}

std::vector<glm::ivec3> Life::getLifeIndices() {

    std::vector<glm::ivec3> ElementsIndexesBomba = {
        glm::ivec3{0, 2, 1}, //Life1
        glm::ivec3{0, 3, 2}, //Life2
        glm::ivec3{3, 4, 2}, //Life3
        glm::ivec3{1, 5, 0}, //Life4
        glm::ivec3{0, 5, 6}, //Life5
        glm::ivec3{6, 5, 7}, //Life6
    };

    return ElementsIndexesBomba;
}

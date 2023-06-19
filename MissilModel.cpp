#include "Missil.h"

std::vector<Vertex> Missil::getMissilVertices(bool NaveOuAlien) {

    //Cores
    glm::vec4 Cor{ 0.35f, 0.90f, 0.20f, 1.0f };
    if (NaveOuAlien) {
        Cor = glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f };

    }

    std::vector<Vertex> Vertices{
        //Nave
        Vertex{ glm::vec4{ -0.02f, -0.00f,  0.0f, 1.0f }, Cor }, // A Nave 0
        Vertex{ glm::vec4{ -0.00f,  0.02f,  0.0f, 1.0f }, Cor }, // B Nave 1
        Vertex{ glm::vec4{ 0.02f,  0.00f,  0.0f, 1.0f }, Cor }, // C Nave 2 
        Vertex{ glm::vec4{ 0.00f, -0.02f,  0.0f, 1.0f }, Cor }, // D Nave 3 

        //Alien
        Vertex{ glm::vec4{ -0.01f,  0.00f,  0.0f, 1.0f }, Cor }, // A Alien 4
        Vertex{ glm::vec4{  0.00f,  0.03f,  0.0f, 1.0f }, Cor }, // B Alien 5
        Vertex{ glm::vec4{  0.01f,  0.00f,  0.0f, 1.0f }, Cor }, // C Alien 6
        Vertex{ glm::vec4{  0.00f, -0.03f,  0.0f, 1.0f }, Cor }, // D Alien 7 
    };
    return Vertices;

}

std::vector<glm::ivec3> Missil::getMissilIndices(bool NaveOuAlien) {

    std::vector<glm::ivec3> ElementsIndexesMissilNave = {
        glm::ivec3{0, 3, 1}, //Corpo1
        glm::ivec3{3, 2, 1}, //Corpo2
    };

    std::vector<glm::ivec3> ElementsIndexesMissilAlien = {
        glm::ivec3{4, 7, 5}, //Corpo1
        glm::ivec3{7, 6, 5}, //Corpo2
    };

    if (NaveOuAlien) {
        return ElementsIndexesMissilNave;
    }
    return ElementsIndexesMissilAlien;
}
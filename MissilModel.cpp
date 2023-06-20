#include "Missil.h"

std::vector<Vertex> Missil::getMissilVertices(bool NaveOuAlien) {

    //Cores
    glm::vec4 Cor{ 0.17f, 0.45f, 0.10f, 1.0f };
    if (NaveOuAlien) {
        Cor = glm::vec4{ 0.5f, 0.0f, 0.0f, 1.0f };

    }

    std::vector<Vertex> Vertices{
        //Nave
        Vertex{ glm::vec4{ -0.02f, -0.00f,  0.0f, 1.0f }, Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // A Nave 0
        Vertex{ glm::vec4{ -0.00f,  0.02f,  0.0f, 1.0f }, Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // B Nave 1
        Vertex{ glm::vec4{ 0.02f,  0.00f,  0.0f, 1.0f }, Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // C Nave 2 
        Vertex{ glm::vec4{ 0.00f, -0.02f,  0.0f, 1.0f }, Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // D Nave 3 

        //Alien
        Vertex{ glm::vec4{ -0.01f,  0.00f,  0.0f, 1.0f }, Cor , glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}}, // A Alien 4
        Vertex{ glm::vec4{  0.00f,  0.03f,  0.0f, 1.0f }, Cor, glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f} }, // B Alien 5
        Vertex{ glm::vec4{  0.01f,  0.00f,  0.0f, 1.0f }, Cor , glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}}, // C Alien 6
        Vertex{ glm::vec4{  0.00f, -0.03f,  0.0f, 1.0f }, Cor , glm::vec2{1.0f, 1.0f,}, glm::vec4{0.0f, 0.0f, 1.0f, 0.0f}}, // D Alien 7 
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
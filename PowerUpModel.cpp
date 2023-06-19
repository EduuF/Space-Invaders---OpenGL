#include "PowerUp.h"
#include "GameState.h"

std::vector<Vertex> PowerUp::getPowerUpVertices() {

    // Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 Amarelo{ 1.0f, 1.0f, 0.0f, 1.0f };

    //Modela o Alien
    std::vector<Vertex> Vertices{

        // Freeze
        Vertex{ glm::vec4{ -0.08f, -0.08f,  0.0f, 1.0f }, Azul }, // A 0
        Vertex{ glm::vec4{ 0.0f,   0.12f,  0.0f, 1.0f }, Azul }, // B 1
        Vertex{ glm::vec4{ 0.08f, -0.08f,  0.0f, 1.0f }, Azul }, // C 2 
        Vertex{ glm::vec4{ 0.0f, -0.12f,  0.0f, 1.0f }, Azul }, // D 3 
        Vertex{ glm::vec4{ -0.08f, 0.08f,  0.0f, 1.0f }, Azul }, // E 4 
        Vertex{ glm::vec4{ 0.08f,  0.08f,   0.0f, 1.0f }, Azul }, // F 5
        Vertex{ glm::vec4{ -0.12f,  0.0f,   0.0f, 1.0f }, Azul }, // G 6
        Vertex{ glm::vec4{ 0.0f, 0.08f,  0.0f, 1.0f }, Azul }, // H 7
        Vertex{ glm::vec4{ 0.0f, -0.08f,  0.0f, 1.0f }, Azul }, // I 8
        Vertex{ glm::vec4{ 0.12f, 0.0f,  0.0f, 1.0f }, Azul }, // J 9

        // Munição
        Vertex{ glm::vec4{ -0.08f, -0.12f,  0.0f, 1.0f }, Amarelo }, // A 10
        Vertex{ glm::vec4{ -0.02f,   0.0f,  0.0f, 1.0f }, Amarelo }, // B 11
        Vertex{ glm::vec4{ 0.08f, 0.0f,  0.0f, 1.0f }, Amarelo }, // C 12 
        Vertex{ glm::vec4{ -0.08f, 0.0f,  0.0f, 1.0f }, Amarelo }, // D 13 
        Vertex{ glm::vec4{ 0.02f, 0.0f,  0.0f, 1.0f }, Amarelo }, // E 14 
        Vertex{ glm::vec4{ 0.08f,  0.12f,   0.0f, 1.0f }, Amarelo }, // F 15

        // Trava Armas
        Vertex{ glm::vec4{ -0.08f, -0.12f,  0.0f, 1.0f }, Vermelho }, // A 16
        Vertex{ glm::vec4{ -0.12f, -0.08f,  0.0f, 1.0f }, Vermelho }, // B 17
        Vertex{ glm::vec4{ 0.12f, 0.08f,  0.0f, 1.0f }, Vermelho }, // C 18
        Vertex{ glm::vec4{ 0.08f, 0.12f,  0.0f, 1.0f }, Vermelho }, // D 19
        Vertex{ glm::vec4{ -0.12f, 0.08f,  0.0f, 1.0f }, Vermelho }, // E 20 
        Vertex{ glm::vec4{ 0.08f,  -0.12f,   0.0f, 1.0f }, Vermelho }, // F 21
        Vertex{ glm::vec4{ 0.12f, -0.08f,   0.0f, 1.0f }, Vermelho }, // G 22
        Vertex{ glm::vec4{ -0.08f, 0.12f,  0.0f, 1.0f }, Vermelho }, // H 23

    };
    return Vertices;

}

std::vector<glm::ivec3> PowerUp::getPowerUpIndices(int tipo) {

    std::vector<glm::ivec3> ElementsIndexesPowerUp2 = {
        glm::ivec3{0, 2, 1}, //Corpo1
        glm::ivec3{3, 5, 4}, //Corpo2
        glm::ivec3{6, 8, 7}, //Corpo3
        glm::ivec3{8, 9, 7}, //Corpo4
       
    };

    std::vector<glm::ivec3> ElementsIndexesPowerUp0 = {
        glm::ivec3{10, 12, 11}, //Corpo1
        glm::ivec3{13, 14, 15}, //Corpo2
        
    };

    std::vector<glm::ivec3> ElementsIndexesPowerUp1 = {
        glm::ivec3{16, 18, 17}, //Corpo1
        glm::ivec3{17, 18, 19}, //Corpo2
        glm::ivec3{20, 21, 22}, //Corpo3
        glm::ivec3{20, 22, 23}, //Corpo4
        
    };

    if (tipo == 0) {
        return ElementsIndexesPowerUp0;
    }
    else if (tipo == 1) {
        return ElementsIndexesPowerUp1;
    }
    return ElementsIndexesPowerUp2;
}
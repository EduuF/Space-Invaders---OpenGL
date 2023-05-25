#include "Nave.h"

Nave::Nave(float posicao, float rotacao, float escala) {
    this->posicao = posicao;
    this->rotacao = rotacao;
    this->escala = escala;
    modelaANave();
}

void Nave::modelaANave() {
    std::array<glm::vec3, 3> Corpo = {
        glm::vec3{-0.04f, -0.88f,  0.0f},
        glm::vec3{ 0.0f,  -0.76f,  0.0f},
        glm::vec3{ 0.04f, -0.88f,   0.0f}
    };

    std::array<glm::vec3, 3> CanhaoEsquerdo = {
        glm::vec3{-0.06f, -0.88f, 0.0f},
        glm::vec3{-0.05f, -0.84f, 0.0f},
        glm::vec3{-0.04f, -0.88f, 0.0f}
    };

    std::array<glm::vec3, 3> CanhaoDireito = {
        glm::vec3{0.04f, -0.88f, 0.0f},
        glm::vec3{0.05f, -0.84f, 0.0f},
        glm::vec3{0.06f, -0.88f,   0.0f},
    };

    std::array<glm::vec3, 3> MotorEsquerdo = {
        glm::vec3{-0.03f, -0.9f,  0.0f},
        glm::vec3{-0.02f, -0.88f, 0.0f},
        glm::vec3{-0.01f, -0.9f,  0.0f},
    };

    std::array<glm::vec3, 3> MotorDireito = {
        glm::vec3{0.01f, -0.9f,  0.0f},
        glm::vec3{0.02f, -0.88f, 0.0f},
        glm::vec3{0.03f, -0.9f,  0.0f}
    };

    std::array<std::array<glm::vec3, 3>, 5> NaveVertices = {
        // Corpo
        Corpo,
        // Asa esquerda
        CanhaoEsquerdo,
        // Asa direita
        CanhaoDireito,
        // Entrada de ar
        MotorEsquerdo,
        // FarolEsqcuerdo
        MotorDireito

    };

    this->modeloDaNave = NaveVertices;
}

void Nave::ajustaEscalaDaNave(float escalar) {
    for (int i = 0; i < modeloDaNave.size(); i++) {
        for (int j = 0; j < 3; j++) {
            this->modeloDaNave[i][j] *= escalar;
        }
    }
}

//std::array<std::array<glm::vec3, 3>, 7> Nave::transladaANave() {

//}

//std::array<std::array<glm::vec3, 3>, 7> Nave::rotacionaANave() {

//}
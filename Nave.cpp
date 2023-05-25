#include "Nave.h"
#include "Matrices.h"

Nave::Nave(float posicao, float rotacao, float escala) {
    this->posicao = posicao;
    this->rotacao = rotacao;
    this->escala = escala;
    modelaANave();
}

void Nave::modelaANave() {
    std::array<glm::vec4, 3> Corpo = {
        glm::vec4{-0.04f, -0.88f,  0.0f, 1.0f},
        glm::vec4{ 0.0f,  -0.76f,  0.0f, 1.0f},
        glm::vec4{ 0.04f, -0.88f,   0.0f, 1.0f}
    };

    std::array<glm::vec4, 3> CanhaoEsquerdo = {
        glm::vec4{-0.06f, -0.88f, 0.0f, 1.0f},
        glm::vec4{-0.05f, -0.84f, 0.0f, 1.0f},
        glm::vec4{-0.04f, -0.88f, 0.0f, 1.0f}
    };

    std::array<glm::vec4, 3> CanhaoDireito = {
        glm::vec4{0.04f, -0.88f, 0.0f, 1.0f},
        glm::vec4{0.05f, -0.84f, 0.0f, 1.0f},
        glm::vec4{0.06f, -0.88f,   0.0f, 1.0f},
    };

    std::array<glm::vec4, 3> MotorEsquerdo = {
        glm::vec4{-0.03f, -0.9f,  0.0f, 1.0f},
        glm::vec4{-0.02f, -0.88f, 0.0f, 1.0f},
        glm::vec4{-0.01f, -0.9f,  0.0f, 1.0f},
    };

    std::array<glm::vec4, 3> MotorDireito = {
        glm::vec4{0.01f, -0.9f,  0.0f, 1.0f},
        glm::vec4{0.02f, -0.88f, 0.0f, 1.0f},
        glm::vec4{0.03f, -0.9f,  0.0f, 1.0f}
    };

    std::array<std::array<glm::vec4, 3>, 5> NaveVertices = {
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

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscola) {
    for (auto& parte : modeloDaNave) {
        ScaleMatrix(parte, FatorDeEscola);
    }
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    for (auto& parte : modeloDaNave) {
        TranslationMatrix(parte, fatorDeTranslacao);
    }
}

void Nave::rotacionaANave(float graus, glm::vec3 eixoDeRotacao) {
    for (auto& parte : modeloDaNave) {
        RotationMatrix(parte, graus, eixoDeRotacao);
    }
}
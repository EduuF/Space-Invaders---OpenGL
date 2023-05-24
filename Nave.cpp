#include "Nave.h"

Nave::Nave(float posicao, float rotacao, float escala) {
	this->posicao = posicao;
	this->rotacao = rotacao;
	this->escala = escala;
}

std::array<std::array<glm::vec3, 3>, 7> Nave::modelaANave() {
    std::array<glm::vec3, 3> Corpo = {
        glm::vec3{-0.1f, -0.2f, 0.0f},
        glm::vec3{0.1f, -0.2f, 0.0f},
        glm::vec3{0.0f, 0.2f, 0.0f}
    };

    std::array<glm::vec3, 3> AsaEsquerda = {
        glm::vec3{-0.2f, -0.2f, 0.0f},
        glm::vec3{-0.1f, -0.2f, 0.0f},
        glm::vec3{-0.15f, 0.0f, 0.0f}
    };

    std::array<glm::vec3, 3> AsaDireita = {
        glm::vec3{0.1f, -0.2f, 0.0f},
        glm::vec3{0.2f, -0.2f, 0.0f},
        glm::vec3{0.15f, 0.0f, 0.0f},
    };

    std::array<glm::vec3, 3> EntradaDeAr = {
        glm::vec3{-0.05f, 0.0f, 0.0f},
        glm::vec3{0.05f, 0.0f, 0.0f},
        glm::vec3{0.0f, 0.1f, 0.0f},
    };

    std::array<glm::vec3, 3> FarolEsquerdo = {
        glm::vec3{-0.1f, -0.2f, 0.0f},
        glm::vec3{-0.075f, -0.25f, 0.0f},
        glm::vec3{-0.05f, -0.2f, 0.0f}
    };

    std::array<glm::vec3, 3> FarolDireito = {
        glm::vec3{0.05f, -0.2f, 0.0f},
        glm::vec3{0.075f, -0.25f, 0.0f},
        glm::vec3{0.1f, -0.2f, 0.0f},
    };

    std::array<glm::vec3, 3> Escapamento = {
        glm::vec3{-0.025f, -0.2f, 0.0f},
        glm::vec3{0.025f, -0.2f, 0.0f},
        glm::vec3{0.0f, -0.25f, 0.0f}
    };

    std::array<std::array<glm::vec3, 3>, 7> CorpoDaNave = {
        // Corpo
        Corpo,
        // Asa esquerda
        AsaEsquerda,
        // Asa direita
        AsaDireita,
        // Entrada de ar
        EntradaDeAr,
        // FarolEsqcuerdo
        FarolEsquerdo,
        // FarolEsqcuerdo
        FarolDireito,
        // Escapamento
        Escapamento
    };

    return CorpoDaNave;
}

std::array<std::array<glm::vec3, 3>, 7> Nave::ajustaEscalaDaNave() {

}

std::array<std::array<glm::vec3, 3>, 7> Nave::transladaANave() {

}

std::array<std::array<glm::vec3, 3>, 7> Nave::rotacionaANave() {

}
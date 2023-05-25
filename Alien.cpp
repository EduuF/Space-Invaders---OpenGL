#include "Alien.h"
#include "Matrices.h"

Alien::Alien(float posicao, float rotacao, float escala) {
	this->posicao = posicao;
	this->rotacao = rotacao;
    modelaAlien();
}

void Alien::modelaAlien() {
    
    //Vertices
    glm::vec4 A = glm::vec4{ -0.04f, 0.96f, 0.0f, 1.0f };
    glm::vec4 B = glm::vec4{ 0.04f, 0.96f, 0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ 0.04f, 0.9f, 0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.04f, 0.9f, 0.0f, 1.0f };
    glm::vec4 E = glm::vec4{ -0.04f, 0.92f, 0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.11f, 0.92f, 0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.11f, 0.96f, 0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.08f, 0.92f, 0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -0.08f, 0.88f, 0.0f, 1.0f };
    glm::vec4 J = glm::vec4{ -0.11f, 0.88f, 0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.1f, 0.88f, 0.0f, 1.0f };
    glm::vec4 L = glm::vec4{ -0.1f, 0.86f, 0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -0.11f, 0.86f, 0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ 0.11f, 0.96f, 0.0f, 1.0f };
    glm::vec4 O = glm::vec4{ 0.11f, 0.92f, 0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ 0.04f, 0.92f, 0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ 0.11f, 0.88f, 0.0f, 1.0f };
    glm::vec4 R = glm::vec4{ 0.08f, 0.88f, 0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ 0.08f, 0.92f, 0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ 0.11f, 0.86f, 0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ 0.1f, 0.86f, 0.0f, 1.0f };
    glm::vec4 V = glm::vec4{ 0.1f, 0.88f, 0.0f, 1.0f };
    glm::vec4 X = glm::vec4{ -0.03f, 0.97f, 0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.01f, 0.97f, 0.0f, 1.0f };
    glm::vec4 Y = glm::vec4{ -0.02f, 0.96f, 0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ 0.01f, 0.97f, 0.0f, 1.0f };
    glm::vec4 A1 = glm::vec4{ 0.03f, 0.97f, 0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ 0.02f, 0.96f, 0.0f, 1.0f };

    std::array<glm::vec4, 3> Corpo1 = {A, C, D};
    std::array<glm::vec4, 3> Corpo2 = {A, B, C};

    std::array<glm::vec4, 3> BracoEsquerdo1 = {A, E, F};
    std::array<glm::vec4, 3> BracoEsquerdo2 = {A, F, G};

    std::array<glm::vec4, 3> MaoEsquerda1 = {H, I, J};
    std::array<glm::vec4, 3> MaoEsquerda2 = {H, J, F};

    std::array<glm::vec4, 3> CanhaoEsquerdo1 = {K, L, M};
    std::array<glm::vec4, 3> CanhaoEsquerdo2 = {K, M, J};

    std::array<glm::vec4, 3> BracoDireito1 = {B, O, P};
    std::array<glm::vec4, 3> BracoDireito2 = {B, N, O};

    std::array<glm::vec4, 3> MaoDireita1 = {O, Q, R};
    std::array<glm::vec4, 3> MaoDireita2 = {O, R, S};

    std::array<glm::vec4, 3> CanhaoDireito1 = {Q, T, U};
    std::array<glm::vec4, 3> CanhaoDireito2 = {Q, U, V};

    std::array<glm::vec4, 3> MotorEsquerdo = { X, W, Y};
    std::array<glm::vec4, 3> MotorDireito = {Z, A1, B1};

    std::array<std::array<glm::vec4, 3>, 16> alienVertices = {
        // Corpo
        Corpo1, Corpo2,

        // Braco Esquerdo
        BracoEsquerdo1, BracoEsquerdo2,
        // Mao Esquerda
        MaoEsquerda1, MaoEsquerda2,
        // CanhaoEsquerdo
        CanhaoEsquerdo1, CanhaoEsquerdo2,
        // Motor Esquerdo
        MotorEsquerdo,

        // Braco Direito
        BracoDireito1, BracoDireito2,
        // Mao Direito
        MaoDireita1, MaoDireita2,
        // Canhao Direito
        CanhaoDireito1, CanhaoDireito2,
        // Motor Direito
        MotorDireito
    };

    this->modeloDoInimigo = alienVertices;

}

void Alien::ajustaEscalaDoAlien(float escalar) {
    for (auto& parte : modeloDoInimigo) {
        for (auto& vertice : parte) {
            vertice.x *= escalar;
            vertice.y *= escalar;
            vertice.z *= escalar;
        }
    }
}

void Alien::transladaOAlien(glm::vec3 fatorDeTranslacao) {
    for (auto& parte : modeloDoInimigo) {
        TranslationMatrix(parte, fatorDeTranslacao);
    }
}

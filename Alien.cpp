#include "Alien.h"

Alien::Alien(float posicao, float rotacao, float escala) {
	this->posicao = posicao;
	this->rotacao = rotacao;
    modelaAlien();
}

void Alien::modelaAlien() {
    
    //Vertices
    glm::vec3 A = glm::vec3{ -0.04f, 0.96f, 0.0f };
    glm::vec3 B = glm::vec3{ 0.04f, 0.96f, 0.0f };
    glm::vec3 C = glm::vec3{ 0.04f, 0.9f, 0.0f };
    glm::vec3 D = glm::vec3{ -0.04f, 0.9f, 0.0f };
    glm::vec3 E = glm::vec3{ -0.04f, 0.92f, 0.0f };
    glm::vec3 F = glm::vec3{ -0.11f, 0.92f, 0.0f };
    glm::vec3 G = glm::vec3{ -0.11f, 0.96f, 0.0f };
    glm::vec3 H = glm::vec3{ -0.08f, 0.92f, 0.0f };
    glm::vec3 I = glm::vec3{ -0.08f, 0.88f, 0.0f };
    glm::vec3 J = glm::vec3{ -0.11f, 0.88f, 0.0f };
    glm::vec3 K = glm::vec3{ -0.1f, 0.88f, 0.0f };
    glm::vec3 L = glm::vec3{ -0.1f, 0.86f, 0.0f };
    glm::vec3 M = glm::vec3{ -0.11f, 0.86f, 0.0f };
    glm::vec3 N = glm::vec3{ 0.11f, 0.96f, 0.0f };
    glm::vec3 O = glm::vec3{ 0.11f, 0.92f, 0.0f };
    glm::vec3 P = glm::vec3{ 0.04f, 0.92f, 0.0f };
    glm::vec3 Q = glm::vec3{ 0.11f, 0.88f, 0.0f };
    glm::vec3 R = glm::vec3{ 0.08f, 0.88f, 0.0f };
    glm::vec3 S = glm::vec3{ 0.08f, 0.92f, 0.0f };
    glm::vec3 T = glm::vec3{ 0.11f, 0.86f, 0.0f };
    glm::vec3 U = glm::vec3{ 0.1f, 0.86f, 0.0f };
    glm::vec3 V = glm::vec3{ 0.1f, 0.88f, 0.0f };
    glm::vec3 X = glm::vec3{ -0.03f, 0.97f, 0.0f };
    glm::vec3 W = glm::vec3{ -0.01f, 0.97f, 0.0f };
    glm::vec3 Y = glm::vec3{ -0.02f, 0.96f, 0.0f };
    glm::vec3 Z = glm::vec3{ 0.01f, 0.97f, 0.0f };
    glm::vec3 A1 = glm::vec3{ 0.03f, 0.97f, 0.0f };
    glm::vec3 B1 = glm::vec3{ 0.02f, 0.96f, 0.0f };

    std::array<glm::vec3, 3> Corpo1 = {A, C, D};
    std::array<glm::vec3, 3> Corpo2 = {A, B, C};

    std::array<glm::vec3, 3> BracoEsquerdo1 = {A, E, F};
    std::array<glm::vec3, 3> BracoEsquerdo2 = {A, F, G};

    std::array<glm::vec3, 3> MaoEsquerda1 = {H, I, J};
    std::array<glm::vec3, 3> MaoEsquerda2 = {H, J, F};

    std::array<glm::vec3, 3> CanhaoEsquerdo1 = {K, L, M};
    std::array<glm::vec3, 3> CanhaoEsquerdo2 = {K, M, J};

    std::array<glm::vec3, 3> BracoDireito1 = {B, O, P};
    std::array<glm::vec3, 3> BracoDireito2 = {B, N, O};

    std::array<glm::vec3, 3> MaoDireita1 = {O, Q, R};
    std::array<glm::vec3, 3> MaoDireita2 = {O, R, S};

    std::array<glm::vec3, 3> CanhaoDireito1 = {Q, T, U};
    std::array<glm::vec3, 3> CanhaoDireito2 = {Q, U, V};

    std::array<glm::vec3, 3> MotorEsquerdo = { X, W, Y};
    std::array<glm::vec3, 3> MotorDireito = {Z, A1, B1};

    std::array<std::array<glm::vec3, 3>, 16> alienVertices = {
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
    for (int i = 0; i < modeloDoInimigo.size(); i++) {
        for (int j = 0; j < 3; j++) {
            this->modeloDoInimigo[i][j] *= escalar;
        }
    }
}
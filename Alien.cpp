#include "Alien.h"
#include "Matrices.h"
#include <iostream>

Alien::Alien() {}

Alien::Alien(glm::vec4 Centro) {
    this->Centro = Centro;
    std::array<std::array<glm::vec4, 3>, 18> inimigoModel = this->getAlienModel(); // Modelo Base

    this->modeloDoInimigo = inimigoModel; // Acopla modelo base

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrixAlien(this->modeloDoInimigo, Origem, this->Centro);
}


void Alien::ajustaEscalaDoAlien(glm::vec3 FatorDeEscala) {
    for (auto& parte : modeloDoInimigo) { // Para cada triangulo do objeto
        ScaleMatrix(parte, FatorDeEscala, this->Centro); // Escala o triangulo
    }
}

void Alien::transladaOAlien(glm::vec3 fatorDeTranslacao) {
    TranslationMatrixAlien(this->modeloDoInimigo, this->Centro, fatorDeTranslacao);
}

void Alien::rotacionaOAlien(float graus) {
    RotationMatrixAlien(this->modeloDoInimigo, graus, this->Centro); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Alien::ProjetaAlien(float AspectRatio, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle) {
    ModelViewProjectionAlien(this->modeloDoInimigo, AspectRatio, Eye, Center, Up, FoVAngle);
}


std::array<std::array<glm::vec4, 3>, 18> Alien::getAlienModel() {

    

    //Modela o Alien
    glm::vec4 A = glm::vec4{ -0.04f, +0.05f,  +0.0f, 1.0f };
    glm::vec4 B = glm::vec4{ +0.04f, +0.05f, +0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ +0.04f, -0.01f,  +0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.04f, -0.01f,  +0.0f, 1.0f };
    glm::vec4 E = glm::vec4{ -0.04f, +0.01f, +0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.11f, +0.01f, +0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.11f, +0.05f, +0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.08f, +0.01f, +0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -0.08f, -0.03f, +0.0f, 1.0f };
    glm::vec4 J = glm::vec4{ -0.11f, -0.03f, +0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.1f,  -0.03f, +0.0f, 1.0f };
    glm::vec4 L = glm::vec4{ -0.1f,  -0.05f, +0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -0.11f, -0.05f, +0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ +0.11f, +0.05f, +0.0f, 1.0f };
    glm::vec4 O = glm::vec4{ +0.11f, +0.01f, +0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ +0.04f, +0.01f, +0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ +0.11f, -0.03f, +0.0f, 1.0f };
    glm::vec4 R = glm::vec4{ +0.08f, -0.03f, +0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ +0.08f, +0.01f, +0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ +0.11f, -0.05f, +0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ +0.1f,  -0.05f, +0.0f, 1.0f };
    glm::vec4 V = glm::vec4{ +0.1f,  -0.03f, +0.0f, 1.0f };
    glm::vec4 X = glm::vec4{ -0.03f, +0.06f, +0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.01f, +0.06f, +0.0f, 1.0f };
    glm::vec4 Y = glm::vec4{ -0.02f, +0.05f, +0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ +0.01f, +0.06f, +0.0f, 1.0f };
    glm::vec4 A1 = glm::vec4{ +0.03f, +0.06f, +0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ +0.02f, +0.05f, +0.0f, 1.0f };


    // Bouding Box
    glm::vec4 BoundingBoxA {- 0.11f,  - 0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB {- 0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC {  0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD {  0.11f,  - 0.05f,  0.0f, 1.0f };


    std::array<glm::vec4, 3> Corpo1 = { A, C, D };
    std::array<glm::vec4, 3> Corpo2 = { A, B, C };

    std::array<glm::vec4, 3> BracoEsquerdo1 = { A, E, F };
    std::array<glm::vec4, 3> BracoEsquerdo2 = { A, F, G };

    std::array<glm::vec4, 3> MaoEsquerda1 = { H, I, J };
    std::array<glm::vec4, 3> MaoEsquerda2 = { H, J, F };

    std::array<glm::vec4, 3> CanhaoEsquerdo1 = { K, L, M };
    std::array<glm::vec4, 3> CanhaoEsquerdo2 = { K, M, J };

    std::array<glm::vec4, 3> BracoDireito1 = { B, O, P };
    std::array<glm::vec4, 3> BracoDireito2 = { B, N, O };

    std::array<glm::vec4, 3> MaoDireita1 = { O, Q, R };
    std::array<glm::vec4, 3> MaoDireita2 = { O, R, S };

    std::array<glm::vec4, 3> CanhaoDireito1 = { Q, T, U };
    std::array<glm::vec4, 3> CanhaoDireito2 = { Q, U, V };

    std::array<glm::vec4, 3> MotorEsquerdo = { X, W, Y };
    std::array<glm::vec4, 3> MotorDireito = { Z, A1, B1 };

    std::array<glm::vec4, 3> BoudingBox1 = { BoundingBoxA, BoundingBoxB, BoundingBoxC };
    std::array<glm::vec4, 3> BoudingBox2 = { BoundingBoxA, BoundingBoxC, BoundingBoxD };

    std::array<std::array<glm::vec4, 3>, 18> alienVertices = {
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
        MotorDireito,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2
    };

    return alienVertices;
}
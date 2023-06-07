#include "Alien.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Alien::Alien() {}

Alien::Alien(glm::vec4 Centro) {
    this->Centro = Centro;
    std::array<std::array<Vertex, 3>, 18> inimigoModel = this->getAlienModel(); // Modelo Base

    this->modeloDoInimigo = inimigoModel; // Acopla modelo base

    this->CanhaoDireitoAtira = true;
    this->disponível = true;
    this->hasBomb = false;
    this->ataca = false;
    this->life = 10;
    this->recua = false;

    // Encontra o UP do Alien
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right do Alien
    this->Right = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

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
    RotationMatrixAlien(this->modeloDoInimigo, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
}

std::array<std::array<Vertex, 3>, 18> Alien::getAlienModel() {

    

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

    //Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde{ 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho{ 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde{ 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul{ 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo{ 0.73f, 0.54f, 0.75f, 1.0f };
    glm::vec4 CorBracoEsquerdo{ 0.42f, 0.20f, 0.58f, 1.0f };
    glm::vec4 CorMaoEsquerda{ 0.41f, 0.05f, 0.69f, 1.0f };
    glm::vec4 CorCanhaoEsquerdo{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBracoDireito{ 0.42f, 0.20f, 0.58f, 1.0f };
    glm::vec4 CorMaoDireita{ 0.41f, 0.05f, 0.69f, 1.0f };
    glm::vec4 CorCanhaoDireito{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorEsquerdo{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorDireito{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoundingBox{ 0.0f, 0.0f, 0.0f, 1.0f };


    std::array<Vertex, 3> Corpo1 = {
        Vertex{A, CorCorpo},
        Vertex{D, CorCorpo},
        Vertex{C, CorCorpo}
    };

    std::array<Vertex, 3> Corpo2 = {
        Vertex{A, CorCorpo},
        Vertex{C, CorCorpo},
        Vertex{B, CorCorpo}
    };

    std::array<Vertex, 3> BracoEsquerdo1 = {
        Vertex{A, CorBracoEsquerdo},
        Vertex{F, CorBracoEsquerdo},
        Vertex{E, CorBracoEsquerdo}
    };

    std::array<Vertex, 3> BracoEsquerdo2 = {
        Vertex{A, CorBracoEsquerdo},
        Vertex{G, CorBracoEsquerdo},
        Vertex{F, CorBracoEsquerdo}
    };

    std::array<Vertex, 3> MaoEsquerda1 = {
        Vertex{H, CorMaoEsquerda},
        Vertex{J, CorMaoEsquerda},
        Vertex{I, CorMaoEsquerda}
    };

    std::array<Vertex, 3> MaoEsquerda2 = {
        Vertex{H, CorMaoEsquerda},
        Vertex{F, CorMaoEsquerda},
        Vertex{J, CorMaoEsquerda}
    };

    std::array<Vertex, 3> CanhaoEsquerdo1 = {
        Vertex{K, CorCanhaoEsquerdo},
        Vertex{M, CorCanhaoEsquerdo},
        Vertex{L, CorCanhaoEsquerdo}
    };

    std::array<Vertex, 3> CanhaoEsquerdo2 = {
        Vertex{K, CorCanhaoEsquerdo},
        Vertex{J, CorCanhaoEsquerdo},
        Vertex{M, CorCanhaoEsquerdo}
    };

    std::array<Vertex, 3> BracoDireito1 = {
        Vertex{B, CorBracoDireito},
        Vertex{P, CorBracoDireito},
        Vertex{O, CorBracoDireito}
    };

    std::array<Vertex, 3> BracoDireito2 = {
        Vertex{B, CorBracoDireito},
        Vertex{O, CorBracoDireito},
        Vertex{N, CorBracoDireito}
    };

    std::array<Vertex, 3> MaoDireita1 = {
        Vertex{O, CorMaoDireita},
        Vertex{R, CorMaoDireita},
        Vertex{Q, CorMaoDireita}
    };

    std::array<Vertex, 3> MaoDireita2 = {
        Vertex{O, CorMaoDireita},
        Vertex{S, CorMaoDireita},
        Vertex{R, CorMaoDireita}
    };

    std::array<Vertex, 3> CanhaoDireito1 = {
        Vertex{Q, CorCanhaoDireito},
        Vertex{U, CorCanhaoDireito},
        Vertex{T, CorCanhaoDireito}
    };

    std::array<Vertex, 3> CanhaoDireito2 = {
        Vertex{Q, CorCanhaoDireito},
        Vertex{V, CorCanhaoDireito},
        Vertex{U, CorCanhaoDireito}
    };

    std::array<Vertex, 3> MotorEsquerdo = {
        Vertex{X, CorMotorEsquerdo},
        Vertex{Y, CorMotorEsquerdo},
        Vertex{W, CorMotorEsquerdo}
    };

    std::array<Vertex, 3> MotorDireito = {
        Vertex{Z, CorMotorDireito},
        Vertex{B1, CorMotorDireito},
        Vertex{A1, CorMotorDireito}
    };

    std::array<Vertex, 3> BoudingBox1 = {
        Vertex{BoundingBoxA, CorBoundingBox},
        Vertex{BoundingBoxC, CorBoundingBox},
        Vertex{BoundingBoxB, CorBoundingBox}
    };

    std::array<Vertex, 3> BoudingBox2 = {
        Vertex{BoundingBoxA, CorBoundingBox},
        Vertex{BoundingBoxD, CorBoundingBox},
        Vertex{BoundingBoxC, CorBoundingBox}
    };


    std::array<std::array<Vertex, 3>, 18> alienVertices = {
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

Missil Alien::Atira(float velocidade){

    bool NaveOuAlien = false;

    if (this->CanhaoDireitoAtira) {

        Missil missil(NaveOuAlien, this->modeloDoInimigo[7][2].Position, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(NaveOuAlien, this->modeloDoInimigo[14][1].Position, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}

void Alien::CarregaBomba() {
    this->bomba = Bomba(this->Centro);
}


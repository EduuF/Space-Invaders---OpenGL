#include "Nave.h"
#include "Matrices.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {
    // Define o centro do obejto como 0,0,0 (Pode ser alterado futuramente)
    this->NaveCentro = NaveCentro; // Diz qual é o centro de onde o objeto será criado
    std::array<std::array<glm::vec4, 3>, 7> NaveModel = this->getNaveModel(); // Modelo Base

    this->modeloDaNave = NaveModel; // Acopla modelo base

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 0.0f };
    TranslationMatrix(Origem, NaveModel, this->NaveCentro);
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscala) {
    for (auto& parte : modeloDaNave) { // Para cada triangulo do objeto
        ScaleMatrix(parte, FatorDeEscala, this->NaveCentro); // Escala o triangulo
    }
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->NaveCentro, this->modeloDaNave, fatorDeTranslacao);
}

void Nave::rotacionaANave(float graus, glm::vec3 eixoDeRotacao) {
    for (auto& parte : modeloDaNave) { // Para cada Triangulo do objeto
        RotationMatrix(parte, graus, this->NaveCentro); // Rotaciona o triangulo em relação ao centro do OBJ
    }
}


std::array<std::array<glm::vec4, 3>, 7> Nave::getNaveModel() {

    // Modela a nave
    glm::vec4 A{ -0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 B{  0.0f,    0.05f,  0.0f, 1.0f };
    glm::vec4 C{  0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 D{ -0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 E{ -0.06f,   0.0f,   0.0f, 1.0f };
    glm::vec4 F{  0.06f,   0.0f,   0.0f, 1.0f };
    glm::vec4 G{  0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 H{ -0.03f, -0.05f,  0.0f, 1.0f };
    glm::vec4 I{ -0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 J{  0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 K{  0.03f, -0.05f,  0.0f, 1.0f };

    // Bouding Box 

    glm::vec4 BoundingBoxA = glm::vec4{ -0.08f, -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB = glm::vec4{ -0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC = glm::vec4{ 0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD = glm::vec4{ 0.08f, -0.05f,  0.0f, 1.0f };

    std::array<glm::vec4, 3> Corpo = { A, B, C };
    std::array<glm::vec4, 3> CanhaoEsquerdo = { A, D, E };
    std::array<glm::vec4, 3> CanhaoDireito = { C, F, G };
    std::array<glm::vec4, 3> MotorEsquerdo = { A, H, I };
    std::array<glm::vec4, 3> MotorDireito = { C, J, K };
    std::array<glm::vec4, 3> BoudingBox1 = { BoundingBoxA, BoundingBoxB, BoundingBoxC };
    std::array<glm::vec4, 3> BoudingBox2 = { BoundingBoxA, BoundingBoxC, BoundingBoxD };

    std::array<std::array<glm::vec4, 3>, 7> NaveVertices = {

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

        // Bouding Box


    };

    return NaveVertices;
}


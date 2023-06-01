#include "Nave.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {

    this->NaveCentro = NaveCentro; // Diz qual é o centro de onde o objeto será criado
    std::array<std::array<Vertex, 3>, 7> NaveModel = this->getNaveModel(); // Modelo Base

    this->modeloDaNave = NaveModel; // Acopla modelo base

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrixNave(this->modeloDaNave, Origem, this->NaveCentro);
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscala) {
    for (auto& parte : this->modeloDaNave) { // Para cada triangulo do objeto
        ScaleMatrix(parte, FatorDeEscala, this->NaveCentro); // Escala o triangulo
    }
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrixNave(this->modeloDaNave, this->NaveCentro, fatorDeTranslacao);
}

void Nave::rotacionaANave(float graus) {
    RotationMatrixNave(this->modeloDaNave, graus, this->NaveCentro); // Rotaciona o triangulo em relação ao centro do OBJ
}


std::array<std::array<Vertex, 3>, 7> Nave::getNaveModel() {

    // Modela a nave
    glm::vec4 A{ -0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 B{  0.0f,   0.05f,  0.0f, 1.0f };
    glm::vec4 C{  0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 D{ -0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 E{ -0.06f,  0.0f,   0.0f, 1.0f };
    glm::vec4 F{  0.06f,  0.0f,   0.0f, 1.0f };
    glm::vec4 G{  0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 H{ -0.03f, -0.05f,  0.0f, 1.0f };
    glm::vec4 I{ -0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 J{  0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 K{  0.03f, -0.05f,  0.0f, 1.0f };

    // Bouding Box 

    glm::vec4 BoundingBoxA{ -0.08f, -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.08f, -0.05f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Vermelho         { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde            { 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul             { 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho     { 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde        { 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul         { 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo         { 0.45f, 0.56f, 0.67f, 1.0f };
    glm::vec4 CorCanhaoDireito { 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorCanhaoEsquerdo{ 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorMotorDireito  { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorEsquerdo { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoudingBox   { 0.0f, 0.0f, 0.0f, 1.0f };

    std::array<Vertex, 3> Corpo = { Vertex{A, CorCorpo}, Vertex{B, CorCorpo}, Vertex{C, CorCorpo} };
    std::array<Vertex, 3> CanhaoEsquerdo = { Vertex{A, AntiVermelho}, Vertex{D, AntiVerde}, Vertex{E, AntiAzul} };
    std::array<Vertex, 3> CanhaoDireito = { Vertex{C, AntiAzul}, Vertex{F, AntiVermelho}, Vertex{G, AntiVerde} };
    std::array<Vertex, 3> MotorEsquerdo = { Vertex{A, CorMotorEsquerdo}, Vertex{H, CorMotorEsquerdo}, Vertex{I, CorMotorEsquerdo} };
    std::array<Vertex, 3> MotorDireito = { Vertex{C, CorMotorDireito}, Vertex{J, CorMotorDireito}, Vertex{K, CorMotorDireito} };

    std::array<Vertex, 3> BoudingBox1 = { Vertex{BoundingBoxA, CorBoudingBox}, Vertex{BoundingBoxB, CorBoudingBox}, Vertex{BoundingBoxC, CorBoudingBox} };
    std::array<Vertex, 3> BoudingBox2 = { Vertex{BoundingBoxA, CorBoudingBox}, Vertex{BoundingBoxC, CorBoudingBox}, Vertex{BoundingBoxD, CorBoudingBox} };


    std::array<std::array<Vertex, 3>, 7> NaveVertices = {

        // Corpo
        Corpo,
        // Asa esquerda
        CanhaoEsquerdo,
        // Asa direita
        CanhaoDireito,
        // Entrada de ar
        MotorEsquerdo,
        // FarolEsqcuerdo
        MotorDireito,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2

    };

    return NaveVertices;
}


#include "Nave.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {

    this->NaveCentro = NaveCentro; // Diz qual é o centro de onde o objeto será criado
    std::array<std::array<Vertex, 3>, 7> NaveModel = this->getNaveModel(); // Modelo Base

    this->modeloDaNave = NaveModel; // Acopla modelo base

    // Define o UP da nave
    this->NaveUp = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right da nave
    this->naveRight = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrixNave(this->modeloDaNave, Origem, this->NaveCentro);

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    this->CanhaoDireitoAtira = false;
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscala) {
    for (auto& parte : this->modeloDaNave) { // Para cada triangulo do objeto
        ScaleMatrix(parte, FatorDeEscala, this->NaveCentro); // Escala o triangulo
    }
    this->escala = FatorDeEscala;
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrixNave(this->modeloDaNave, this->NaveCentro, fatorDeTranslacao);
}

void Nave::rotacionaANave(float graus) {
    RotationMatrixNave(this->modeloDaNave, graus, this->NaveCentro, this->NaveUp, this->naveRight); // Rotaciona o OBJ em relação a seu centro
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

    // Texturas
    glm::vec2 TexturaCorpo{ 0.45f, 0.56f };
    glm::vec2 TexturaCanhaoDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaCanhaoEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    std::array<Vertex, 3> Corpo = { 
        Vertex{A, CorCorpo, {0.0f, 0.0f}},
        Vertex{C, AntiVerde, {1.0f, 0.0f}},
        Vertex{B, CorCorpo, {1.0f, 1.0f}} };

    std::array<Vertex, 3> CanhaoEsquerdo = { 
        Vertex{A, AntiVermelho}, 
        Vertex{E, AntiVerde}, 
        Vertex{D, AntiAzul} };

    std::array<Vertex, 3> CanhaoDireito = { 
        Vertex{C, AntiAzul}, 
        Vertex{G, AntiVermelho}, 
        Vertex{F, AntiVerde} };

    std::array<Vertex, 3> MotorEsquerdo = { 
        Vertex{A, CorMotorEsquerdo}, 
        Vertex{I, CorMotorEsquerdo}, 
        Vertex{H, CorMotorEsquerdo} };

    std::array<Vertex, 3> MotorDireito = { 
        Vertex{C, CorMotorDireito}, 
        Vertex{K, CorMotorDireito}, 
        Vertex{J, CorMotorDireito} };

    std::array<Vertex, 3> BoudingBox1 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox}, 
        Vertex{BoundingBoxB, CorBoudingBox} };

    std::array<Vertex, 3> BoudingBox2 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxD, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox} };


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

void Nave::MoveRight(float Amount) {
    this->rotacionaANave(Amount);
}

Missil Nave::Atira(float velocidade) {

    if (this->CanhaoDireitoAtira) {

        Missil missil(this->modeloDaNave[2][1].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(this->modeloDaNave[1][1].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}


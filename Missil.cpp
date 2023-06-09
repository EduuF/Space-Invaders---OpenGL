#include "Missil.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Missil::Missil() {};

Missil::Missil(bool NaveOuAlien, glm::vec4 Centro, glm::vec4 direcao, float velocidade) {

    this->Centro = Centro; // Diz qual � o centro de onde o objeto ser� criado
    this->NaveOuAlien = NaveOuAlien;
    std::vector<std::vector<Vertex>> Model = this->getModel(this->NaveOuAlien); // Modelo Base
    
    this->modelo = Model; // Acopla modelo base
    this->velocidade = velocidade;

    // Define UP como y
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };

    // Altera os v�rtices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->modelo, Origem, this->Up ,this->Centro);    

    // Graus da direcao em rela��o � Origem
    glm::vec3 yAxis = glm::normalize(this->Up);
    glm::vec3 v2 = glm::normalize(direcao);
    float dotProduct = glm::dot(yAxis, v2);
    float angleRad = acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    if (v2.x > yAxis.x) {
        graus = -graus;
    }

    this->rotaciona(graus);

    this->ajustaEscala(glm::vec3{ 1.3f, 1.3f, 0.0f });

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}

Missil::~Missil() {};

void Missil::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->modelo, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Missil::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->modelo, this->Centro, this->Up, fatorDeTranslacao);
}

void Missil::rotaciona(float graus) {
    RotationMatrix(this->modelo, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em rela��o ao centro do OBJ
}

void Missil::moveFoward() {    
    //Encontra o angulo entre 2 vetores
    glm::vec3 v1 = glm::vec3{0.0f, 1.0f, 0.0f};
    glm::vec3 v2 = this->Up;
    float dotProduct = glm::dot(v1, v2);
    float angleRad = glm::acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    if (v2.x > v1.x) {
        graus = -graus;
    }

    glm::vec3 fatorDeTranslacao{ this->Centro.x, 0.0f, 0.0f };
    RotacionaEmRelacaoAOrigem(this->modelo, -graus, this->Centro, this->Up, this->Right);
    this->translada(glm::vec3{ 0.0f, this->velocidade, 0.0f });
    RotacionaEmRelacaoAOrigem(this->modelo, graus, this->Centro, this->Up, this->Right);
}


std::vector<std::vector<Vertex>> Missil::getModel(bool NaveOuAlien) {

    glm::vec4 A{ 0.0f, 0.0f,  0.0f, 1.0f };
    glm::vec4 B{ 0.0f, 0.0f,  0.0f, 1.0f };
    glm::vec4 C{ 0.0f, 0.0f,  0.0f, 1.0f };
    glm::vec4 D{ 0.0f, 0.0f,  0.0f, 1.0f };

    // Cores
    glm::vec4 CorMissil{ 0.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    // Texturas
    glm::vec2 TexturaMissil{ 1.0f, 1.0f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    if (NaveOuAlien) {
        // Modela o tiro da nave
        A = glm::vec4{ -0.02f, -0.00f,  0.0f, 1.0f };
        B = glm::vec4{ -0.00f,  0.02f,  0.0f, 1.0f };
        C = glm::vec4{ 0.02f,  0.00f,  0.0f, 1.0f };
        D = glm::vec4{ 0.00f, -0.02f,  0.0f, 1.0f };

        // Cores
        CorMissil = glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f };
        CorBoudingBox = glm::vec4{ 0.0f, 0.0f, 0.0f, 1.0f };

        // Texturas
        TexturaMissil = glm::vec2{ 1.0f, 1.0f };
        TexturaBoudingBox = glm::vec2{ 1.0f, 1.0f };
    }
    else {
        // Modela o tiro do Alien
        A = glm::vec4{ -0.01f,  0.00f,  0.0f, 1.0f };
        B = glm::vec4{  0.00f,  0.03f,  0.0f, 1.0f };
        C = glm::vec4{  0.01f,  0.00f,  0.0f, 1.0f };
        D = glm::vec4{  0.00f, -0.03f,  0.0f, 1.0f };

        // Cores
        CorMissil = glm::vec4 {0.35f, 0.90f, 0.20f, 1.0f };
        CorBoudingBox = glm::vec4{ 0.0f, 0.0f, 0.0f, 1.0f };

        // Texturas
        TexturaMissil = glm::vec2{ 1.0f, 1.0f };
        TexturaBoudingBox = glm::vec2{ 1.0f, 1.0f };
    }
    

    // Bouding Box 
    glm::vec4 BoundingBoxA = A;
    glm::vec4 BoundingBoxB = B;
    glm::vec4 BoundingBoxC = C;
    glm::vec4 BoundingBoxD = D;

    std::vector<Vertex> Missil1 = {
        Vertex{A, CorMissil},
        Vertex{D, CorMissil},
        Vertex{B, CorMissil} };

    std::vector<Vertex> Missil2 = {
        Vertex{D, CorMissil},
        Vertex{C, CorMissil},
        Vertex{B, CorMissil} };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxC, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxB, CorBoudingBox, {0.0f, 0.0f}} };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxD, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxC, CorBoudingBox, {0.0f, 0.0f}} };


    std::vector<std::vector<Vertex>> MissilVertices = {

        // Corpo
        Missil1,
        // Asa esquerda
        Missil2,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2

    };

    return MissilVertices;
}

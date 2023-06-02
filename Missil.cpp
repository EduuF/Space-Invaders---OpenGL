#include "Missil.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Missil::Missil() {};

Missil::Missil(glm::vec4 Centro, glm::vec4 direcao, float velocidade) {

    this->Centro = Centro; // Diz qual é o centro de onde o objeto será criado
    std::array<std::array<Vertex, 3>, 4> NaveModel = this->getModel(); // Modelo Base

    this->modelo = NaveModel; // Acopla modelo base
    this->velocidade = velocidade;

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrixMissil(this->modelo, Origem, this->Centro);

    // Define UP como y
    this->Up = glm::vec4{0.0f, 1.0f, 0.0f, 0.0f};

    // Graus da direcao em relação à Origem
    glm::vec3 v1 = glm::normalize(this->Up);
    glm::vec3 v2 = glm::normalize(glm::vec3{ this->Up.x, this->Up.y, this->Up.z});
    float dotProduct = glm::dot(v1, v2);
    float angleRad = acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    this->rotaciona(graus);
}

Missil::~Missil() {};

void Missil::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrixMissil(this->modelo, this->Centro, fatorDeTranslacao);
}

void Missil::rotaciona(float graus) {
    RotationMatrixMissil(this->modelo, graus, this->Centro, this->Up); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Missil::moveFoward() {    

    //Encontra o angulo entre 2 vetores
    std::cout << "Up1: " << glm::to_string(this->Up) << std::endl;
    glm::vec3 v1 = glm::normalize(this->Up);
    glm::vec3 v2 = glm::normalize(glm::vec3{0.0f, 1.0f, 0.0f});
    float dotProduct = glm::dot(v1, v2);
    float angleRad = acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    std::cout << "Up2: " << glm::to_string(this->Up) << std::endl;

    glm::vec3 fatorDeTranslacao{ this->Centro.x, this->Centro.y, this->Centro.z };
    this->translada(-1.0f * fatorDeTranslacao);
    this->rotaciona(-graus);
    this->translada(glm::vec3{ 0.0f, this->velocidade, 0.0f });
    this->rotaciona(graus);
    this->translada(fatorDeTranslacao);
}


std::array<std::array<Vertex, 3>, 4> Missil::getModel() {

    // Modela a nave
    glm::vec4 A{ -0.01f, -0.01f,  0.0f, 1.0f };
    glm::vec4 B{ -0.1f,   0.01f,  0.0f, 1.0f };
    glm::vec4 C{ 0.01f, 0.01f,  0.0f, 1.0f };
    glm::vec4 D{ 0.01f, -0.01f,  0.0f, 1.0f };

    // Bouding Box 
    glm::vec4 BoundingBoxA = A;
    glm::vec4 BoundingBoxB = B;
    glm::vec4 BoundingBoxC = C;
    glm::vec4 BoundingBoxD = D;

    // Cores
    glm::vec4 CorMissil{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    // Texturas
    glm::vec2 TexturaMissil{ 1.0f, 1.0f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    std::array<Vertex, 3> Missil1 = {
        Vertex{A, CorMissil, {0.0f, 0.0f}},
        Vertex{D, CorMissil, {1.0f, 0.0f}},
        Vertex{B, CorMissil, {1.0f, 1.0f}} };

    std::array<Vertex, 3> Missil2 = {
        Vertex{D, CorMissil, {0.0f, 0.0f}},
        Vertex{B, CorMissil, {0.0f, 0.0f}},
        Vertex{C, CorMissil, {0.0f, 0.0f}} };

    std::array<Vertex, 3> BoudingBox1 = {
        Vertex{BoundingBoxA, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxC, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxB, CorBoudingBox, {0.0f, 0.0f}} };

    std::array<Vertex, 3> BoudingBox2 = {
        Vertex{BoundingBoxA, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxD, CorBoudingBox, {0.0f, 0.0f}},
        Vertex{BoundingBoxC, CorBoudingBox, {0.0f, 0.0f}} };


    std::array<std::array<Vertex, 3>, 4> MissilVertices = {

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

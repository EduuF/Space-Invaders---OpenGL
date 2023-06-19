#include "Missil.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Missil::Missil() {};

Missil::Missil(bool NaveOuAlien, glm::vec4 Centro, glm::vec4 direcao, float velocidade) {

    this->Centro = Centro; // Diz qual é o centro de onde o objeto será criado
    this->NaveOuAlien = NaveOuAlien;
    
    this->Vertices = this->getMissilVertices(this->NaveOuAlien);
    this->Indices = this->getMissilIndices(this->NaveOuAlien);

    this->velocidade = velocidade;

    // Define UP como y
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up ,this->Centro);

    // Graus da direcao em relação à Origem
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
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Missil::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void Missil::rotaciona(float graus) {
    RotationMatrix(this->Vertices, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
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
    RotacionaEmRelacaoAOrigem(this->Vertices, -graus, this->Centro, this->Up, this->Right);
    this->translada(glm::vec3{ 0.0f, this->velocidade, 0.0f });
    RotacionaEmRelacaoAOrigem(this->Vertices, graus, this->Centro, this->Up, this->Right);
}
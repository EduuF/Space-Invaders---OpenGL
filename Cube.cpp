#include "Cube.h"
#include <iostream>

Cube::Cube(glm::vec4 Centro, glm::vec4 Cor) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = Centro;

    this->Cor = Cor;

    this->Vertices = this->getCubeVertices();
    this->Indices = this->getCubeIndices();
    
    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);

    this->ajustaEscala(glm::vec3{ 0.015f, 0.015f, 0.015f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}

void Cube::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void Cube::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro);
    this->escala *= FatorDeEscala;
}

void Cube::moveFoward(float DeltaTime, float velocidadeDeDescidaDoPowerUp) {
    glm::vec3 fatorDeTranslacao{ 0.0f, -1.0f * DeltaTime * velocidadeDeDescidaDoPowerUp * 4 , 0.0f };
    this->translada(fatorDeTranslacao);
}
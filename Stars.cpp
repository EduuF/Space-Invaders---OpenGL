#include "Stars.h"
#include <iostream>
Stars::Stars(float eixoX, float Brilho, float Profundidade) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{eixoX, 4.0f, Profundidade, 1.0f};

    this->Vertices = this->getStarsVertices(this->Brilho);
    this->Indices = this->getStarsIndices();

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.7f, 0.7f, 0.0f });

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    //std::cout << " EixoXDaEstrelha: " << eixoX << " BrilhoEstrela: " << Brilho << " Profundidade: " << Profundidade << std::endl;
    //std::cout << glm::to_string(this->Centro) << std::endl;
}

void Stars::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void Stars::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro);
    this->escala *= FatorDeEscala;
}

void Stars::moveFoward(float DeltaTime, float velocidadeDeDescidaDoPowerUp) {
    glm::vec3 fatorDeTranslacao{ 0.0f, -1.0f * DeltaTime * velocidadeDeDescidaDoPowerUp*2 , 0.0f };
    this->translada(fatorDeTranslacao);
}
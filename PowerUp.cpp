#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(glm::vec4 Centro, int tipo) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = Centro;
    this->tipo = tipo;

    this->Vertices = this->getPowerUpVertices();
    this->Indices = this->getPowerUpIndices(this->tipo);

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.7f, 0.7f, 0.0f });

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}

void PowerUp::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void PowerUp::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro);
    this->escala *= FatorDeEscala;
}

void PowerUp::moveOPowerUp(float DeltaTime, float velocidadeDeDescidaDoPowerUp) {
    glm::vec3 fatorDeTranslacao{ 0.0f, -1.0f * DeltaTime * velocidadeDeDescidaDoPowerUp , 0.0f };
    this->translada(fatorDeTranslacao);
}
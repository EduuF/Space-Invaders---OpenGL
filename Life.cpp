#include "Life.h"
#include <iostream>

Life::Life(glm::vec4 Centro) {
    this->Centro = Centro;
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };

    this->Vertices = this->getLifeVertices();
    this->Indices = this->getLifeIndices();

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.2f, 0.2f, 0.0f });
}

void Life::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void Life::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro);
}
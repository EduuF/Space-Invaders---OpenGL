#include "Bomba.h"
#include "Triangle.h"
#include <array>

Bomba::Bomba() {};

Bomba::~Bomba() {};

Bomba::Bomba(glm::vec4 Centro, float CountDown) {
    this->Vertices = this->getBombaVertices();
    this->Indices = this->getBombaIndices();
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{ Centro.x, Centro.y - 0.12f, 0.0f, 1.0f };

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    this->Dropada = false;
    this->Aumentando = true;
    this->CountDown = CountDown;

    this->ajustaEscala(glm::vec3{ 1.5f, 1.5f, 0.0f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}


void Bomba::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up ,fatorDeTranslacao);
}

void Bomba::rotaciona(float graus) {
    RotationMatrix(this->Vertices, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Bomba::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Bomba::ajustaEixoZ() {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, glm::vec3{ 0.0f, 0.0f, 0.0f - this->Centro.z});
}

void Bomba::pisca(float DeltaTime, float intensidadeDePiscada, float velocidadeDePiscada) {
    if (this->escala.x >= intensidadeDePiscada) {
        this->Aumentando = false;
    }
    if (this->escala.x <= 0.9f) {
        this->Aumentando = true;
    }

    if (this->Aumentando) {
        this->ajustaEscala(glm::vec3{ 1 + DeltaTime * velocidadeDePiscada, 1 + DeltaTime * velocidadeDePiscada, 0.0f });
    }
    else {
        this->ajustaEscala(glm::vec3{ 1 - DeltaTime * velocidadeDePiscada, 1 - DeltaTime * velocidadeDePiscada, 0.0f });
    }
}
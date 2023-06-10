#include "Stars.h"
#include <iostream>
Stars::Stars(float eixoX, float Brilho, float Profundidade) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{eixoX, 2.99f, Profundidade, 1.0f};

    this->Model = this->getModel(this->Brilho);

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.4f, 0.4f, 0.0f });

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    //std::cout << " EixoXDaEstrelha: " << eixoX << " BrilhoEstrela: " << Brilho << " Profundidade: " << Profundidade << std::endl;
    //std::cout << glm::to_string(this->Centro) << std::endl;
}

void Stars::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Model, this->Centro, this->Up, fatorDeTranslacao);
}

void Stars::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Model, FatorDeEscala, this->Centro);
    this->escala *= FatorDeEscala;
}

void Stars::moveFoward(float DeltaTime, float velocidadeDeDescidaDoPowerUp) {
    glm::vec3 fatorDeTranslacao{ 0.0f, -1.0f * DeltaTime * velocidadeDeDescidaDoPowerUp*3 , 0.0f };
    this->translada(fatorDeTranslacao);
}

std::vector<std::vector<Vertex>> Stars::getModel(int Brilho) {

    float BrilhoDaEstrela = static_cast<float>(Brilho) / 100.0f;

    // Modela a nave
    glm::vec4 A{ 0.0f, 0.02f,  0.0f, 1.0f };
    glm::vec4 B{ -0.01f,   -0.01f,  0.0f, 1.0f };
    glm::vec4 C{ 0.01f, -0.01f,  0.0f, 1.0f };
    glm::vec4 D{ -0.01f, 0.01f,  0.0f, 1.0f };
    glm::vec4 E{ 0.0f, -0.02f,  0.0f, 1.0f };
    glm::vec4 F{ 0.01f,  0.01f,   0.0f, 1.0f };

    // Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde{ 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho{ 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde{ 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul{ 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo{ 0.50f, 0.50f, 1.00f, 1.0f };
    glm::vec4 CorCorpo2{ 0.90f, 0.40f, 0.77f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    std::vector<Vertex> Estrela1 = {
        Vertex{A, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f -BrilhoDaEstrela}},
        Vertex{B, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela}},
        Vertex{C, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela}} };

    std::vector<Vertex> Estrela2 = {
        Vertex{D, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela}},
        Vertex{E, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela}},
        Vertex{F, glm::vec4{1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela, 1.0f - BrilhoDaEstrela}} };

    std::vector<std::vector<Vertex>> EstrelaVertices = {

        // Aletas
        Estrela1,
        Estrela2

    };

    return EstrelaVertices;
}
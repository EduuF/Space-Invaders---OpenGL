#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(glm::vec4 Centro, int tipo) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = Centro;
    this->tipo = tipo;

    this->Model = this->getModel(tipo);    

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.4f, 0.4f, 0.0f });

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}

void PowerUp::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Model, this->Centro, this->Up, fatorDeTranslacao);
}

void PowerUp::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Model, FatorDeEscala, this->Centro); 
    this->escala *= FatorDeEscala;
}

void PowerUp::moveOPowerUp(float DeltaTime, float velocidadeDeDescidaDoPowerUp) {
    glm::vec3 fatorDeTranslacao{ 0.0f, -1.0f * DeltaTime * velocidadeDeDescidaDoPowerUp , 0.0f };
    this->translada(fatorDeTranslacao);
}

std::vector<std::vector<Vertex>> PowerUp::getModel(int tipo) {

    std::cout << tipo << std::endl;

    // Modela a nave
    glm::vec4 A{ -0.08f, -0.08f,  0.0f, 1.0f };
    glm::vec4 B{ 0.0f,   0.12f,  0.0f, 1.0f };
    glm::vec4 C{ 0.08f, -0.08f,  0.0f, 1.0f };
    glm::vec4 D{ 0.0f, -0.12f,  0.0f, 1.0f };
    glm::vec4 E{ -0.08f, 0.08f,  0.0f, 1.0f };
    glm::vec4 F{ 0.08f,  0.08f,   0.0f, 1.0f };
    glm::vec4 G{ -0.12f,  0.0f,   0.0f, 1.0f };
    glm::vec4 H{ 0.0f, 0.08f,  0.0f, 1.0f };
    glm::vec4 I{ 0.0f, -0.08f,  0.0f, 1.0f };
    glm::vec4 J{ 0.12f, 0.0f,  0.0f, 1.0f };

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

    std::vector<Vertex> PowerUP1 = {
        Vertex{A, Azul},
        Vertex{C, Azul},
        Vertex{B, Azul} };

    std::vector<Vertex> PowerUP2 = {
        Vertex{D, Azul},
        Vertex{F, Azul},
        Vertex{E, Azul} };

    std::vector<Vertex> PowerUP3 = {
        Vertex{G, Azul},
        Vertex{I, Azul},
        Vertex{H, Azul} };

    std::vector<Vertex> PowerUP4 = {
        Vertex{I, Azul},
        Vertex{J, Azul},
        Vertex{H, Azul} };

    if (tipo == 0) {
        A = glm::vec4{ -0.08f, -0.12f,  0.0f, 1.0f };
        B = glm::vec4{ -0.02f,   0.0f,  0.0f, 1.0f };
        C = glm::vec4{ 0.08f, 0.0f,  0.0f, 1.0f };
        D = glm::vec4{ -0.08f, 0.0f,  0.0f, 1.0f };
        E = glm::vec4{ 0.02f, 0.0f,  0.0f, 1.0f };
        F = glm::vec4{ 0.08f,  0.12f,   0.0f, 1.0f };
        G = glm::vec4{ 0.0f, 0.0f,   0.0f, 1.0f };
        H = glm::vec4{ 0.0f, 0.0f,  0.0f, 1.0f };

         PowerUP1 = std::vector<Vertex>{
            Vertex{A, AntiAzul},
            Vertex{C, AntiAzul},
            Vertex{B, AntiAzul} };

         PowerUP2 = std::vector<Vertex>{
            Vertex{D, AntiAzul},
            Vertex{E, AntiAzul},
            Vertex{F, AntiAzul} };

         PowerUP3 = std::vector<Vertex>{
            Vertex{G},
            Vertex{G},
            Vertex{G} };

         PowerUP4 = std::vector<Vertex>{
            Vertex{G},
            Vertex{G},
            Vertex{G} };

    }
    else if (tipo == 1) {
        A = glm::vec4{ -0.08f, -0.12f,  0.0f, 1.0f };
        B = glm::vec4{ -0.12f, -0.08f,  0.0f, 1.0f };
        C = glm::vec4{ 0.12f, 0.08f,  0.0f, 1.0f };
        D = glm::vec4{ 0.08f, 0.12f,  0.0f, 1.0f };
        E = glm::vec4{ -0.12f, 0.08f,  0.0f, 1.0f };
        F = glm::vec4{ 0.08f,  -0.12f,   0.0f, 1.0f };
        G = glm::vec4{ 0.12f, -0.08f,   0.0f, 1.0f };
        H = glm::vec4{ -0.08f, 0.12f,  0.0f, 1.0f };

         PowerUP1 = std::vector<Vertex>{
            Vertex{A, Vermelho},
            Vertex{C, Vermelho},
            Vertex{B, Vermelho} };

         PowerUP2 = std::vector<Vertex>{
            Vertex{B, Vermelho},
            Vertex{C, Vermelho},
            Vertex{D, Vermelho} };

         PowerUP3 = std::vector<Vertex>{
            Vertex{E, Vermelho},
            Vertex{F, Vermelho},
            Vertex{G, Vermelho} };

         PowerUP4 = std::vector<Vertex>{
            Vertex{E, Vermelho},
            Vertex{G, Vermelho},
            Vertex{H, Vermelho} };

    }

    std::vector<std::vector<Vertex>> PowerUpVertices = {

        // Aletas
        PowerUP1,
        PowerUP2,
        // Corpo
        PowerUP3,
        PowerUP4

    };

    return PowerUpVertices;
}
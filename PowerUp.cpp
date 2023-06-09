#include "PowerUp.h"

PowerUp::PowerUp(glm::vec4 Centro, int tipo) {
    glm::vec4 Cor{ 1.0f, 1.0f, 0.0f, 1.0f };
    if (tipo == 0) {
        Cor = glm::vec4{ 0.66f, 0.33f, 0.20f, 1.0f };
    } else if (tipo == 1) {
        Cor = glm::vec4{ 0.30f, 0.50f, 0.60f, 1.0f };
    } else if (tipo == 2) {
        Cor = glm::vec4{ 0.75f, 0.10f, 0.40f, 1.0f };
    } else if (tipo == 3) {
        Cor = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f };
    }

    this->Model = this->getModel(Cor);
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = Centro;
    this->tipo = tipo;

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);

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

std::vector<std::vector<Vertex>> PowerUp::getModel(glm::vec4 Cor) {

    // Modela a nave
    glm::vec4 A{ -0.036f, 0.036f,  0.0f, 1.0f };
    glm::vec4 B{ -0.036f,   -0.036f,  0.0f, 1.0f };
    glm::vec4 C{ 0.036f, -0.036f,  0.0f, 1.0f };
    glm::vec4 D{ 0.036f, 0.036f,  0.0f, 1.0f };
    glm::vec4 E{ 0.00f, 0.036f,  0.0f, 1.0f };
    glm::vec4 F{ -0.036f,  0.0f,   0.0f, 1.0f };
    glm::vec4 G{ 0.036f,  0.0f,   0.0f, 1.0f };
    glm::vec4 H{ 0.0f, -0.036f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde{ 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho{ 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde{ 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul{ 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo{ 0.80f, 0.30f, 0.67f, 1.0f };
    glm::vec4 CorCorpo2{ 0.90f, 0.40f, 0.77f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    std::vector<Vertex> PowerUP1 = {
        Vertex{A, Cor},
        Vertex{H, Cor},
        Vertex{G, Cor} };

    std::vector<Vertex> PowerUP2 = {
        Vertex{F, Cor},
        Vertex{H, Cor},
        Vertex{D, Cor} };

    std::vector<Vertex> PowerUP3 = {
        Vertex{F, Cor},
        Vertex{C, Cor},
        Vertex{E, Cor} };

    std::vector<Vertex> PowerUP4 = {
        Vertex{B, Cor},
        Vertex{G, Cor},
        Vertex{E, Cor} };



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
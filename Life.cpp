#include "Life.h"
#include <iostream>

Life::Life(glm::vec4 Centro) {
    this->Centro = Centro;
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };

    this->Model = this->getModel();

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);
    this->ajustaEscala(glm::vec3{ 0.2f, 0.2f, 0.0f });
}

void Life::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Model, this->Centro, this->Up, fatorDeTranslacao);
}

void Life::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Model, FatorDeEscala, this->Centro);
}

std::vector<std::vector<Vertex>> Life::getModel() {

    // Modela a nave
    glm::vec4 A{ 0.0f,  0.1f,  0.0f, 1.0f };
    glm::vec4 B{ 0.0f, -0.35f,  0.0f, 1.0f };
    glm::vec4 C{ -0.35f, 0.0f,  0.0f, 1.0f };
    glm::vec4 D{ -0.1f, 0.2f,  0.0f, 1.0f };
    glm::vec4 E{ -0.25f, 0.2f,  0.0f, 1.0f };
    glm::vec4 AntiC{ 0.35f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiD{ 0.1f, 0.2f,  0.0f, 1.0f };
    glm::vec4 AntiE{ 0.25f, 0.2f,  0.0f, 1.0f };

    // Cores
    glm::vec4 VermelhoEscuro{ 0.70f, 0.10f, 0.10f, 1.0f };
    glm::vec4 VermelhoClaro{ 0.85f, 0.25f, 0.25f, 1.0f };
    glm::vec4 VermelhoMaisClaro{ 1.0f, 0.40f, 0.40f, 1.0f };

    std::vector<Vertex> Life1 = {
        Vertex{A, VermelhoEscuro},
        Vertex{C, VermelhoEscuro},
        Vertex{B, VermelhoEscuro} };

    std::vector<Vertex> Life2 = {
        Vertex{A, VermelhoEscuro},
        Vertex{D, VermelhoEscuro},
        Vertex{C, VermelhoEscuro} };

    std::vector<Vertex> Life3 = {
        Vertex{D, VermelhoEscuro},
        Vertex{E, VermelhoEscuro},
        Vertex{C, VermelhoEscuro} };

    std::vector<Vertex> Life4 = {
        Vertex{B, VermelhoClaro},
        Vertex{AntiC, VermelhoClaro},
        Vertex{A, VermelhoClaro} };

    std::vector<Vertex> Life5 = {
        Vertex{A, VermelhoClaro},
        Vertex{AntiC, VermelhoClaro},
        Vertex{AntiD, VermelhoClaro} };

    std::vector<Vertex> Life6 = {
        Vertex{AntiD, VermelhoMaisClaro},
        Vertex{AntiC, VermelhoMaisClaro},
        Vertex{AntiE, VermelhoMaisClaro} };

    std::vector<std::vector<Vertex>> LifeVertices = {

        // Coracao
        Life1,
        Life2,
        Life3,
        Life4,
        Life5,
        Life6

    };

    return LifeVertices;
}
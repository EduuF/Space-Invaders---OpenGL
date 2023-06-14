#include "Smoke.h"
#include "Triangle.h"
#include <array>
#include <iostream>

Smoke::Smoke() {};

Smoke::~Smoke() {};

Smoke::Smoke(glm::vec4 Centro, glm::vec4 direcao) {
    this->Model = this->getModel();
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{ Centro.x, Centro.y - 0.12f, 0.0f, 1.0f };

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);

    // Graus da direcao em relação à Origem

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 30);
    float angleRandomness = dist(gen) - 15; 

    glm::vec3 yAxis = glm::normalize(this->Up);
    glm::vec3 v2 = glm::normalize(direcao);
    float dotProduct = glm::dot(yAxis, v2);
    float angleRad = acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    if (v2.x > yAxis.x) {
        graus = -graus;
    }

    this->rotaciona(graus + angleRandomness);
    this->ajustaEscala(glm::vec3{ 4.5f, 4.5f, 4.5f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };

    std::uniform_int_distribution<int> distrotacionaCimaBaixo(0, 1);
    this->rotacionaCimaBaixo = distrotacionaCimaBaixo(rd);

    // Define a velocidade da fumaça
    std::uniform_real_distribution<> distVelocidade(3.0f, 5.0f);
    this->velocidade = static_cast<float>(distVelocidade(gen));
}


void Smoke::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Model, this->Centro, this->Up, fatorDeTranslacao);
}

void Smoke::rotaciona(float graus) {
    RotationMatrix(this->Model, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Smoke::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Model, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Smoke::moveFoward(float DeltaTime) {
    this->tempoDeVida -= DeltaTime;

    //Encontra o angulo entre 2 vetores
    glm::vec3 v1 = glm::vec3{ 0.0f, 1.0f, 0.0f };
    glm::vec3 v2 = this->Up;
    float dotProduct = glm::dot(v1, v2);
    float angleRad = glm::acos(dotProduct);
    float graus = angleRad * 180.0f / glm::pi<float>();

    if (v2.x > v1.x) {
        graus = -graus;
    }

    glm::vec3 fatorDeTranslacao{ this->Centro.x, 0.0f, 0.0f };
    RotacionaEmRelacaoAOrigem(this->Model, -graus, this->Centro, this->Up, this->Right);
    this->translada(glm::vec3{ 0.0f, DeltaTime * this->tempoDeVida / this->velocidade , 0.0f });
    RotacionaEmRelacaoAOrigem(this->Model, graus, this->Centro, this->Up, this->Right);

    // Faz a particula desaparecer aos poucos
    glm::vec4 Cor{ 0.9f  , 0.9f, 0.9f , this->tempoDeVida };
    for (auto& triangle : this->Model) {
        for (auto& vertice : triangle) {
            vertice.Color = Cor;
        }
    }

    // Aumenta o tamanho com o tempo
    if (this->escala.x <= 1.5f) {
        this->ajustaEscala(this->escala += DeltaTime / 100);
        std::cout << "this->escala: " << glm::to_string(this->escala) << std::endl;
    }    

    // Rotaciona um pouco com o tempo
    if (this->rotacionaCimaBaixo == 0) {
        this->rotaciona((30.0f * DeltaTime));
    } else {
        this->rotaciona((-30.0f * DeltaTime));
    }
}


std::vector<std::vector<Vertex>> Smoke::getModel() {

    // Modela a nave
    glm::vec4 A{ -0.002f, -0.002f,  0.0f, 1.0f };
    glm::vec4 B{ -0.002f,  0.002f,  0.0f, 1.0f };
    glm::vec4 C{  0.002f,  0.002f,  0.0f, 1.0f };
    glm::vec4 D{  0.002f, -0.002f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Cor{ 0.8f , 0.8f , 0.8f , 1.0f };

    std::vector<Vertex> Triangulo1 = {
        Vertex{A, Cor},
        Vertex{B, Cor},
        Vertex{C, Cor} };

    std::vector<Vertex> Triangulo2 = {
        Vertex{A, Cor},
        Vertex{C, Cor},
        Vertex{D, Cor} };

    std::vector<std::vector<Vertex>> SmokeVertices = {

        // Aletas
        Triangulo1,
        Triangulo2

    };

    return SmokeVertices;
}
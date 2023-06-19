#include "Smoke.h"
#include "Triangle.h"
#include <array>
#include <iostream>

Smoke::Smoke() {};

Smoke::~Smoke() {};

Smoke::Smoke(glm::vec4 Centro, glm::vec4 direcao) {
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{ Centro.x, Centro.y - 0.12f, 0.0f, 1.0f };

    this->Vertices = this->getSmokeVertices();
    this->Indices = this->getSmokeIndices();

    // Altera os v�rtices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up, this->Centro);

    // Graus da direcao em rela��o � Origem

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
    this->ajustaEscala(glm::vec3{ 3.5f, 3.5f, 3.5f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };

    std::uniform_int_distribution<int> distrotacionaCimaBaixo(0, 1);
    this->rotacionaCimaBaixo = distrotacionaCimaBaixo(rd);

    // Define a velocidade da fuma�a
    std::uniform_real_distribution<> distVelocidade(3.0f, 5.0f);
    this->velocidade = static_cast<float>(distVelocidade(gen));
}


void Smoke::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up, fatorDeTranslacao);
}

void Smoke::rotaciona(float graus) {
    RotationMatrix(this->Vertices, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em rela��o ao centro do OBJ
}

void Smoke::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro); // Escala o triangulo
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
    RotacionaEmRelacaoAOrigem(this->Vertices, -graus, this->Centro, this->Up, this->Right);
    this->translada(glm::vec3{ 0.0f, DeltaTime * this->tempoDeVida / this->velocidade , 0.0f });
    RotacionaEmRelacaoAOrigem(this->Vertices, graus, this->Centro, this->Up, this->Right);

    // Faz a particula desaparecer aos poucos
    glm::vec4 Cor{ 1.0f - this->tempoDeVida / 5.0f  , 1.0f - this->tempoDeVida / 5.0f, 1.0f - this->tempoDeVida / 5.0f , this->tempoDeVida };
    for (auto& vertice : this->Vertices) {
        vertice.Color = Cor;
    }

    // Aumenta o tamanho com o tempo
    if (this->escala.x <= 1.5f) {
        this->ajustaEscala(this->escala += DeltaTime / 100);
        std::cout << "this->escala: " << glm::to_string(this->escala) << std::endl;
    }    

    // Rotaciona um pouco com o tempo
    if (this->rotacionaCimaBaixo == 0) {
        this->rotaciona((45.0f * DeltaTime));
    } else {
        this->rotaciona((-45.0f * DeltaTime));
    }
}
#ifndef SMOKE_H
#define SMOKE_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include <random>
#include "Triangle.h"
#include "Matrices.h"

class Smoke {
public:

    int rotacionaCimaBaixo;

    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;
    glm::vec3 escala;

    float tempoDeVida = 0.7f; // SmoothStop // Faz particula desaparecer aos poucos

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getSmokeVertices();
    std::vector<glm::ivec3> getSmokeIndices();

    float velocidade;

    Smoke(glm::vec4 Centro, glm::vec4 direcao);
    Smoke();
    ~Smoke();

    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);
    void ajustaEscala(glm::vec3 FatorDeEscala);
    void moveFoward(float DeltaTime);

    std::vector<std::vector<Vertex>> getModel();

};

#endif
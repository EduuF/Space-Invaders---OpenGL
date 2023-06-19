#ifndef STARS_H
#define STARS_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Matrices.h"

class Stars {
public:
    int Brilho;
    int Profundidade;

    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;
    glm::vec3 escala;

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getStarsVertices(int Brilho);
    std::vector<glm::ivec3> getStarsIndices();

    float velocidade;

    Stars(float eixoX, float Brilho, float Profundidade);

    void translada(glm::vec3 fatorDeTranslacao);
    void ajustaEscala(glm::vec3 FatorDeEscala);
    void moveFoward(float DeltaTime, float velocidadeDeDescidaDoPowerUp);

    std::vector<std::vector<Vertex>> getModel(int brilho);
};

#endif

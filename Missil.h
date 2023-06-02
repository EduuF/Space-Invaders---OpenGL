#ifndef MISSIL_H
#define MISSIL_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"

class Missil {
public:
    glm::vec4 Centro;
    glm::vec4 Up;

    float velocidade;

    Missil(glm::vec4 Centro, glm::vec4 direcao, float velocidade);
    Missil();
    ~Missil();

    std::array<std::array<Vertex, 3>, 4> modelo;

    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);

    void moveFoward();

    std::array<std::array<Vertex, 3>, 4> getModel();

};

#endif
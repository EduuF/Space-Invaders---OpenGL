#ifndef MISSIL_H
#define MISSIL_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"

class Missil {
public:
    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;

    bool NaveOuAlien;

    float velocidade;

    Missil(bool NaveOuAlien, glm::vec4 Centro, glm::vec4 direcao, float velocidade);
    Missil();
    ~Missil();

    std::vector<std::vector<Vertex>> modelo;

    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);

    void moveFoward();

    std::vector<std::vector<Vertex>> getModel(bool NaveOuAlien);

};

#endif
#ifndef CUBE_H
#define CUBE_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Matrices.h"

class Cube {
public:
    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;
    glm::vec3 escala;
    glm::vec4 Cor;

    Cube(glm::vec4 Centro, glm::vec4 Cor);
    Cube();

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getCubeVertices();
    std::vector<glm::ivec3> getCubeIndices();


    void ajustaEscala(glm::vec3 FatorDeEscala);
    void translada(glm::vec3 fatorDeTranslacao);
    void moveFoward(float DeltaTime, float velocidadeDeDescidaDoPowerUp);
};

#endif
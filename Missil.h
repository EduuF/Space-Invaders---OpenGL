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
    glm::vec3 escala;

    bool NaveOuAlien;

    float velocidade;

    Missil(bool NaveOuAlien, glm::vec4 Centro, glm::vec4 direcao, float velocidade);
    Missil();
    ~Missil();

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getMissilVertices(bool NaveOuAlien);
    std::vector<glm::ivec3> getMissilIndices(bool NaveOuAlien);


    void ajustaEscala(glm::vec3 FatorDeEscala);
    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);

    void moveFoward();

};

#endif
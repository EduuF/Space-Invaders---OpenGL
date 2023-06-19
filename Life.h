#ifndef LIFE_H
#define LIFE_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Matrices.h"

class Life {
public:
    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getLifeVertices();
    std::vector<glm::ivec3> getLifeIndices();

    Life(glm::vec4 Centro);

    void translada(glm::vec3 fatorDeTranslacao);
    void ajustaEscala(glm::vec3 FatorDeEscala);

    std::vector<std::vector<Vertex>> getModel();
};

#endif

#ifndef BOMBA_H
#define BOMBA_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Matrices.h"

class Bomba {
public:
    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;
    glm::vec3 escala;

    bool Descendo;
    bool Dropada;
    bool Aumentando;

    float CountDown;
    float velocidade;    

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getBombaVertices();
    std::vector<glm::ivec3> getBombaIndices();

    Bomba(glm::vec4 Centro, float CountDown);
    Bomba();
    ~Bomba();

    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);
    void ajustaEscala(glm::vec3 FatorDeEscala);
    void ajustaEixoZ();

    void pisca(float DeltaTime, float intensidadeDePiscada, float velocidadeDePiscada);

};

#endif
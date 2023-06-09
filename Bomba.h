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
    

    std::vector<std::vector<Vertex>> Model;

    float velocidade;

    Bomba(glm::vec4 Centro, float CountDown);
    Bomba();
    ~Bomba();

    void translada(glm::vec3 fatorDeTranslacao);
    void rotaciona(float graus);
    void ajustaEscala(glm::vec3 FatorDeEscala);
    void ajustaEixoZ();

    std::vector<std::vector<Vertex>> getModel();

    void pisca(float DeltaTime, float intensidadeDePiscada, float velocidadeDePiscada);

};

#endif
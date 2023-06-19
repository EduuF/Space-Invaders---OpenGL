#ifndef POWERUP_H
#define POWERUP_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Matrices.h"

class PowerUp {
public:
	int tipo;

    glm::vec4 Centro;
    glm::vec4 Up;
    glm::vec4 Right;
    glm::vec3 escala;


    bool Descendo;

    std::vector<Vertex> Vertices;
    std::vector<glm::ivec3> Indices;

    std::vector<Vertex> getPowerUpVertices();
    std::vector<glm::ivec3> getPowerUpIndices(int tipo);

    float velocidade;

    PowerUp(glm::vec4 Centro, int tipo);

    void translada(glm::vec3 fatorDeTranslacao);
    void ajustaEscala(glm::vec3 FatorDeEscala);
    void moveOPowerUp(float DeltaTime, float velocidadeDeDescidaDoPowerUp);

    std::vector<std::vector<Vertex>> getModel(int tipo);
};

#endif

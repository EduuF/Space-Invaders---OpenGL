#ifndef NAVE_H
#define NAVE_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Missil.h"

class Nave {
public:
    glm::vec4 NaveCentro;
    glm::vec4 NaveUp;
    glm::vec4 naveRight;
    glm::vec3 escala;

    bool CanhaoDireitoAtira;
    bool intangivel;
    bool piscando;

    int life;

    float tempoDeIntangibilidade;
    float TempoPiscando;

	Nave(glm::vec4 NaveCentro);

    std::vector<glm::ivec3> modeloDaNave;

    void ajustaEscalaDaNave(glm::vec3 FatorDeEscala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus);

    std::vector<glm::ivec3> getNaveModel();

    void MoveRight(float Amount);
    void MoveNaveLateralmente(double MouseXPos, float VelocidadeLateralNave);
    void pisca(float tempoDePiscada, float DeltaTime);
    void AtualizaTempoDeTangibilidade(float DeltaTime, float tempoDeIntangibilidadeNave);
    Missil Atira(float velocidade);

};

#endif
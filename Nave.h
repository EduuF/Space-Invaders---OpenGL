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

    int life;
    float tempoDeIntangibilidade;

	Nave(glm::vec4 NaveCentro);

    std::vector<std::vector<Vertex>> modeloDaNave;

    void ajustaEscalaDaNave(glm::vec3 FatorDeEscala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus);

    std::vector<std::vector<Vertex>> getNaveModel();

    void MoveRight(float Amount);
    Missil Atira(float velocidade);

};

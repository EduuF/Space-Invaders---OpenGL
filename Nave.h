#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"
#include "Missil.h"

class Nave {
public:
    glm::vec4 NaveCentro;
    glm::vec4 NaveUp;
    glm::vec4 naveRight;
    glm::vec3 escala;

    bool CanhaoDireitoAtira;

	Nave(glm::vec4 NaveCentro);

    std::array<std::array<Vertex, 3>, 7> modeloDaNave;

    void ajustaEscalaDaNave(glm::vec3 FatorDeEscala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus);

    std::array<std::array<Vertex, 3>, 7> getNaveModel();

    void MoveRight(float Amount);
    Missil Atira(float velocidade);

};

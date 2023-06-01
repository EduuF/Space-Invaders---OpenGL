#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"

class Nave {
public:
    glm::vec4 NaveCentro;

	Nave(glm::vec4 NaveCentro);

    std::array<std::array<Vertex, 3>, 7> modeloDaNave;

    void ajustaEscalaDaNave(glm::vec3 FatorDeEscala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus);

    std::array<std::array<Vertex, 3>, 7> getNaveModel();

};

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Nave {
public:
    glm::vec4 NaveCentro, BoundingBoxA, BoundingBoxB, BoundingBoxC, BoundingBoxD;
	Nave(glm::vec4 NaveCentro);

    std::array<std::array<glm::vec4, 3>, 5> modeloDaNave;

    void modelaANave();
    void ajustaEscalaDaNave(glm::vec3 FatorDeescala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus, glm::vec3 eixoDeRotacao);

};

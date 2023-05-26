#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Nave {
public:
    glm::vec4 NaveCentro;

	Nave(glm::vec4 NaveCentro);

    std::array<std::array<glm::vec4, 3>, 7> modeloDaNave;

    void ajustaEscalaDaNave(glm::vec3 FatorDeescala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    void rotacionaANave(float graus);

    std::array<std::array<glm::vec4, 3>, 7> getNaveModel();

};

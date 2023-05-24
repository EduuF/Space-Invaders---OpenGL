#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Nave {
public:
	float posicao, rotacao, escala;
	Nave(float posicao, float rotacao, float escala);

    std::array<std::array<glm::vec3, 3>, 7> modelaANave();
    std::array<std::array<glm::vec3, 3>, 7> ajustaEscalaDaNave();
    std::array<std::array<glm::vec3, 3>, 7> transladaANave();
    std::array<std::array<glm::vec3, 3>, 7> rotacionaANave();

};

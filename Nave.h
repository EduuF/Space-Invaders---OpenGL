#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Nave {
public:
	float posicao, rotacao, escala;
	Nave(float posicao, float rotacao, float escala);
    std::array<std::array<glm::vec4, 3>, 5> modeloDaNave;

    void modelaANave();
    void ajustaEscalaDaNave(glm::vec3 FatorDeescala);
    void transladaANave(glm::vec3 fatorDeTranslacao);
    //void rotacionaANave();

};

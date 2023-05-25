#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Alien {
public:
	float posicao, rotacao, escala;
	glm::vec4 AlienCentro;
	Alien(float posicao, float rotacao, float escala);
	std::array<std::array<glm::vec4, 3>, 16> modeloDoInimigo;
	
	void modelaAlien();
	//void ajustaEscalaDoAlien(glm::vec3 FatorDeescala);
	//void transladaOAlien(glm::vec3 fatorDeTranslacao);
	//void rotacionaOAlien(float graus, glm::vec3 eixoDeRotacao);
    
};

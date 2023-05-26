#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Alien {
public:
	glm::vec4 Centro, BoundingBoxA, BoundingBoxB, BoundingBoxC, BoundingBoxD;
	Alien(glm::vec4 Centro);

	std::array<std::array<glm::vec4, 3>, 16> modeloDoInimigo;
	void modelaAlien();
	//void ajustaEscalaDoAlien(glm::vec3 FatorDeescala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	//void rotacionaOAlien(float graus, glm::vec3 eixoDeRotacao);
    
};

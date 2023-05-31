#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Alien {
public:
	Alien();
	glm::vec4 Centro;
	Alien(glm::vec4 Centro);

	std::array<std::array<glm::vec4, 3>, 18> modeloDoInimigo;
	void ajustaEscalaDoAlien(glm::vec3 FatorDeescala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);

	void ProjetaAlien(glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle);


	std::array<std::array<glm::vec4, 3>, 18> getAlienModel();
    
};

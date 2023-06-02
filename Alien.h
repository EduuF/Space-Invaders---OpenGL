#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"

class Alien {
public:
	Alien();

	glm::vec4 Centro;
	glm::vec4 Up;

	Alien(glm::vec4 Centro);

	std::array<std::array<Vertex, 3>, 18> modeloDoInimigo;
	void ajustaEscalaDoAlien(glm::vec3 FatorDeEscala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);


	std::array<std::array<Vertex, 3>, 18> getAlienModel();
    
};

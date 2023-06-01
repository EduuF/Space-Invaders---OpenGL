#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"

class Alien {
public:
	Alien();
	glm::vec4 Centro;
	Alien(glm::vec4 Centro);

	std::array<std::array<Vertex, 3>, 18> modeloDoInimigo;
	void ajustaEscalaDoAlien(glm::vec3 FatorDeEscala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);

	void ProjetaAlien(float AspectRatio, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle);


	std::array<std::array<Vertex, 3>, 18> getAlienModel();
    
};

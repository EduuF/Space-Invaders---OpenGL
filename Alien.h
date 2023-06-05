#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"
#include "Missil.h"

class Alien {
public:

	bool disponível;

	Alien();

	glm::vec4 Centro;
	glm::vec4 Up;
	glm::vec4 Right;

	Alien(glm::vec4 Centro);

	bool CanhaoDireitoAtira;

	std::array<std::array<Vertex, 3>, 18> modeloDoInimigo;
	void ajustaEscalaDoAlien(glm::vec3 FatorDeEscala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);


	std::array<std::array<Vertex, 3>, 18> getAlienModel();
    
	Missil Atira(float velocidade);
	void DropaBomba();
};

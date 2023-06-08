#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Missil.h"
#include "Bomba.h"

class Alien {
public:

	glm::vec3 escala;

	int ID;
	bool disponível;
	bool hasBomb;
	bool ataca;
	bool recua;
	bool vivo;

	Bomba bomba;
	int life;

	double yOriginal;

	Alien();

	glm::vec4 Centro;
	glm::vec4 Up;
	glm::vec4 Right;

	Alien(glm::vec4 Centro);

	bool CanhaoDireitoAtira;

	std::vector<std::vector<Vertex>> modeloDoInimigo;
	void ajustaEscalaDoAlien(glm::vec3 FatorDeEscala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);


	std::vector<std::vector<Vertex>> getAlienModel();
    
	Missil Atira(float velocidade);
	void CarregaBomba();
};

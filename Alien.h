#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Alien {
public:
	float posicao, rotacao, escala;
	Alien(float posicao, float rotacao, float escala);
	std::array<std::array<glm::vec3, 3>, 16> modeloDoInimigo;
	
	void modelaAlien();
	void ajustaEscalaDoAlien(float escalar);
    
};

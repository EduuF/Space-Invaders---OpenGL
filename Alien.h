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
	bool dispon�vel;
	bool hasBomb;
	bool ataca;
	bool recua;
	bool vivo;
	bool intangivel;
	bool piscando;

	Bomba bomba;
	int life;

	double yOriginal;

	float tempoDeIntangibilidade;
	float TempoPiscando;

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
	void CarregaBomba(float CountDown);
	void pisca(float tempoDePiscada, float DeltaTime);
	void MoveAlienLateralmente(bool& AlienMoveLeft, float velocidadeInimigos, float DeltaTime);
	void AtacaEmEsquadrao(float localDeSobrevooDosAliens, glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe, float alturaDoPlaneta);
	void RecuaEmEsquadrao(glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe);
	void AtualizaTempoDeTangibilidade(float DeltaTime, float tempoDeIntangibilidadeAlien);
	void AtualizaEstadoDaBomba(float DeltaTime, glm::vec3 fatorDeTranslacaoEsquadrao, float intensidadePiscadaBombaDropada, float velocidadeDePiscadaBombaDropada);
};

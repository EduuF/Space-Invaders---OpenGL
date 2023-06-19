#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"
#include "Missil.h"
#include "Bomba.h"
#include "AlienModel.h"

class Alien {
public:

	glm::vec3 escala{ 1.0f, 1.0f, 1.0f };

	int ID;
	bool disponível;
	bool hasBomb;
	bool ataca;
	bool recua;
	bool vivo;
	bool intangivel;
	bool piscando;
	bool sobeAsa;

	Bomba bomba;
	int life;
	int skin;

	float yOriginal;

	float tempoDeIntangibilidade;
	float TempoPiscando;
	float TempoParaTrocarSkin;

	Alien();

	glm::vec4 Centro;
	glm::vec4 Up;
	glm::vec4 Right;

	Alien(glm::vec4 Centro);

	bool CanhaoDireitoAtira;

	std::vector<Vertex> Vertices;
	std::vector<glm::ivec3> Indices;

	std::vector<Vertex> getAlienVertices(bool hasPowerUp1, bool hasPowerUp2);
	std::vector<glm::ivec3> getAlienIndices(int pose);


	void ajustaEscalaDoAlien(glm::vec3 FatorDeEscala);
	void transladaOAlien(glm::vec3 fatorDeTranslacao);
	void rotacionaOAlien(float graus);
    
	Missil Atira(float velocidade);
	void CarregaBomba(float CountDown);
	void pisca(float tempoDePiscada, float DeltaTime);
	void MoveAlienLateralmente(bool& AlienMoveLeft, float velocidadeInimigos, float DeltaTime);
	void AtacaEmEsquadrao(float localDeSobrevooDosAliens, glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe, float alturaDoPlaneta);
	void RecuaEmEsquadrao(glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe, float localDeSobrevooDosAliens);
	void AtualizaTempoDeTangibilidade(float DeltaTime, float tempoDeIntangibilidadeAlien);
	void AtualizaEstadoDaBomba(float DeltaTime, glm::vec3 fatorDeTranslacaoEsquadrao, float intensidadePiscadaBombaDropada, float velocidadeDePiscadaBombaDropada);
	void TrocaSkin(float DeltaTime, float velocidadeDoAlien, bool hasPowerUp1, bool hasPowerUp2, bool congela);
};

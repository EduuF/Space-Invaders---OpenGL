#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Nave.h"
#include "Missil.h"
#include <random>

class GameState {
public:

	const GLuint NumeroDeLinhasDeInimigos = 5;
	const GLuint NumeroDeColunasDeInimigos = 7;
	int AlienComABomba = -1;

	bool endGame = false;
	bool pausedGame = false;
	bool NaveAtira = false;
	bool InimigoAtira = false;
	bool rotacionaNaveParaDireita = false;
	bool rotacionaNaveParaEsquerda = false;
	bool AlienMoveLeft = true;
	bool PrintaEstadoDoJogo = false;

	bool pressESC = false;
	bool releaseESC = false;
	bool pressF1 = false;
	bool releaseF1 = false;

	float CadenciaDeTirosNave = 0.3f;
	float VelocidadeLateralNave = 0.03f;
	float velocidadeDosAlien = 0.15f;
	float velocidadeSubidaEDescidaInimigos = 1.2f;
	float localDeSobrevooDosAliens = 2.0f - (this->NumeroDeLinhasDeInimigos * 0.3);
	float alturaDoPlaneta = -1.8f;
	float velocidadeDePiscadaBombaDropada = 2.5f;
	float intensidadePiscadaBombaDropada = 1.3f;
	float TempoParaBombaExplodirBombaDropada = 30.0f;
	float VelocidadeDoTiroAlien = 1.5f;
	float tempoDeIntangibilidadeAlien = 2.0f;
	float tempoDeIntangibilidadeNave = 2.0f;
	float TempoDePiscadaAoSerAtingido = 0.1f;

	int chanceDeInimigoAtirar = 500;
	int chanceDeInimigoTentarDroparBomba = 100;
	int chanceDeFormarEsquadrao = 5000;

	GameState();

	void ApertaEsc();
	void SoltaEsc();
	void ApertaF1();
	void SoltaF1();
	void ApertaW();
	void SoltaW();
	void ApertaS();
	void SoltaS();
	void ApertaA();
	void SoltaA();
	void ApertaD();
	void SoltaD();
	

	int GeraNumeroAleatorio();

	void vitoria();
	void gameOver();
};

#endif
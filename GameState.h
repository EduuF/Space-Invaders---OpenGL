#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Nave.h"
#include "Missil.h"
#include <random>

class GameState {
public:

	int NumeroDeLinhasDeInimigos = 3;
	int NumeroDeColunasDeInimigos = 6;
	int AlienComABomba = -1;
	int QuantidadeDeEstrelas = 30;

	bool vitoria = false;
	bool gameOver = false;
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
	bool hasPowerUp0 = false;
	bool hasPowerUp1 = false;
	bool hasPowerUp2 = false;
	bool ordemDeRecuada = false;

	float CadenciaDeTirosNave = 0.03f;
	float VelocidadeLateralNave = 0.05f;
	float velocidadeDosAlien = 0.1f;
	float velocidadeSubidaEDescidaInimigos = 1.2f;
	float localDeSobrevooDosAliens = 2.0f - ((this->NumeroDeLinhasDeInimigos+1) * 0.32);
	float alturaDoPlaneta = -1.8f;
	float velocidadeDePiscadaBombaDropada = 2.5f;
	float intensidadePiscadaBombaDropada = 1.3f;
	float TempoParaBombaExplodirBombaDropada = 25.0f;
	float VelocidadeDoTiroAlien = 0.5f;
	float tempoDeIntangibilidadeAlien = 2.0f;
	float tempoDeIntangibilidadeNave = 2.0f;
	float TempoDePiscadaAoSerAtingido = 0.1f;
	float velocidadeDeDescidaDoPowerUp = 0.8f;
	float tempoDePowerUp0 = 10.0f;
	float tempoDePowerUp1 = 10.0f;
	float tempoDePowerUp2 = 10.0f;
	float VelocidadeDoTiroNave = 2.0f;
	
	int ChanceDeDroparPowerUp = 200;
	int chanceDeInimigoAtirar = 150;
	int chanceDeInimigoTentarDroparBomba = 20;
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

	void getPowerUp(int tipo);
	void AplicaPowerUps(float DeltaTime);
	

	int GeraNumeroAleatorio();
};

#endif
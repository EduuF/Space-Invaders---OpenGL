#include "GameState.h"


#include <iostream>

GameState::GameState() {
}

int GameState::GeraNumeroAleatorio() {
	std::random_device rd;
	std::uniform_int_distribution<int> dist(1, 10000);
	return dist(rd);
}

void GameState::getPowerUp(int tipo) {
	if (tipo == 0 && !this->hasPowerUp0) {
		this->hasPowerUp0 = true;
		this->CadenciaDeTirosNave /= 3;
	}else if (tipo == 1 && !this->hasPowerUp1) {
		this->hasPowerUp1 = true;
		this->velocidadeDosAlien /= 3;
	}else if (tipo == 2 && !this->hasPowerUp2) {
		this->hasPowerUp2 = true;
		this->chanceDeInimigoAtirar /= 20;
	}
}

void GameState::AplicaPowerUps(float DeltaTime) {
	if (hasPowerUp0) {
		this->tempoDePowerUp0 -= DeltaTime;
		if (this->tempoDePowerUp0 <= 0.0f) {
			this->tempoDePowerUp0 = 10.0f;
			this->hasPowerUp0 = false;
			this->CadenciaDeTirosNave *= 3;
		}
	}
	if (hasPowerUp1) {
		this->tempoDePowerUp1 -= DeltaTime;
		if (this->tempoDePowerUp1 <= 0.0f) {
			this->tempoDePowerUp1 = 10.0f;
			this->hasPowerUp1 = false;
			this->velocidadeDosAlien *= 3;
		}
	}
	if (hasPowerUp2) {
		this->tempoDePowerUp2 -= DeltaTime;
		if (this->tempoDePowerUp2 <= 0.0f) {
			this->tempoDePowerUp2 = 10.0f;
			this->hasPowerUp2 = false;
			this->chanceDeInimigoAtirar *= 20;
		}
	}
}

void GameState::ApertaEsc() {
	this->releaseESC = false;
	this->pressESC = true;
}

void GameState::SoltaEsc() {
	this->releaseESC = true;

	if (this->pressESC && this->releaseESC) {
		this->pressESC = false;
		this->releaseESC = false;

		if (this->pausedGame) {
			this->pausedGame = false;
		}
		else {
			this->pausedGame = true;
		}
	}
}

void GameState::ApertaF1() {
	this->releaseF1 = false;
	this->pressF1 = true;
}

void GameState::SoltaF1() {
	this->releaseF1 = true;

	if (this->pressF1 && this->releaseF1) {
		this->pressF1 = false;
		this->releaseF1 = false;
		this->PrintaEstadoDoJogo = true;

		if (this->pausedGame) {
			this->pausedGame = false;
		}
		else {
			this->pausedGame = true;
		}
	}
}

void GameState::ApertaW() {
	this->NaveAtira = true;
}

void GameState::SoltaW() {
	this->NaveAtira = false;

}

void GameState::ApertaS() {
	this->InimigoAtira = true;
}

void GameState::SoltaS() {
	this->InimigoAtira = false;

}

void GameState::ApertaD() {
	this->rotacionaNaveParaDireita = true;
}

void GameState::SoltaD() {
	this->rotacionaNaveParaDireita = false;

}

void GameState::ApertaA() {
	this->rotacionaNaveParaEsquerda = true;
}

void GameState::SoltaA() {
	this->rotacionaNaveParaEsquerda = false;

}
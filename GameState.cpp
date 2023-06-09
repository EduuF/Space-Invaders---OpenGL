#include "GameState.h"


#include <iostream>

GameState::GameState() {
}

int GameState::GeraNumeroAleatorio() {
	std::random_device rd;
	std::uniform_int_distribution<int> dist(1, 10000);
	return dist(rd);
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


void GameState::vitoria() {
	this->endGame = true;
	std::cout << "!!Vitória ^.^" << std::endl;
}

void GameState::gameOver() {
	this->endGame = true;
	std::cout << "!!Perdeu D,=" << std::endl;
}
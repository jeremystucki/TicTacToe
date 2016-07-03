//
// Created by Jeremy Stucki on 02/07/2016.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include "TicTacToePlayer.h"

void TicTacToePlayer::Reset() {
	fitness = 0;
	currentPlayer = defaultPlayer;
	currentMove = 0;
	for (int i = 0; i < fields->size(); i++) {
		(*fields)[i] = EMPTY;
	}
}

void TicTacToePlayer::Update(const std::vector<float> &networkOutputs) {
	currentMove++;
	currentPlayer = (currentPlayer == PLAYERX) ? PLAYERO : PLAYERX;

	if (currentMove % 2 == 0 && currentPlayer == PLAYERO) {
		return;
	}

	if (currentMove % 2 != 0 && currentPlayer == PLAYERX) {
		return;
	}

	if (getWinner() != EMPTY) {
		return;
	}

	std::vector<float> outputs = networkOutputs;
	std::sort(outputs.begin(), outputs.end(), std::greater<float>());

	for (int i = 0; i < outputs.size(); i++) {
		int field = 0;

		for (int j = 0; j < outputs.size(); j++) {
			if (networkOutputs[j] == outputs[i]) {
				field = j;
				break;
			}
		}

		if ((*fields)[field] != EMPTY) {
			continue;
		}

		(*fields)[field] = currentPlayer;
		break;
	}

	fitness += 20;

	if (getWinner() == currentPlayer) {
		fitness += 100;
	}
}

double TicTacToePlayer::GetFitness() const {
	return fitness;
}

std::vector<float> TicTacToePlayer::ProvideNetworkWithInputs() const {
	std::vector<float> inputs;
	inputs.reserve(11);

	for (int i = 0; i < 9; i++) {
		inputs.push_back((*fields)[i]);
	}

	inputs.push_back(currentMove);
	inputs.push_back(currentPlayer);

	return inputs;
}

TicTacToePlayer::TicTacToePlayer(std::shared_ptr<std::vector<int>> fields, int player) :
		fields(fields)
{
	this->defaultPlayer = player;
	this->currentPlayer = defaultPlayer;

	currentPlayer = (currentPlayer == PLAYERX) ? PLAYERO : PLAYERX;
}

int TicTacToePlayer::getWinner() {
	for(int i = 0; i < 3; i++) {
		if ((*fields)[i] != EMPTY && (*fields)[i] == (*fields)[i + 3] && (*fields)[i + 3] == (*fields)[i + 6]) {
			return (int) (*fields)[i];
		}
	}

	if ((*fields)[0] != EMPTY && (*fields)[0] == (*fields)[1] && (*fields)[1] == (*fields)[2]) {
		return (int) (*fields)[0];
	}

	if ((*fields)[3] != EMPTY && (*fields)[3] == (*fields)[4] && (*fields)[4] == (*fields)[5]) {
		return (int) (*fields)[0];
	}

	if ((*fields)[6] != EMPTY && (*fields)[6] == (*fields)[7] && (*fields)[7] == (*fields)[8]) {
		return (int) (*fields)[0];
	}

	if ((*fields)[0] != EMPTY && (*fields)[0] == (*fields)[4] && (*fields)[4] == (*fields)[8]) {
		return (int) (*fields)[0];
	}

	if ((*fields)[2] != EMPTY && (*fields)[2] == (*fields)[4] && (*fields)[4] == (*fields)[6]) {
		return (int) (*fields)[2];
	}

	return EMPTY;
}

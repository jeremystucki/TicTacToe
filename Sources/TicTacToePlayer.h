//
// Created by Jeremy Stucki on 02/07/2016.
//

#include <memory>
#include "body.h"

class TicTacToePlayer: public JNF_NEAT::IBody {

private:
	const int EMPTY = 0;
	const int PLAYERX = 1;
	const int PLAYERO = -1;

	int fitness = 0;
	int currentPlayer;
	int defaultPlayer;
	int currentMove = 0;

	std::shared_ptr<std::vector<int>> fields;

	int getWinner();


public:
	TicTacToePlayer(std::shared_ptr<std::vector<int>> fields, int player);

	void Reset() override;
	void Update(const std::vector<float>& networkOutputs) override;
	double GetFitness() const override;

	std::vector<float> ProvideNetworkWithInputs() const override;

};

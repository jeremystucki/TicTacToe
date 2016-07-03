//
// Created by Jeremy Stucki on 02/07/2016.
//

#include <iostream>
#include <memory>
#include "training_parameters.h"
#include "body.h"
#include "TicTacToePlayer.h"
#include "neural_network_trainer.h"

int main() {

	JNF_NEAT::TrainingParameters params;
	params.numberOfInputs = 11;
	params.numberOfOutputs = 9;
	params.updatesPerGeneration = 9;

	std::vector<std::shared_ptr<JNF_NEAT::IBody>> bodies;

	for (int i = 0; i < 50; i++) {
		auto fields = std::make_shared<std::vector<int>>(std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0});
		fields->reserve(9);

		for (int j = 0; j < 9; j++) {
			fields->push_back(0);
		}

		bodies.push_back(std::make_shared<TicTacToePlayer>(fields, 1));
		bodies.push_back(std::make_shared<TicTacToePlayer>(fields, -1));
	}

	JNF_NEAT::NeuralNetworkTrainer trainer(bodies, params);
	trainer.loggingEnabled = true;
	trainer.TrainUntilGenerationEquals(50);

}

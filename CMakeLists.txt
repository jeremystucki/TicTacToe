cmake_minimum_required(VERSION 3.5)
project(TicTacToe)

# uncomment on macOS with custom gcc
# set(CMAKE_C_COMPILER /usr/local/bin/gcc)
# set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        Sources/body.h
        Sources/gene.cpp
        Sources/gene.h
        Sources/genome.cpp
        Sources/genome.h
        Sources/neural_network.cpp
        Sources/neural_network.h
        Sources/neural_network_trainer.cpp
        Sources/neural_network_trainer.h
        Sources/neuron.cpp
        Sources/neuron.h
        Sources/organism.cpp
        Sources/organism.h
        Sources/species.cpp
        Sources/species.h
        Sources/trained_neural_network.cpp
        Sources/trained_neural_network.h
        Sources/training_parameters.h
        Sources/TicTacToePlayer.cpp
        Sources/TicTacToePlayer.h
        Sources/main.cpp
        Sources/logger.cpp
        Sources/logger.h
)

add_executable(TicTacToe ${SOURCE_FILES})
target_link_libraries(TicTacToe -lstdc++fs)

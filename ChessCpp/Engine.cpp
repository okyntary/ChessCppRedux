#include <random>

#include "Engine.h"
#include "Model.h"

Engine::Engine(Model* model) : m_model(model) {}

void Engine::update() const
{
	chooseRandomMove();
}

void Engine::chooseRandomMove() const
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();
	unsigned int noOfValidMoves{ m_model->m_validMoves.size() };

	if (noOfValidMoves)
	{
		unsigned int index = (noOfValidMoves * std::rand() / RAND_MAX);
		m_model->enterMove((m_model->m_validMoves)[index]);
	}
}

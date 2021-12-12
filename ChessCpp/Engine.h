#pragma once

class Model;
#include "Model.h"

class Engine
{
private:
	Model* m_model;

public:
	Engine(Model* model);

	// Pulls information from Model
	void update() const;

	// Responds with a randomly chosen valid move
	void chooseRandomMove() const;
};

class Evaluator
{

};

class Opening
{

};

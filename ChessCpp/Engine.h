#pragma once

#include <array>
#include <map>
#include <memory>

#include "ChessPiece.h"

class Model;
#include "Model.h"

class Evaluator
{
private:
	const static std::map<PieceType, int> m_pieceValues;
	const static std::map<PieceType, std::array<std::array<int, 8>, 8>> openingModifiers;
	const static std::map<PieceType, std::array<std::array<int, 8>, 8>> middlegameModifiers;
	const static std::map<PieceType, std::array<std::array<int, 8>, 8>> endgameModifiers;

public:
	static int getPieceValue(std::shared_ptr<ChessPiece> chessPiece);
	int evaluate(Model* model) const;
	int naiveEvaluate(Model* model) const;
};

class Engine
{
private:
	Model* m_model{nullptr};
	Evaluator m_evaluator{};

public:
	Engine(Model* model);

	// Pulls information from Model
	void update() const;

	// Responds with a randomly chosen valid move
	void chooseRandomMove() const;

	int evalute() const;
};

class Opening
{

};

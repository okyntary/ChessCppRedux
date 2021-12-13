#pragma once

#include <array>
#include <map>
#include <memory>

#include "ChessMove.h"
#include "ChessPiece.h"

enum class Player;
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
	void playMove() const;

	// Responds with a randomly chosen valid move
	std::shared_ptr<ChessMove> chooseRandomMove() const;
	std::shared_ptr<ChessMove> searchForBestMove(int depth, Player currentPlayer) const;
	// Simulates a given move and returns the evaluation of the simulated board state

	int evaluate() const;
};

class Opening
{

};

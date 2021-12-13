#include <random>

#include "Engine.h"
#include "Model.h"

const std::map<PieceType, int> Evaluator::m_pieceValues
{
	{PieceType::king, INT_MAX},
	{PieceType::queen, 900},
	{PieceType::rook, 500},
	{PieceType::bishop, 300},
	{PieceType::knight, 300},
	{PieceType::pawn, 100},
};

int Evaluator::getPieceValue(std::shared_ptr<ChessPiece> chessPiece)
{
	int pieceEvaluation{ m_pieceValues.at(chessPiece->getPieceType()) };
	if (chessPiece->getPieceColor() == PieceColor::black) pieceEvaluation *= -1;
	return pieceEvaluation;
}

int Evaluator::evaluate(Model* model) const
{
	// todo
	return naiveEvaluate(model);
}

int Evaluator::naiveEvaluate(Model* model) const
{
	Chessboard& chessboard{model->m_chessboard};

	int evaluation{ 0 };
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			if (chessboard.hasPiece({ i, j })) evaluation += getPieceValue(chessboard.getPiece({ i, j }));
		}
	}
	return evaluation;
}

Engine::Engine(Model* model) : m_model(model), m_evaluator() {}

void Engine::update() const
{
	// todo - minmax search + alpha-beta pruning
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

int Engine::evalute() const
{
	return m_evaluator.evaluate(m_model);
}

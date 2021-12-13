#include <memory>
#include <random>
#include <vector>

#include "Engine.h"
enum class Player;
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
	if (chessPiece->getPieceType() == PieceType::king) return 0;

	int pieceEvaluation{ m_pieceValues.at(chessPiece->getPieceType()) };
	if (chessPiece->getPieceColor() == PieceColor::black) pieceEvaluation *= -1;
	return pieceEvaluation;
}

int Evaluator::evaluate(Model* model) const
{
	bool isWhiteTurn{model->m_currentPlayer == Player::white};
	if (isWhiteTurn && model->isCheckmated(Player::white))
	{
		return INT_MIN;
	}
	else if (!isWhiteTurn && model->isCheckmated(Player::black))
	{
		return INT_MAX;
	}
	// Todo
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

void Engine::playMove() const
{
	constexpr int presetDepth{ 3 };
	std::shared_ptr<ChessMove> chosenMove{searchForBestMove(presetDepth, m_model->m_currentPlayer)};
	m_model->enterMove(chosenMove);
}

std::shared_ptr<ChessMove> Engine::chooseRandomMove() const
{
	// Initialize RNG
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	std::vector<std::shared_ptr<ChessMove>> validMoves{m_model->m_validMoves};
	unsigned int noOfValidMoves{ validMoves.size() };
	if (noOfValidMoves)
	{
		unsigned int randomIndex = (noOfValidMoves * std::rand() / RAND_MAX);
		return validMoves[randomIndex];
	}
	return nullptr;
}

std::shared_ptr<ChessMove> Engine::searchForBestMove(int depth, Player currentPlayer) const
{
	// Base case for 0 ply
	if (depth == 0)
	{
		return nullptr;
	}

	// Base case for 1 ply
	std::vector<std::shared_ptr<ChessMove>> validMoves{m_model->generateValidMoves()};
	std::vector<std::shared_ptr<ChessMove>> candidateMoves{};
	bool isWhiteTurn{ currentPlayer == Player::white };

	int currentEvaluation{ isWhiteTurn ? INT_MIN : INT_MAX };

	if (depth == 1)
	{

		if (isWhiteTurn)
		{
			for (auto validMove : validMoves)
			{
				m_model->simulateMove(validMove);
				int simulatedEvaluation{evaluate()};
				m_model->undoMove(validMove);
				if (simulatedEvaluation > currentEvaluation)
				{
					currentEvaluation = simulatedEvaluation;
					candidateMoves.clear();
					candidateMoves.push_back(validMove);
				}
				else if (simulatedEvaluation == currentEvaluation)
				{
					candidateMoves.push_back(validMove);
				}
			}
		}
		else
		{
			for (auto validMove : validMoves)
			{
				m_model->simulateMove(validMove);
				int simulatedEvaluation{evaluate()};
				m_model->undoMove(validMove);
				if (simulatedEvaluation < currentEvaluation)
				{
					currentEvaluation = simulatedEvaluation;
					candidateMoves.clear();
					candidateMoves.push_back(validMove);
				}
				else if (simulatedEvaluation == currentEvaluation)
				{
					candidateMoves.push_back(validMove);
				}
			}
		}
	}
	else
	{
		if (isWhiteTurn)
		{
			for (auto validMove : validMoves)
			{
				m_model->simulateMove(validMove);
				std::shared_ptr<ChessMove> bestMove{searchForBestMove(depth - 1, Player::black)};
				m_model->simulateMove(bestMove);
				int simulatedEvaluation{evaluate()};
				m_model->undoMove(bestMove);
				m_model->undoMove(validMove);
				if (simulatedEvaluation > currentEvaluation)
				{
					currentEvaluation = simulatedEvaluation;
					candidateMoves.clear();
					candidateMoves.push_back(validMove);
				}
				else if (simulatedEvaluation == currentEvaluation)
				{
					candidateMoves.push_back(validMove);
				}
			}
		}
		else
		{
			for (auto validMove : validMoves)
			{
				m_model->simulateMove(validMove);
				std::shared_ptr<ChessMove> bestMove{searchForBestMove(depth - 1, Player::white)};
				m_model->simulateMove(bestMove);
				int simulatedEvaluation{evaluate()};
				m_model->undoMove(bestMove);
				m_model->undoMove(validMove);
				if (simulatedEvaluation < currentEvaluation)
				{
					currentEvaluation = simulatedEvaluation;
					candidateMoves.clear();
					candidateMoves.push_back(validMove);
				}
				else if (simulatedEvaluation == currentEvaluation)
				{
					candidateMoves.push_back(validMove);
				}
			}
		}
	}

	// Initialize RNG
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	unsigned int noOfCandidateMoves{ candidateMoves.size() };
	if (noOfCandidateMoves)
	{
		unsigned int randomIndex = (noOfCandidateMoves * std::rand() / RAND_MAX);
		return candidateMoves[randomIndex];
	}
	return nullptr;
}

int Engine::evaluate() const
{
	return m_evaluator.evaluate(m_model);
}

int Engine::evaluate(int depth) const
{
	return alphaBeta(depth, INT_MIN, INT_MAX);
}

int Engine::alphaBeta(int depth, int alpha, int beta) const
{
	Player currentPlayer{m_model->m_currentPlayer};
	if (depth == 0)
	{
		return evaluate();
	}
	else if (currentPlayer == Player::white)
	{
		int bestSoFar{ INT_MIN };
		std::vector<std::shared_ptr<ChessMove>> validMoves{m_model->generateValidMoves()};
		for (auto validMove : validMoves)
		{
			m_model->simulateMove(validMove);
			int simulatedEvaluation{ alphaBeta(depth - 1, alpha, beta) };
			m_model->undoMove(validMove);
			if (simulatedEvaluation > bestSoFar)
			{
				bestSoFar = simulatedEvaluation;
			}
			else if (bestSoFar > beta)
			{
				return bestSoFar;
			}
			alpha = std::max(alpha, bestSoFar);
		}
		return bestSoFar;
	}
	else if (currentPlayer == Player::black)
	{
		int bestSoFar{ INT_MAX };
		std::vector<std::shared_ptr<ChessMove>> validMoves{m_model->generateValidMoves()};
		for (auto validMove : validMoves)
		{
			m_model->simulateMove(validMove);
			int simulatedEvaluation{ alphaBeta(depth - 1, alpha, beta) };
			m_model->undoMove(validMove);
			if (simulatedEvaluation < bestSoFar)
			{
				bestSoFar = simulatedEvaluation;
			}
			else if (bestSoFar < alpha)
			{
				return bestSoFar;
			}
			beta = std::min(beta, bestSoFar);
		}
		return bestSoFar;
	}
}

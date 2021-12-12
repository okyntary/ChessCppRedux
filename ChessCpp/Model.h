#pragma once

#include <array>
#include <memory>
#include <vector>

class Engine;
class View;
#include "Engine.h"
#include "View.h" 

#include "Chessboard.h"
#include "ChessPiece.h"
#include "ChessMove.h"

 enum class Player
{
	white,
	black,
	null
};

class Model
{
private:

	// Circular dependency here, acceptable since scope of program is small
	// Link to View
	View* m_view{};
	Engine* m_engine{};

	std::array<std::shared_ptr<ChessPiece>, 32> m_chessPieces{};
	Chessboard m_chessboard{};
	std::vector<std::shared_ptr<ChessMove>> m_validMoves;
	MoveHistory m_moveHistory{};
	Player m_currentPlayer{ Player::white };

	friend class Engine;
	friend class View;

public:
	Model();
	// Set the view
	void setView(View* view);
	// Call view to update based on model
	void updateView() const;

	void setEngine(Engine* engine);
	void updateEngine() const;

	// Methods related to the actual model
	void initialize();
	void resetChessboard();

	int getTurnNumber() const;
	std::shared_ptr<ChessPiece> getPromotionPiece(PieceColor color, PieceType type) const;
	static Player getOtherPlayer(Player player);
	void swapCurrentPlayer();

	// Collision methods - all return true if the moving from the start to the end Coordinates is feasible given
	// the chessboard
	bool hasNoCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoQueenCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoRookCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoBishopCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoPawnCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const;

	// Move-generating methods
	// Generates all plausible moves on this board state, given the current player
	std::vector<std::shared_ptr<ChessMove>> generatePlausibleMoves();
	// Generates all plausible moves on this board state, given the specified player
	std::vector<std::shared_ptr<ChessMove>> generatePlausibleMoves(Player player);
	// Generates all valid moves on this board state, given the current player
	std::vector<std::shared_ptr<ChessMove>> generateValidMoves();

	// Check if the given move is inside m_validMoves and return it if it does exist. Return nullptr if it does not exist
	std::shared_ptr<ChessMove> validateMove(const std::shared_ptr<ChessMove> move) const;
	// Enter the move, called by the Controller
	void enterMove(std::string move);
	// Enter the move selected by the Engine
	void enterMove(std::shared_ptr<ChessMove> move);

	// Methods related to testing board state
	Coordinates getPlayerKingSquare(Player player);
	bool isChecked();
	bool isChecked(Player player);
	bool isCheckmated();
	bool isCheckmated(Player player);
	bool isStalemated();
	bool isStalemated(Player player);

	// Methods related to making moves
	void simulateMove(std::shared_ptr<ChessMove>& move);
	void undoMove(std::shared_ptr<ChessMove>& move);
	void applyMove(std::shared_ptr<ChessMove>& move);

	// Miscellaneous test methods
	void testMoves();
	void testPlausibleMoves();
};

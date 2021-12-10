#pragma once

#include <array>
#include <memory>
#include <vector>

class View;
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

	std::array<ChessPiece*, 32> m_chessPieces{};
	Chessboard m_chessboard{};
	std::vector<std::shared_ptr<ChessMove>> m_validMoves;
	MoveHistory m_moveHistory{};
	Player m_currentPlayer{ Player::white };

	friend class View;

public:
	Model();
	// Set the view
	void setView(View* view);
	// Call view to update based on model
	void updateView() const;

	// Methods related to the actual model
	void initialize();
	int getTurnNumber() const;
	ChessPiece& getPromotionPiece(PieceColor color, PieceType type) const;
	static Player getOtherPlayer(Player player);
	void swapCurrentPlayer();

	// Collision methods - all return true if the moving from the start to the end Coordinates is feasible given
	// the chessboard
	bool hasNoCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoQueenCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoRookCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoBishopCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoPawnCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;

	// Move-generating methods
	// Generates all plausible moves on this board state, given the current player
	std::vector<std::shared_ptr<ChessMove>> generatePlausibleMoves();
	// Generates all plausible moves on this board state, given the specified player
	std::vector<std::shared_ptr<ChessMove>> generatePlausibleMoves(Player player);
	// Generates all valid moves on this board state, given the current player
	std::vector<std::shared_ptr<ChessMove>> generateValidMoves();

	// Check if the given move is inside m_validMoves
	bool validateMove(const ChessMove& move) const;
	// Enter the move, called by the Controller
	void enterMove(const std::string& move) const;

	// Methods related to testing board state
	Coordinates getPlayerKingSquare(Player player);
	bool isChecked();
	bool isChecked(Player player);
	bool isCheckmated();
	bool isCheckmated(Player player);
	bool isStalemated();
	bool isStalemated(Player player);

	// Methods related to making moves
	bool isValidMove(std::shared_ptr<ChessMove>& move); // Need to implement, to check whether move entered is valid
	void simulateMove(std::shared_ptr<ChessMove>& move);
	void undoMove(std::shared_ptr<ChessMove>& move);
	void applyMove(std::shared_ptr<ChessMove>& move);

	// Miscellaneous test methods
	void testMoves();
	void testPlausibleMoves();
	void testCheckmate();
	void testTargetSquares();
};

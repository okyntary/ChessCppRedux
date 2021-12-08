#pragma once

#include <array>
#include <vector>

class View;
#include "View.h" 

#include "Chessboard.h"
#include "ChessPiece.h"
#include "ChessMove.h"

class Model
{
private:
	enum class Player
	{
		white,
		black
	};

	// Circular dependency here, acceptable since scope of program is small
	// Link to View
	View* m_view{};

	std::array<ChessPiece*, 32> m_chessPieces{};
	Chessboard m_chessboard{};
	std::vector<ChessMove> m_validMoves;
	MoveHistory m_moveHistory{};
	Player m_currentPlayer{Player::white};

	friend class View;

public:
	Model();
	// Set the view
	void setView(View* view);
	// Call view to update based on model
	void updateView() const;

	// Methods related to the actual model
	void initialize();
	ChessPiece& getPromotionPiece(PieceColor color, PieceType type);

	// Collision methods - all return true if the moving from the start to the end Coordinates is feasible given
	// the chessboard
	bool hasNoCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoQueenCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoRookCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoBishopCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;
	bool hasNoPawnCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const;

	// Move-generating methods
	std::vector<ChessMove> generatePlausibleMoves();

	// Miscellaneous test methods
	void testMove();
	void testUndoMove();
	void testPlausibleMoves();

	void testTargetSquares();
};

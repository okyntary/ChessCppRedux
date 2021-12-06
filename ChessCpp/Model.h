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
	// Circular dependency here, acceptable since scope of program is small
	// Link to View
	View* m_view{};

	std::array<ChessPiece*, 32> m_chessPieces{};
	Chessboard m_chessboard{};
	std::vector<ChessMove> m_validMoves;
	bool currentPlayer{false};

	friend class View;

public:
	Model();
	// Set the view
	void setView(View* view);
	// Call view to update based on model
	void updateView() const;

	// Methods related to the actual model
	void initialize();

	void testMove();
	void testUndoMove();
};

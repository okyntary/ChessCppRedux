#pragma once

#include <vector>

class View;
#include "View.h" 

#include "Chessboard.h"
#include "ChessPiece.h"

class Model
{
private:
	// Circular dependency here, acceptable since scope of program is small
	// Link to View
	View* m_view{};
	Chessboard m_chessboard{};

public:
	// Set the view
	void setView(View* view);
	// Call view to update based on model
	void updateView() const;

	// Methods related to the actual model
	void initialize();
};

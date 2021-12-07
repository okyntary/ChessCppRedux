#include <iostream>

#include <string>

#include "ChessPiece.h"

// ChessPiece methods
ChessPiece::ChessPiece(PieceColor color, PieceType type) : m_color(color), m_type(type) {}

void ChessPiece::increaseMoveCount()
{
	++m_moveCount;
}

void ChessPiece::decreaseMoveCount()
{
	if (m_moveCount > 0) --m_moveCount;
}

void ChessPiece::setCapturedStatus(bool isCaptured)
{
	m_isCaptured = isCaptured;
}

void ChessPiece::setAsCaptured()
{
	m_isCaptured = true;
}

PieceColor ChessPiece::getPieceColor() const
{
	return m_color;
}

PieceType ChessPiece::getPieceType() const
{
	return m_type;
}

bool ChessPiece::hasMoved() const
{
	return m_moveCount > 0;
}

bool ChessPiece::isCaptured() const
{
	return m_isCaptured;
}

// NullPiece methods
NullPiece::NullPiece() : ChessPiece(PieceColor::null, PieceType::null) {};

const std::string NullPiece::toString() const
{
	return "NP";
}

std::vector<Coordinates> NullPiece::getTargetSquares(Coordinates coordinates) const
{
	return std::vector<Coordinates>{};
}

// King methods
King::King(PieceColor color) : ChessPiece(color, PieceType::king) {};

std::vector<Coordinates> King::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;
	for (int i = start_col - 1; i <= start_col + 1; ++i)
	{
		for (int j = start_row - 1; j <= start_row + 1; ++j)
		{
			if (i == start_col && j == start_row) continue;
			Coordinates targetSquare{ j, i };
			if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
		}
	}
	return targetSquares;
}

WhiteKing::WhiteKing() : King::King(PieceColor::white) {};

const std::string WhiteKing::toString() const
{
	return "WK";
}

BlackKing::BlackKing() : King::King(PieceColor::black) {};

const std::string BlackKing::toString() const
{
	return "BK";
}

// Queen methods
Queen::Queen(PieceColor color) : ChessPiece(color, PieceType::queen) {};

std::vector<Coordinates> Queen::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;

	// Counting column number
	for (int i = 0; i < 8; ++i)
	{
		int colDiff = std::abs(start_col - i);
		if (colDiff == 0) continue;
		// Counting row number
		for (int j = start_row - colDiff; j <= start_row + colDiff; j += 2 * colDiff)
		{
			if (i == start_col && j == start_row) continue;

			Coordinates targetSquare{ j, i };
			if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		if (i != start_col) targetSquares.push_back(Coordinates{ start_row, i });
	}
	
	for (int j = 0; j < 8; ++j)
	{
		if (j != start_row) targetSquares.push_back(Coordinates{ j, start_col });
	}

	return targetSquares;

}

WhiteQueen::WhiteQueen() : Queen::Queen(PieceColor::white) {};

const std::string WhiteQueen::toString() const
{
	return "WQ";
}

BlackQueen::BlackQueen() : Queen::Queen(PieceColor::black) {};

const std::string BlackQueen::toString() const
{
	return "BQ";
}

// Rook methods
Rook::Rook(PieceColor color) : ChessPiece(color, PieceType::rook) {};

std::vector<Coordinates> Rook::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;

	for (int i = 0; i < 8; ++i)
	{
		if (i != start_col) targetSquares.push_back(Coordinates{ start_row, i });
	}
	
	for (int j = 0; j < 8; ++j)
	{
		if (j != start_row) targetSquares.push_back(Coordinates{ j, start_col });
	}
	return targetSquares;
}

WhiteRook::WhiteRook() : Rook::Rook(PieceColor::white) {};

const std::string WhiteRook::toString() const
{
	return "WR";
}

BlackRook::BlackRook() : Rook::Rook(PieceColor::black) {};

const std::string BlackRook::toString() const
{
	return "BR";
}

// Bishop methods
Bishop::Bishop(PieceColor color) : ChessPiece(color, PieceType::bishop) {};

std::vector<Coordinates> Bishop::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;

	// Counting column number
	for (int i = 0; i < 8; ++i)
	{
		int colDiff = std::abs(start_col - i);
		if (colDiff == 0) continue;
		// Counting row number
		for (int j = start_row - colDiff; j <= start_row + colDiff; j += 2 * colDiff)
		{
			if (i == start_col && j == start_row) continue;

			Coordinates targetSquare{ j, i };
			if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
		}
	}
	return targetSquares;
}

WhiteBishop::WhiteBishop() : Bishop::Bishop(PieceColor::white) {};

const std::string WhiteBishop::toString() const
{
	return "WB";
}

BlackBishop::BlackBishop() : Bishop::Bishop(PieceColor::black) {};

const std::string BlackBishop::toString() const
{
	return "BB";
}

// Knight methods
Knight::Knight(PieceColor color) : ChessPiece(color, PieceType::knight) {};

std::vector<Coordinates> Knight::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;

	for (int i = start_col - 2; i <= start_col + 2; i += 4)
	{
		for (int j = start_row - 1; j <= start_row + 1; j += 2)
		{
			Coordinates targetSquare{ j, i };
			if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
		}
	}
	
	for (int i = start_col - 1; i <= start_col + 1; i += 2)
	{
		for (int j = start_row - 2; j <= start_row + 2; j += 4)
		{
			Coordinates targetSquare{ j, i };
			if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
		}
	}
	return targetSquares;
}


WhiteKnight::WhiteKnight() : Knight::Knight(PieceColor::white) {};

const std::string WhiteKnight::toString() const
{
	return "WN";
}

BlackKnight::BlackKnight() : Knight::Knight(PieceColor::black) {};

const std::string BlackKnight::toString() const
{
	return "BN";
}

// Pawn methods
Pawn::Pawn(PieceColor color) : ChessPiece(color, PieceType::pawn) {};

WhitePawn::WhitePawn() : Pawn::Pawn(PieceColor::white) {};

const std::string WhitePawn::toString() const
{
	return "WP";
}

std::vector<Coordinates> WhitePawn::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;
	
	if (m_moveCount == 0)
	{
		Coordinates targetSquare{ start_row + 2, start_col };
		targetSquares.push_back(targetSquare);
	}

	for (int i = start_col - 1; i <= start_col + 1; ++i)
	{
		Coordinates targetSquare{ start_row + 1, i };
		if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
	}
	return targetSquares;
}

BlackPawn::BlackPawn() : Pawn::Pawn(PieceColor::black) {};

const std::string BlackPawn::toString() const
{
	return "BP";
}

std::vector<Coordinates> BlackPawn::getTargetSquares(Coordinates coordinates) const
{
	std::vector<Coordinates> targetSquares{};
	int start_row = coordinates.row;
	int start_col = coordinates.col;
	
	if (m_moveCount == 0)
	{
		Coordinates targetSquare{ start_row - 2, start_col };
		targetSquares.push_back(targetSquare);
	}

	for (int i = start_col - 1; i <= start_col + 1; ++i)
	{
		Coordinates targetSquare{ start_row - 1, i };
		if (targetSquare.isOnBoard()) targetSquares.push_back(targetSquare);
	}
	return targetSquares;
}


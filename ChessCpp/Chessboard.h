#pragma once

#include <array>

#include "ChessPiece.h"

class Square
{
private:
	// Coordinates, zero-indexed
	int m_row{};
	int m_col{};
	
public:
	Square(int row = 0, int col = 0);
};

class Chessboard
{
private:
	// Row-major order
	std::array<std::array<Square, 8>, 8> m_chessboard{};

public:
	Chessboard();
};

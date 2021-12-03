#pragma once

#include <array>

#include "ChessPiece.h"

class Square
{
private:
	// Coordinates, zero-indexed
	int m_row{};
	int m_col{};
	ChessPiece* m_piece{};
	
public:
	Square(int row = 0, int col = 0);
	void setPiece(ChessPiece* piece);
	void removePiece();
};

class Chessboard
{
private:
	// Row-major order
	std::array<std::array<Square, 8>, 8> m_chessboard{};

public:
	Chessboard();
	void setPiece(int row, int col, ChessPiece* piece);
	void removePiece(int row, int col);
};

#include "Chessboard.h"

Square::Square(int row, int col) : m_row(row), m_col(col), m_piece(nullptr) {};

void Square::setPiece(ChessPiece* piece)
{
	m_piece = piece;
}

void Square::removePiece()
{
	m_piece = nullptr;
}

Chessboard::Chessboard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_chessboard[i][j] = Square(i, j);
		}
	}
}

void Chessboard::setPiece(int row, int col, ChessPiece* piece)
{
	m_chessboard[row][col].setPiece(piece);
}

void Chessboard::removePiece(int row, int col)
{
	m_chessboard[row][col].removePiece();
}

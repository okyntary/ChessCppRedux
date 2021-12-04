#include "Chessboard.h"

Chessboard::Square::Square(int row, int col) : m_row(row), m_col(col), m_piece(nullptr) {};

void Chessboard::Square::placePiece(ChessPiece* piece)
{
	m_piece = piece;
}

void Chessboard::Square::removePiece()
{
	m_piece = nullptr;
}

bool Chessboard::Square::hasPiece() const
{
	return static_cast<bool>(m_piece);
}

ChessPiece& Chessboard::Square::getPiece()
{
	return *m_piece;
}

const ChessPiece& Chessboard::Square::getPiece() const
{
	return *m_piece;
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

void Chessboard::placePiece(int row, int col, ChessPiece* piece)
{
	m_chessboard[row][col].placePiece(piece);
}

void Chessboard::removePiece(int row, int col)
{
	m_chessboard[row][col].removePiece();
}

bool Chessboard::hasPiece(int row, int col) const
{
	return m_chessboard[row][col].hasPiece();
}

ChessPiece& Chessboard::getPiece(int row, int col)
{
	return m_chessboard[row][col].getPiece();
}

const ChessPiece& Chessboard::getPiece(int row, int col) const
{
	return m_chessboard[row][col].getPiece();
}

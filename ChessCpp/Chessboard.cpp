#include "Chessboard.h"

Square::Square(Coordinates coordinates) : m_coordinates(coordinates), m_piece(nullptr) {};

void Square::placePiece(std::shared_ptr<ChessPiece> piece)
{
	m_piece = piece;
}

void Square::removePiece()
{
	m_piece = nullptr;
}

bool Square::hasPiece() const
{
	return static_cast<bool>(m_piece);
}

std::shared_ptr<ChessPiece> Square::getPiece()
{
	return m_piece;
}

std::shared_ptr<ChessPiece> Square::getPiece() const
{
	return m_piece;
}

Chessboard::Chessboard()
{
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			m_chessboard[i][j] = Square{Coordinates{ i, j }};
		}
	}
}

void Chessboard::placePiece(Coordinates coordinates, std::shared_ptr<ChessPiece> piece)
{
	m_chessboard[coordinates.row][coordinates.col].placePiece(piece);
}

void Chessboard::removePiece(Coordinates coordinates)
{
	m_chessboard[coordinates.row][coordinates.col].removePiece();
}

bool Chessboard::hasPiece(Coordinates coordinates) const
{
	return m_chessboard[coordinates.row][coordinates.col].hasPiece();
}

std::shared_ptr<ChessPiece> Chessboard::getPiece(Coordinates coordinates)
{
	return m_chessboard[coordinates.row][coordinates.col].getPiece();
}

std::shared_ptr<ChessPiece> Chessboard::getPiece(Coordinates coordinates) const
{
	return m_chessboard[coordinates.row][coordinates.col].getPiece();
}

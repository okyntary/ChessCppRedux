#pragma once

#include <array>

#include "Coordinates.h"
#include "ChessPiece.h"

class Square
{
private:
	Coordinates m_coordinates;
	ChessPiece* m_piece{};
	friend class View;
	
public:
	Square(Coordinates coordinates = Coordinates{ 0, 0 });

	void placePiece(ChessPiece* piece);
	void removePiece();
	bool hasPiece() const;
	ChessPiece& getPiece();
	const ChessPiece& getPiece() const;
};

class Chessboard
{
private:
	// Row-major order
	std::array<std::array<Square, 8>, 8> m_chessboard{};
	friend class View;

public:
	Chessboard();
	void placePiece(Coordinates coordinates, ChessPiece* piece);
	void removePiece(Coordinates coordinates);
	bool hasPiece(Coordinates coordinates) const;
	ChessPiece& getPiece(Coordinates coordinates);
	const ChessPiece& getPiece(Coordinates coordinates) const;
};

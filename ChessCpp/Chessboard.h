#pragma once

#include <array>
#include <memory>

#include "Coordinates.h"
#include "ChessPiece.h"

class Square
{
private:
	Coordinates m_coordinates;
	std::shared_ptr<ChessPiece> m_piece{};
	friend class View;
	
public:
	Square(Coordinates coordinates = Coordinates{ 0, 0 });

	void placePiece(std::shared_ptr<ChessPiece> piece);
	void removePiece();
	bool hasPiece() const;
	std::shared_ptr<ChessPiece> getPiece();
	std::shared_ptr<ChessPiece> getPiece() const;
};

class Chessboard
{
private:
	// Row-major order
	std::array<std::array<Square, 8>, 8> m_chessboard{};
	friend class View;

public:
	Chessboard();
	void placePiece(Coordinates coordinates, std::shared_ptr<ChessPiece> piece);
	void removePiece(Coordinates coordinates);
	bool hasPiece(Coordinates coordinates) const;
	std::shared_ptr<ChessPiece> getPiece(Coordinates coordinates);
	std::shared_ptr<ChessPiece> getPiece(Coordinates coordinates) const;
};

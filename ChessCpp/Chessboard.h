#pragma once

#include <array>

#include "ChessPiece.h"

class Chessboard
{
private:
	class Square
	{
	private:
		// Coordinates, zero-indexed
		int m_row{};
		int m_col{};
		ChessPiece* m_piece{};
		friend class View;
		
	public:
		Square(int row = 0, int col = 0);
		void placePiece(ChessPiece* piece);
		void removePiece();
		bool hasPiece() const;
		ChessPiece& getPiece();
		const ChessPiece& getPiece() const;
	};

	// Row-major order
	std::array<std::array<Square, 8>, 8> m_chessboard{};
	friend class View;

public:
	Chessboard();
	void placePiece(int row, int col, ChessPiece* piece);
	void removePiece(int row, int col);
	bool hasPiece(int row, int col) const;
	ChessPiece& getPiece(int row, int col);
	const ChessPiece& getPiece(int row, int col) const;
};

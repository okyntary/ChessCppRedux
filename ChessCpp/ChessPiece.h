#pragma once

class ChessPiece
{
	enum class PieceColor
	{
		null,
		white,
		black
	};

	enum class PieceType
	{
		null,
		king,
		queen,
		rook,
		bishop,
		knight,
		pawn
	};

private:
	PieceColor m_color{ PieceColor::null };
	PieceType m_type{ PieceType::null };
	bool hasMoved{ false };

public:
	ChessPiece(PieceColor color = PieceColor::null, PieceType type = PieceType::null);
};

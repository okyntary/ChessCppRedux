#pragma once

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

// ChessPiece class
class ChessPiece
{
protected:
	PieceColor m_color{ PieceColor::null };
	PieceType m_type{ PieceType::null };
	bool hasMoved{ false };
	bool isCaptured{ false };

public:
	ChessPiece(PieceColor color = PieceColor::null, PieceType type = PieceType::null);
};

// NullPiece class
class NullPiece : public ChessPiece
{
public:
	NullPiece();
};

// King classes
class King : public ChessPiece
{
public:
	King(PieceColor color);
};

class WhiteKing : public King
{
public:
	WhiteKing();
};

class BlackKing : public King
{
public:
	BlackKing();
};

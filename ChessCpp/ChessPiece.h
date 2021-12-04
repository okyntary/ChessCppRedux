#pragma once

#include <string>

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
private:
	PieceColor m_color{ PieceColor::null };
	PieceType m_type{ PieceType::null };
	bool hasMoved{ false };
	bool isCaptured{ false };
	friend class View;

public:
	ChessPiece(PieceColor color = PieceColor::null, PieceType type = PieceType::null);
	virtual const std::string toString() const = 0;
};

// NullPiece class
class NullPiece : public ChessPiece
{
public:
	NullPiece();
	const std::string toString() const override;
};

// King classes
class King : public ChessPiece
{
public:
	King(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhiteKing : public King
{
public:
	WhiteKing();
	const std::string toString() const override;
};

class BlackKing : public King
{
public:
	BlackKing();
	const std::string toString() const override;
};

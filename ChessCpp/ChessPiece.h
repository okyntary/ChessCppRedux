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

// Queen classes
class Queen : public ChessPiece
{
public:
	Queen(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhiteQueen : public Queen
{
public:
	WhiteQueen();
	const std::string toString() const override;
};

class BlackQueen : public Queen
{
public:
	BlackQueen();
	const std::string toString() const override;
};

// Rook classes
class Rook : public ChessPiece
{
public:
	Rook(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhiteRook : public Rook
{
public:
	WhiteRook();
	const std::string toString() const override;
};

class BlackRook : public Rook
{
public:
	BlackRook();
	const std::string toString() const override;
};

// Bishop classes
class Bishop : public ChessPiece
{
public:
	Bishop(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhiteBishop : public Bishop
{
public:
	WhiteBishop();
	const std::string toString() const override;
};

class BlackBishop : public Bishop
{
public:
	BlackBishop();
	const std::string toString() const override;
};

// Knight classes
class Knight : public ChessPiece
{
public:
	Knight(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhiteKnight : public Knight
{
public:
	WhiteKnight();
	const std::string toString() const override;
};

class BlackKnight : public Knight
{
public:
	BlackKnight();
	const std::string toString() const override;
};

// Pawn classes
class Pawn : public ChessPiece
{
public:
	Pawn(PieceColor color);
	virtual const std::string toString() const override = 0;
};

class WhitePawn : public Pawn
{
public:
	WhitePawn();
	const std::string toString() const override;
};

class BlackPawn : public Pawn
{
public:
	BlackPawn();
	const std::string toString() const override;
};

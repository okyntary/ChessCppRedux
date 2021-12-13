#pragma once

#include <string>
#include <vector>

#include "Coordinates.h"

enum class PieceColor
{
	white,
	black,
	null,
};

enum class PieceType
{
	king,
	queen,
	rook,
	bishop,
	knight,
	pawn,
	null,
};

class ChessPiece
{
protected:
	PieceColor m_color{ PieceColor::null };
	PieceType m_type{ PieceType::null };
	int m_moveCount{0};
	bool m_isCaptured{ false };

	friend class Engine;
	friend class View;

public:
	ChessPiece(PieceColor color = PieceColor::null, PieceType type = PieceType::null);
	void increaseMoveCount();
	void decreaseMoveCount();
	void setCapturedStatus(bool isCaptured);
	void setAsCaptured();
	// Reset all piece data
	virtual void resetPiece();

	// Getter methods
	PieceColor getPieceColor() const;
	PieceType getPieceType() const;
	bool hasMoved() const;
	bool isCaptured() const;
	bool isCorrectPiece(PieceColor color, PieceType type) const;
	virtual std::string toString() const = 0;
	virtual std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const = 0;
};

// NullPiece class
class NullPiece : public ChessPiece
{
public:
	NullPiece();
	std::string toString() const override;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

// King classes
class King : public ChessPiece
{
public:
	King(PieceColor color);
	virtual std::string toString() const override = 0;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class WhiteKing : public King
{
public:
	WhiteKing();
	std::string toString() const override;
};

class BlackKing : public King
{
public:
	BlackKing();
	std::string toString() const override;
};

// Queen classes
class Queen : public ChessPiece
{
public:
	Queen(PieceColor color);
	virtual std::string toString() const override = 0;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class WhiteQueen : public Queen
{
public:
	WhiteQueen();
	std::string toString() const override;
};

class BlackQueen : public Queen
{
public:
	BlackQueen();
	std::string toString() const override;
};

// Rook classes
class Rook : public ChessPiece
{
public:
	Rook(PieceColor color);
	virtual std::string toString() const override = 0;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class WhiteRook : public Rook
{
public:
	WhiteRook();
	std::string toString() const override;
};

class BlackRook : public Rook
{
public:
	BlackRook();
	std::string toString() const override;
};

// Bishop classes
class Bishop : public ChessPiece
{
public:
	Bishop(PieceColor color);
	virtual std::string toString() const override = 0;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class WhiteBishop : public Bishop
{
public:
	WhiteBishop();
	std::string toString() const override;
};

class BlackBishop : public Bishop
{
public:
	BlackBishop();
	std::string toString() const override;
};

// Knight classes
class Knight : public ChessPiece
{
public:
	Knight(PieceColor color);
	virtual std::string toString() const override = 0;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class WhiteKnight : public Knight
{
public:
	WhiteKnight();
	std::string toString() const override;
};

class BlackKnight : public Knight
{
public:
	BlackKnight();
	std::string toString() const override;
};

// Pawn classes
class Pawn : public ChessPiece
{
private:
	// The turn on which the pawn moved forward by two squares. 
	int m_doubleMoveTurn{ 0 };

public:
	Pawn(PieceColor color);
	virtual std::string toString() const override = 0;
	virtual std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override = 0;
	void resetPiece() override;

	// Double move methods
	void setDoubleMoveTurn(int doubleMoveTurn);
	bool canDoubleMove() const;
	bool hasDoubleMoved() const;
	int getDoubleMoveTurn() const;
};

class WhitePawn : public Pawn
{
public:
	WhitePawn();
	std::string toString() const override;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

class BlackPawn : public Pawn
{
public:
	BlackPawn();
	std::string toString() const override;
	std::vector<Coordinates> getTargetSquares(Coordinates coordinates) const override;
};

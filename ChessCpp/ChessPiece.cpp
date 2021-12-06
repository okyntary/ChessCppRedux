#include <iostream>

#include <string>

#include "ChessPiece.h"

// ChessPiece methods
ChessPiece::ChessPiece(PieceColor color, PieceType type) : m_color(color), m_type(type) {}

void ChessPiece::increaseMoveCount()
{
	++m_moveCount;
}

void ChessPiece::decreaseMoveCount()
{
	if (m_moveCount > 0) --m_moveCount;
}

void ChessPiece::setCapturedStatus(bool isCaptured)
{
	m_isCaptured = isCaptured;
}

void ChessPiece::setAsCaptured()
{
	m_isCaptured = true;
}

bool ChessPiece::hasMoved() const
{
	return m_moveCount > 0;
}

bool ChessPiece::isCaptured() const
{
	return m_isCaptured;
}

// NullPiece methods
NullPiece::NullPiece() : ChessPiece(PieceColor::null, PieceType::null) {};

const std::string NullPiece::toString() const
{
	return "NP";
}

std::vector<Coordinates> NullPiece::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

// King methods
King::King(PieceColor color) : ChessPiece(color, PieceType::king) {};

std::vector<Coordinates> King::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

WhiteKing::WhiteKing() : King::King(PieceColor::white) {};

const std::string WhiteKing::toString() const
{
	return "WK";
}

BlackKing::BlackKing() : King::King(PieceColor::black) {};

const std::string BlackKing::toString() const
{
	return "BK";
}

// Queen methods
Queen::Queen(PieceColor color) : ChessPiece(color, PieceType::queen) {};

std::vector<Coordinates> Queen::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

WhiteQueen::WhiteQueen() : Queen::Queen(PieceColor::white) {};

const std::string WhiteQueen::toString() const
{
	return "WQ";
}

BlackQueen::BlackQueen() : Queen::Queen(PieceColor::black) {};

const std::string BlackQueen::toString() const
{
	return "BQ";
}

// Rook methods
Rook::Rook(PieceColor color) : ChessPiece(color, PieceType::rook) {};

std::vector<Coordinates> Rook::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

WhiteRook::WhiteRook() : Rook::Rook(PieceColor::white) {};

const std::string WhiteRook::toString() const
{
	return "WR";
}

BlackRook::BlackRook() : Rook::Rook(PieceColor::black) {};

const std::string BlackRook::toString() const
{
	return "BR";
}

// Bishop methods
Bishop::Bishop(PieceColor color) : ChessPiece(color, PieceType::bishop) {};

std::vector<Coordinates> Bishop::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

WhiteBishop::WhiteBishop() : Bishop::Bishop(PieceColor::white) {};

const std::string WhiteBishop::toString() const
{
	return "WB";
}

BlackBishop::BlackBishop() : Bishop::Bishop(PieceColor::black) {};

const std::string BlackBishop::toString() const
{
	return "BB";
}

// Knight methods
Knight::Knight(PieceColor color) : ChessPiece(color, PieceType::knight) {};

std::vector<Coordinates> Knight::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}


WhiteKnight::WhiteKnight() : Knight::Knight(PieceColor::white) {};

const std::string WhiteKnight::toString() const
{
	return "WN";
}

BlackKnight::BlackKnight() : Knight::Knight(PieceColor::black) {};

const std::string BlackKnight::toString() const
{
	return "BN";
}

// Pawn methods
Pawn::Pawn(PieceColor color) : ChessPiece(color, PieceType::pawn) {};

WhitePawn::WhitePawn() : Pawn::Pawn(PieceColor::white) {};

const std::string WhitePawn::toString() const
{
	return "WP";
}

std::vector<Coordinates> WhitePawn::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}

BlackPawn::BlackPawn() : Pawn::Pawn(PieceColor::black) {};

const std::string BlackPawn::toString() const
{
	return "BP";
}

std::vector<Coordinates> BlackPawn::getTargetSquares(int row, int col) const
{
	return std::vector<Coordinates>{};
}


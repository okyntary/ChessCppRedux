#include <iostream>

#include <string>

#include "ChessPiece.h"

// ChessPiece methods
ChessPiece::ChessPiece(PieceColor color, PieceType type) : m_color(color), m_type(type) {}

// NullPiece methods
NullPiece::NullPiece() : ChessPiece(PieceColor::null, PieceType::null) {};

const std::string NullPiece::toString() const
{
	return "NP";
}

// King methods
King::King(PieceColor color) : ChessPiece(color, PieceType::king) {};

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

BlackPawn::BlackPawn() : Pawn::Pawn(PieceColor::black) {};

const std::string BlackPawn::toString() const
{
	return "BP";
}

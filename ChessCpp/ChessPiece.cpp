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

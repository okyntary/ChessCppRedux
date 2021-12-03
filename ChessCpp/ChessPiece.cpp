#include "ChessPiece.h"

// ChessPiece methods
ChessPiece::ChessPiece(PieceColor color, PieceType type) : m_color(color), m_type(type) {}

// NullPiece methods
NullPiece::NullPiece() : ChessPiece(PieceColor::null, PieceType::null) {};

// King methods
King::King(PieceColor color) : ChessPiece(color, PieceType::king) {};

WhiteKing::WhiteKing() : King::King(PieceColor::white) {};

BlackKing::BlackKing() : King::King(PieceColor::black) {};

#include <cassert>
#include <string>

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessMove.h"

// ChessMove methods
ChessMove::ChessMove(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end,
		const bool isCapture, std::shared_ptr<ChessPiece> capturedPiece)
		: m_chessPiece{ chessPiece }, m_start{ start }, m_end{ end },
		m_isCapture{ isCapture }, m_capturedPiece{ capturedPiece } {}

void ChessMove::applyMove(Chessboard& chessboard, int turnNumber)
{
	chessboard.removePiece(m_start);
	assert(m_isCapture == chessboard.hasPiece(m_end));
	if (m_isCapture)
	{
		assert(m_capturedPiece != nullptr);
		chessboard.removePiece(m_end);
		m_capturedPiece->setAsCaptured();
	}
	chessboard.placePiece(m_end, m_chessPiece);
	m_chessPiece->increaseMoveCount();

	// If the piece is a pawn and it just made a double move
	if (m_chessPiece->getPieceType() == PieceType::pawn && abs(m_end.row - m_start.row) == 2)
	{
		if (m_chessPiece->getPieceColor() == PieceColor::white)
		{
			dynamic_cast<WhitePawn&>(*m_chessPiece).setDoubleMoveTurn(turnNumber);
		}
		else if (m_chessPiece->getPieceColor() == PieceColor::black)
		{
			dynamic_cast<BlackPawn&>(*m_chessPiece).setDoubleMoveTurn(turnNumber);
		}
	}
}

void ChessMove::undoMove(Chessboard& chessboard)
{
	// If the piece is a pawn and it just made a double move which needs to be undone
	if (m_chessPiece->getPieceType() == PieceType::pawn && abs(m_end.row - m_start.row) == 2)
	{
		if (m_chessPiece->getPieceColor() == PieceColor::white)
		{
			dynamic_cast<WhitePawn&>(*m_chessPiece).setDoubleMoveTurn(0);
		}
		else if (m_chessPiece->getPieceColor() == PieceColor::black)
		{
			dynamic_cast<BlackPawn&>(*m_chessPiece).setDoubleMoveTurn(0);
		}
	}

	m_chessPiece->decreaseMoveCount();
	chessboard.removePiece(m_end);
	if (m_isCapture)
	{
		m_capturedPiece->setCapturedStatus(false);
		chessboard.placePiece(m_end, m_capturedPiece);
	}
	chessboard.placePiece(m_start, m_chessPiece);
}

Coordinates ChessMove::getStart() const
{
	return m_start;
}

Coordinates ChessMove::getEnd() const
{
	return m_end;
}

std::string ChessMove::toString() const
{
	const std::string currentPiece{ m_chessPiece->toString().at(1) };
	if (m_chessPiece->getPieceType() == PieceType::pawn)
	{
		return {m_start.toString() + (m_isCapture ? "x" : "-") + m_end.toString()};
	}
	return {currentPiece + m_start.toString() + (m_isCapture ? "x" : "-") + m_end.toString()};
}

// Promotion methods
Promotion::Promotion(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, std::shared_ptr<ChessPiece> capturedPiece,
	std::shared_ptr<ChessPiece> promotedPiece) : ChessMove(chessPiece, start, end, isCapture, capturedPiece), m_promotedPiece(promotedPiece) {}

void Promotion::applyMove(Chessboard& chessboard, int turnNumber)
{
	chessboard.removePiece(m_start);
	assert(m_chessPiece->getPieceType() == PieceType::pawn);
	assert(m_isCapture == chessboard.hasPiece(m_end));
	assert(m_start.row == 1 || m_start.row == 6);
	assert(m_end.row == 0 || m_end.row == 7);
	if (m_isCapture)
	{
		assert(m_capturedPiece);
		chessboard.removePiece(m_end);
		m_capturedPiece->setAsCaptured();
	}
	chessboard.placePiece(m_end, m_promotedPiece);
}

void Promotion::undoMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_end);
	if (m_isCapture)
	{
		m_capturedPiece->setCapturedStatus(false);
		chessboard.placePiece(m_end, m_capturedPiece);
	}
	chessboard.placePiece(m_start, m_chessPiece);
}

std::string Promotion::toString() const
{
	const std::string promotedPiece{ m_promotedPiece->toString().at(1) };
	return {m_start.toString() + (m_isCapture ? "x" : "-") + m_end.toString() + "=" + promotedPiece};
}

// EnPassant methods
EnPassant::EnPassant(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end, std::shared_ptr<ChessPiece> capturedPiece)
		: ChessMove(chessPiece, start, end, true, capturedPiece) {}

void EnPassant::applyMove(Chessboard& chessboard, int turnNumber)
{
	assert(m_chessPiece->getPieceType() == PieceType::pawn);
	assert(m_start.row == 3 || m_start.row == 4);

	Coordinates capturedPawnSquare{m_start.row, m_end.col};
	assert(m_capturedPiece->getPieceType() == PieceType::pawn);
	chessboard.removePiece(capturedPawnSquare);
	m_capturedPiece->setAsCaptured();

	chessboard.removePiece(m_start);
	m_chessPiece->increaseMoveCount();
	chessboard.placePiece(m_end, m_chessPiece);
}

void EnPassant::undoMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_end);
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);

	m_capturedPiece->setCapturedStatus(false);
	Coordinates capturedPawnSquare{m_start.row, m_end.col};
	chessboard.placePiece(capturedPawnSquare, m_capturedPiece);
}

std::string EnPassant::toString() const
{
	return {m_start.toString() + "x" + m_end.toString()};
}

// CastleShort methods
CastleShort::CastleShort(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end)
		: ChessMove(chessPiece, start, end, false, nullptr) {}

void CastleShort::applyMove(Chessboard& chessboard, int turnNumber)
{
	// Extra checks to make sure that the castling is legal
	assert(m_chessPiece->getPieceType() == PieceType::king);
	assert(!m_chessPiece->hasMoved());
	assert(m_start.col == 4);
	assert(m_end.col == 6);
	assert(m_start.row == m_end.row);
	assert(!chessboard.hasPiece(m_end));

	Coordinates castlingRookSquare{ m_start.row, 7 };
	Coordinates targetRookSquare{ m_start.row, 5 };
	assert(!chessboard.getPiece(castlingRookSquare)->hasMoved());
	assert(!chessboard.hasPiece(targetRookSquare));
	std::shared_ptr<ChessPiece> castlingRook(chessboard.getPiece(castlingRookSquare));
	assert(castlingRook->getPieceType() == PieceType::rook);
	
	// Moving the king
	chessboard.removePiece(m_start);
	m_chessPiece->increaseMoveCount();
	chessboard.placePiece(m_end, m_chessPiece);

	// Moving the rook
	chessboard.removePiece(castlingRookSquare);
	m_chessPiece->increaseMoveCount();
	chessboard.placePiece(targetRookSquare, castlingRook);
}

void CastleShort::undoMove(Chessboard& chessboard)
{
	Coordinates castlingRookSquare{ m_start.row, 7 };
	Coordinates targetRookSquare{ m_start.row, 5 };
	std::shared_ptr<ChessPiece> castlingRook(chessboard.getPiece(castlingRookSquare));

	// Unmoving the rook
	chessboard.removePiece(targetRookSquare);
	castlingRook->decreaseMoveCount();
	chessboard.placePiece(castlingRookSquare, castlingRook);

	// Unmoving the king
	chessboard.removePiece(m_end);
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);
}

std::string CastleShort::toString() const
{
	return "0-0";
}

// CastleLong methods
CastleLong::CastleLong(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end)
		: ChessMove(chessPiece, start, end, false, nullptr) {}


void CastleLong::applyMove(Chessboard& chessboard, int turnNumber)
{
	// Extra checks to make sure that the castling is legal
	assert(m_chessPiece->getPieceType() == PieceType::king);
	assert(!m_chessPiece->hasMoved());
	assert(m_start.col == 4);
	assert(m_end.col == 2);
	assert(m_start.row == m_end.row);
	assert(!chessboard.hasPiece(m_end));

	Coordinates castlingRookSquare{ m_start.row, 0 };
	Coordinates targetRookSquare{ m_start.row, 3 };
	assert(!chessboard.getPiece(castlingRookSquare)->hasMoved());
	assert(!chessboard.hasPiece(targetRookSquare));
	std::shared_ptr<ChessPiece> castlingRook(chessboard.getPiece(castlingRookSquare));
	assert(castlingRook->getPieceType() == PieceType::rook);
	
	// Moving the king
	chessboard.removePiece(m_start);
	m_chessPiece->increaseMoveCount();
	chessboard.placePiece(m_end, m_chessPiece);

	// Moving the rook
	chessboard.removePiece(castlingRookSquare);
	m_chessPiece->increaseMoveCount();
	chessboard.placePiece(targetRookSquare, castlingRook);
}

void CastleLong::undoMove(Chessboard& chessboard)
{
	Coordinates castlingRookSquare{ m_start.row, 0 };
	Coordinates targetRookSquare{ m_start.row, 3 };
	std::shared_ptr<ChessPiece> castlingRook(chessboard.getPiece(castlingRookSquare));

	// Unmoving the rook
	chessboard.removePiece(targetRookSquare);
	castlingRook->decreaseMoveCount();
	chessboard.placePiece(castlingRookSquare, castlingRook);

	// Unmoving the king
	chessboard.removePiece(m_end);
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);
}

std::string CastleLong::toString() const
{
	return "0-0-0";
}

// MoveHistory methods
MoveHistory::MoveHistory() {}

int MoveHistory::getTurnNumber() const
{
	return 1 + m_moveHistory.size() / 2;
}

void MoveHistory::addMove(std::shared_ptr<ChessMove> move)
{
	m_moveHistory.push_back(move);
}

void MoveHistory::popMove()
{
	m_moveHistory.pop_back();
}

std::string MoveHistory::toString() const
{
	std::string moveHistoryString{};
	for (int i{ 0 }; i < m_moveHistory.size(); ++i)
	{
		std::shared_ptr<ChessMove> move{ m_moveHistory[i] };
		std::string turnNumber{ i % 2 == 0 ? std::to_string(1 + i / 2) + (i % 2 == 0 ? ".  " : "   ")
				: (i % 2 == 0 ? ".  " : "   ") };
		moveHistoryString += turnNumber + move->toString() + (i % 2 == 0 ? "" : "\n");
	}
	return moveHistoryString;
}

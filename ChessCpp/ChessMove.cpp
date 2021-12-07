#include <cassert>

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessMove.h"

// ChessMove methods
ChessMove::ChessMove(ChessPiece* chessPiece, const Coordinates start, const Coordinates end,
		const bool isCapture, ChessPiece* capturedPiece)
		: m_chessPiece{ chessPiece }, m_start{ start }, m_end{ end },
		m_isCapture{ isCapture }, m_capturedPiece{ capturedPiece }
{

}

void ChessMove::applyMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_start);
	assert(m_isCapture == chessboard.hasPiece(m_end));
	if (m_isCapture)
	{
		assert(!m_capturedPiece);
		assert(m_capturedPiece == &(chessboard.getPiece(m_end)));
		chessboard.removePiece(m_end);
		m_capturedPiece->setAsCaptured();
	}
	chessboard.placePiece(m_end, m_chessPiece);
	m_chessPiece->increaseMoveCount();
}

void ChessMove::undoMove(Chessboard& chessboard)
{
	m_chessPiece->decreaseMoveCount();
	if (!m_capturedPiece)
	{
		m_chessPiece->setCapturedStatus(false);
		chessboard.placePiece(m_end, m_capturedPiece);
	}
	chessboard.placePiece(m_start, m_chessPiece);
}

// Promotion methods
Promotion::Promotion(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, ChessPiece* capturedPiece,
	ChessPiece* promotedPiece) : ChessMove(chessPiece, start, end, isCapture, capturedPiece), m_promotedPiece(promotedPiece) {}

void Promotion::applyMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_start);
	assert(m_isCapture == chessboard.hasPiece(m_end));
	assert(m_start.row == 1 || m_start.row == 6);
	assert(m_end.row == 0 || m_end.row == 7);
	if (m_isCapture)
	{
		assert(!m_capturedPiece);
		assert(m_capturedPiece == &(chessboard.getPiece(m_end)));
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

// EnPassant methods
EnPassant::EnPassant(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece)
		: ChessMove(chessPiece, start, end, true, capturedPiece) {}

void EnPassant::applyMove(Chessboard& chessboard)
{
	assert(&(chessboard.getPiece(m_end)) != m_capturedPiece);
	assert(m_start.row == 3 || m_start.row == 4);

	Coordinates capturedPawnSquare{m_start.row, m_end.col};
	assert(&(chessboard.getPiece(capturedPawnSquare)) == m_capturedPiece);
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

// CastleShort methods
CastleShort::CastleShort(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece)
		: ChessMove(chessPiece, start, end, false, capturedPiece) {}

void CastleShort::applyMove(Chessboard& chessboard)
{
	// Extra checks to make sure that the castling is legal
	assert(!m_chessPiece->hasMoved());
	assert(m_start.col == 4);
	assert(m_end.col == 6);
	assert(m_start.row == m_end.row);
	assert(!chessboard.hasPiece(m_end));

	Coordinates castlingRookSquare{ m_start.row, 7 };
	Coordinates targetRookSquare{ m_start.row, 5 };
	assert(!chessboard.getPiece(castlingRookSquare).hasMoved());
	assert(!chessboard.hasPiece(targetRookSquare));
	ChessPiece* castlingRook(&(chessboard.getPiece(castlingRookSquare)));
	
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
	ChessPiece* castlingRook(&(chessboard.getPiece(castlingRookSquare)));

	// Unmoving the rook
	chessboard.removePiece(targetRookSquare);
	castlingRook->decreaseMoveCount();
	chessboard.placePiece(castlingRookSquare, castlingRook);

	// Unmoving the king
	chessboard.removePiece(m_end);
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);
}

// CastleLong methods
CastleLong::CastleLong(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece)
		: ChessMove(chessPiece, start, end, false, capturedPiece) {}

void CastleLong::applyMove(Chessboard& chessboard)
{
	// Extra checks to make sure that the castling is legal
	assert(!m_chessPiece->hasMoved());
	assert(m_start.col == 4);
	assert(m_end.col == 2);
	assert(m_start.row == m_end.row);
	assert(!chessboard.hasPiece(m_end));

	Coordinates castlingRookSquare{ m_start.row, 0 };
	Coordinates targetRookSquare{ m_start.row, 3 };
	assert(!chessboard.getPiece(castlingRookSquare).hasMoved());
	assert(!chessboard.hasPiece(targetRookSquare));
	ChessPiece* castlingRook(&(chessboard.getPiece(castlingRookSquare)));
	
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
	ChessPiece* castlingRook(&(chessboard.getPiece(castlingRookSquare)));

	// Unmoving the rook
	chessboard.removePiece(targetRookSquare);
	castlingRook->decreaseMoveCount();
	chessboard.placePiece(castlingRookSquare, castlingRook);

	// Unmoving the king
	chessboard.removePiece(m_end);
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);
}


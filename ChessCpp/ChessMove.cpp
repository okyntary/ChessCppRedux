#include <cassert>

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessMove.h"

ChessMove::ChessMove(ChessPiece* chessPiece, const Coordinates start, const Coordinates end,
		const bool isCapture, ChessPiece* capturedPiece)
		: m_chessPiece{ chessPiece }, m_start{ start }, m_end{ end },
		m_isCapture{ isCapture }, m_capturedPiece{ capturedPiece } {}

void ChessMove::applyMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_start);
	if (chessboard.hasPiece(m_end))
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
	if (!m_capturedPiece)
	{
		m_chessPiece->setCapturedStatus(false);
		chessboard.placePiece(m_end, m_capturedPiece);
	}
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start, m_chessPiece);
}


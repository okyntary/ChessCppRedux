#include <cassert>

#include "Chessboard.h"
#include "ChessMove.h"

ChessMove::ChessMove(ChessPiece* chessPiece, const int start_x, const int start_y,
		const int end_x, const int end_y, const bool isCapture, ChessPiece* capturedPiece)
		: m_chessPiece{ chessPiece }, m_start_x{ start_x }, m_start_y{ start_y }, m_end_x{ end_x },
		m_end_y{ end_y }, m_isCapture{ isCapture }, m_capturedPiece{ capturedPiece } {}

void ChessMove::applyMove(Chessboard& chessboard)
{
	chessboard.removePiece(m_start_x, m_start_y);
	if (chessboard.hasPiece(m_end_x, m_end_y))
	{
		assert(!m_capturedPiece);
		assert(m_capturedPiece == &(chessboard.getPiece(m_end_x, m_end_y)));
		chessboard.removePiece(m_end_x, m_end_y);
		m_capturedPiece->setAsCaptured();
	}
	chessboard.placePiece(m_end_x, m_end_y, m_chessPiece);
	m_chessPiece->increaseMoveCount();
}

void ChessMove::undoMove(Chessboard& chessboard)
{
	if (!m_capturedPiece)
	{
		m_chessPiece->setCapturedStatus(false);
		chessboard.placePiece(m_end_x, m_end_y, m_capturedPiece);
	}
	m_chessPiece->decreaseMoveCount();
	chessboard.placePiece(m_start_x, m_start_y, m_chessPiece);
}


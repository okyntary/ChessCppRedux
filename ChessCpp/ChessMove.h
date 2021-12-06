#pragma once

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessPiece.h"

class ChessMove
{
private:
	ChessPiece* m_chessPiece{ nullptr };
	const Coordinates m_start;
	const Coordinates m_end;
	const bool m_isCapture{};
	ChessPiece* m_capturedPiece{ nullptr };
	
public:
	ChessMove(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, ChessPiece* capturedPiece);
	virtual void applyMove(Chessboard& chessboard);
	// Can only be done right after apply move is done
	virtual void undoMove(Chessboard& chessboard);
};

class Promotion : public ChessMove
{
private:
	ChessPiece* m_promotedPiece{ nullptr };
public:
	Promotion(ChessPiece* promotedPiece);
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class EnPassant : public ChessMove
{
public:
	EnPassant();
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class CastleShort : public ChessMove
{
public:
	CastleShort();
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class CastleLong : public ChessMove
{
public:
	CastleLong();
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

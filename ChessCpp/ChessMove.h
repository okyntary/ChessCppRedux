#pragma once

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessPiece.h"

class ChessMove
{
protected:
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
	Promotion(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, ChessPiece* capturedPiece,
			ChessPiece* promotedPiece);
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class EnPassant : public ChessMove
{
public:
	EnPassant(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece);
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class CastleShort : public ChessMove
{
public:
	CastleShort(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece);
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class CastleLong : public ChessMove
{
public:
	CastleLong(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece);
	void applyMove(Chessboard& chessboard);
	void undoMove(Chessboard& chessboard);
};

class MoveHistory
{
private:
	std::vector<ChessMove> m_moveHistory{};

public:
	MoveHistory();
	int getTurnNumber();
	void addMove(ChessMove& chessMove);
	void removeMove();
};

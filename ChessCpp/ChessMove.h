#pragma once

#include <memory>

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
	virtual void applyMove(Chessboard& chessboard, int turnNumber);
	// Can only be done right after apply move is done
	virtual void undoMove(Chessboard& chessboard);
	Coordinates getEnd();
};

class Promotion : public ChessMove
{
private:
	ChessPiece* m_promotedPiece{ nullptr };
public:
	Promotion(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, ChessPiece* capturedPiece,
			ChessPiece* promotedPiece);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);
};

class EnPassant : public ChessMove
{
public:
	EnPassant(ChessPiece* chessPiece, const Coordinates start, const Coordinates end, ChessPiece* capturedPiece);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);
};

class CastleShort : public ChessMove
{
public:
	CastleShort(ChessPiece* chessPiece, const Coordinates start, const Coordinates end);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);
};

class CastleLong : public ChessMove
{
public:
	CastleLong(ChessPiece* chessPiece, const Coordinates start, const Coordinates end);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);
};

class MoveHistory
{
private:
	std::vector<std::shared_ptr<ChessMove>> m_moveHistory{};

public:
	MoveHistory();
	int getTurnNumber() const;
	void addMove(std::shared_ptr<ChessMove>  chessMove);
	void popMove();
};

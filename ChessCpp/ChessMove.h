#pragma once

#include <memory>
#include <string>

#include "Coordinates.h"
#include "Chessboard.h"
#include "ChessPiece.h"

class ChessMove
{
protected:
	std::shared_ptr<ChessPiece> m_chessPiece{ nullptr };
	const Coordinates m_start;
	const Coordinates m_end;
	const bool m_isCapture{};
	std::shared_ptr<ChessPiece> m_capturedPiece{ nullptr };
	
public:
	ChessMove(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, std::shared_ptr<ChessPiece> capturedPiece);
	virtual void applyMove(Chessboard& chessboard, int turnNumber);
	// Can only be done right after apply move is done
	virtual void undoMove(Chessboard& chessboard);
	Coordinates getStart() const;
	Coordinates getEnd() const;

	virtual std::string toString() const;
};

class Promotion : public ChessMove
{
private:
	std::shared_ptr<ChessPiece> m_promotedPiece{ nullptr };
public:
	Promotion(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end, const bool isCapture, std::shared_ptr<ChessPiece> capturedPiece,
			std::shared_ptr<ChessPiece> promotedPiece);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);

	std::string toString() const override;
};

class EnPassant : public ChessMove
{
public:
	EnPassant(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end, std::shared_ptr<ChessPiece> capturedPiece);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);

	std::string toString() const override;
};

class CastleShort : public ChessMove
{
public:
	CastleShort(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);

	std::string toString() const override;
};

class CastleLong : public ChessMove
{
public:
	CastleLong(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end);
	void applyMove(Chessboard& chessboard, int turnNumber);
	void undoMove(Chessboard& chessboard);

	std::string toString() const override;
};

class MoveHistory
{
private:
	std::vector<std::shared_ptr<ChessMove>> m_moveHistory{};

public:
	MoveHistory();
	int getTurnNumber() const;
	void addMove(std::shared_ptr<ChessMove> chessMove);
	void popMove();
};

#include "Model.h"
#include "Chessboard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

Model::Model()
{
	initialize();
}

void Model::setView(View* view)
{
	m_view = view;
	updateView();
}

void Model::updateView() const
{
	m_view->update();
	m_view->display();
}

void Model::initialize()
{
	// Initial set of pieces
	static WhiteKing wk1{};
	static WhiteQueen wq1{};
	static WhiteRook wr1{};
	static WhiteRook wr2{};
	static WhiteBishop wb1{};
	static WhiteBishop wb2{};
	static WhiteKnight wn1{};
	static WhiteKnight wn2{};
	static WhitePawn wp1{};
	static WhitePawn wp2{};
	static WhitePawn wp3{};
	static WhitePawn wp4{};
	static WhitePawn wp5{};
	static WhitePawn wp6{};
	static WhitePawn wp7{};
	static WhitePawn wp8{};
	static BlackKing bk1{};
	static BlackQueen bq1{};
	static BlackRook br1{};
	static BlackRook br2{};
	static BlackBishop bb1{};
	static BlackBishop bb2{};
	static BlackKnight bn1{};
	static BlackKnight bn2{};
	static BlackPawn bp1{};
	static BlackPawn bp2{};
	static BlackPawn bp3{};
	static BlackPawn bp4{};
	static BlackPawn bp5{};
	static BlackPawn bp6{};
	static BlackPawn bp7{};
	static BlackPawn bp8{};

	for (int i = 0; i < 32; ++i)
	{
		switch (i)
		{
		case 0:
			m_chessPieces[i] = &wk1;
			m_chessboard.placePiece(0, 4, m_chessPieces[i]);
			break;
		case 1:
			m_chessPieces[i] = &wq1;
			m_chessboard.placePiece(0, 3, m_chessPieces[i]);
			break;
		case 2:
			m_chessPieces[i] = &wr1;
			m_chessboard.placePiece(0, 0, m_chessPieces[i]);
			break;
		case 3:
			m_chessPieces[i] = &wr2;
			m_chessboard.placePiece(0, 7, m_chessPieces[i]);
			break;
		case 4:
			m_chessPieces[i] = &wb1;
			m_chessboard.placePiece(0, 2, m_chessPieces[i]);
			break;
		case 5:
			m_chessPieces[i] = &wb2;
			m_chessboard.placePiece(0, 5, m_chessPieces[i]);
			break;
		case 6:
			m_chessPieces[i] = &wn1;
			m_chessboard.placePiece(0, 1, m_chessPieces[i]);
			break;
		case 7:
			m_chessPieces[i] = &wn2;
			m_chessboard.placePiece(0, 6, m_chessPieces[i]);
			break;
		case 8:
			m_chessPieces[i] = &wp1;
			m_chessboard.placePiece(1, 0, m_chessPieces[i]);
			break;
		case 9:
			m_chessPieces[i] = &wp2;
			m_chessboard.placePiece(1, 1, m_chessPieces[i]);
			break;
		case 10:
			m_chessPieces[i] = &wp3;
			m_chessboard.placePiece(1, 2, m_chessPieces[i]);
			break;
		case 11:
			m_chessPieces[i] = &wp4;
			m_chessboard.placePiece(1, 3, m_chessPieces[i]);
			break;
		case 12:
			m_chessPieces[i] = &wp5;
			m_chessboard.placePiece(1, 4, m_chessPieces[i]);
			break;
		case 13:
			m_chessPieces[i] = &wp6;
			m_chessboard.placePiece(1, 5, m_chessPieces[i]);
			break;
		case 14:
			m_chessPieces[i] = &wp7;
			m_chessboard.placePiece(1, 6, m_chessPieces[i]);
			break;
		case 15:
			m_chessPieces[i] = &wp8;
			m_chessboard.placePiece(1, 7, m_chessPieces[i]);
			break;
		case 16:
			m_chessPieces[i] = &bk1;
			m_chessboard.placePiece(7, 4, m_chessPieces[i]);
			break;
		case 17:
			m_chessPieces[i] = &bq1;
			m_chessboard.placePiece(7, 3, m_chessPieces[i]);
			break;
		case 18:
			m_chessPieces[i] = &br1;
			m_chessboard.placePiece(7, 0, m_chessPieces[i]);
			break;
		case 19:
			m_chessPieces[i] = &br2;
			m_chessboard.placePiece(7, 7, m_chessPieces[i]);
			break;
		case 20:
			m_chessPieces[i] = &bb1;
			m_chessboard.placePiece(7, 2, m_chessPieces[i]);
			break;
		case 21:
			m_chessPieces[i] = &bb2;
			m_chessboard.placePiece(7, 5, m_chessPieces[i]);
			break;
		case 22:
			m_chessPieces[i] = &bn1;
			m_chessboard.placePiece(7, 1, m_chessPieces[i]);
			break;
		case 23:
			m_chessPieces[i] = &bn2;
			m_chessboard.placePiece(7, 6, m_chessPieces[i]);
			break;
		case 24:
			m_chessPieces[i] = &bp1;
			m_chessboard.placePiece(6, 0, m_chessPieces[i]);
			break;
		case 25:
			m_chessPieces[i] = &bp2;
			m_chessboard.placePiece(6, 1, m_chessPieces[i]);
			break;
		case 26:
			m_chessPieces[i] = &bp3;
			m_chessboard.placePiece(6, 2, m_chessPieces[i]);
			break;
		case 27:
			m_chessPieces[i] = &bp4;
			m_chessboard.placePiece(6, 3, m_chessPieces[i]);
			break;
		case 28:
			m_chessPieces[i] = &bp5;
			m_chessboard.placePiece(6, 4, m_chessPieces[i]);
			break;
		case 29:
			m_chessPieces[i] = &bp6;
			m_chessboard.placePiece(6, 5, m_chessPieces[i]);
			break;
		case 30:
			m_chessPieces[i] = &bp7;
			m_chessboard.placePiece(6, 6, m_chessPieces[i]);
			break;
		case 31:
			m_chessPieces[i] = &bp8;
			m_chessboard.placePiece(6, 7, m_chessPieces[i]);
			break;
		default:
			m_chessPieces[i] = nullptr;
			break;
		}
	}
}

void Model::testMove()
{
	ChessMove move1{ m_chessPieces[6], 0, 1, 2, 2, false, nullptr };
	move1.applyMove(m_chessboard);
}

void Model::testUndoMove()
{
	ChessMove move1{ m_chessPieces[6], 0, 1, 2, 2, false, nullptr };
	move1.undoMove(m_chessboard);
}

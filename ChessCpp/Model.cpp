#include <cassert>


#include "Model.h"
#include "Coordinates.h"
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
			m_chessboard.placePiece(Coordinates{ 0, 4 }, m_chessPieces[i]);
			break;
		case 1:
			m_chessPieces[i] = &wq1;
			m_chessboard.placePiece(Coordinates{ 0, 3 }, m_chessPieces[i]);
			break;
		case 2:
			m_chessPieces[i] = &wr1;
			m_chessboard.placePiece(Coordinates{ 0, 0 }, m_chessPieces[i]);
			break;
		case 3:
			m_chessPieces[i] = &wr2;
			m_chessboard.placePiece(Coordinates{ 0, 7 }, m_chessPieces[i]);
			break;
		case 4:
			m_chessPieces[i] = &wb1;
			m_chessboard.placePiece(Coordinates{ 0, 2 }, m_chessPieces[i]);
			break;
		case 5:
			m_chessPieces[i] = &wb2;
			m_chessboard.placePiece(Coordinates{ 0, 5 }, m_chessPieces[i]);
			break;
		case 6:
			m_chessPieces[i] = &wn1;
			m_chessboard.placePiece(Coordinates{ 0, 1 }, m_chessPieces[i]);
			break;
		case 7:
			m_chessPieces[i] = &wn2;
			m_chessboard.placePiece(Coordinates{ 0, 6 }, m_chessPieces[i]);
			break;
		case 8:
			m_chessPieces[i] = &wp1;
			m_chessboard.placePiece(Coordinates{ 1, 0 }, m_chessPieces[i]);
			break;
		case 9:
			m_chessPieces[i] = &wp2;
			m_chessboard.placePiece(Coordinates{ 1, 1 }, m_chessPieces[i]);
			break;
		case 10:
			m_chessPieces[i] = &wp3;
			m_chessboard.placePiece(Coordinates{ 1, 2 }, m_chessPieces[i]);
			break;
		case 11:
			m_chessPieces[i] = &wp4;
			m_chessboard.placePiece(Coordinates{ 1, 3 }, m_chessPieces[i]);
			break;
		case 12:
			m_chessPieces[i] = &wp5;
			m_chessboard.placePiece(Coordinates{ 1, 4 }, m_chessPieces[i]);
			break;
		case 13:
			m_chessPieces[i] = &wp6;
			m_chessboard.placePiece(Coordinates{ 1, 5 }, m_chessPieces[i]);
			break;
		case 14:
			m_chessPieces[i] = &wp7;
			m_chessboard.placePiece(Coordinates{ 1, 6 }, m_chessPieces[i]);
			break;
		case 15:
			m_chessPieces[i] = &wp8;
			m_chessboard.placePiece(Coordinates{ 1, 7 }, m_chessPieces[i]);
			break;
		case 16:
			m_chessPieces[i] = &bk1;
			m_chessboard.placePiece(Coordinates{ 7, 4 }, m_chessPieces[i]);
			break;
		case 17:
			m_chessPieces[i] = &bq1;
			m_chessboard.placePiece(Coordinates{ 7, 3 }, m_chessPieces[i]);
			break;
		case 18:
			m_chessPieces[i] = &br1;
			m_chessboard.placePiece(Coordinates{ 7, 0 }, m_chessPieces[i]);
			break;
		case 19:
			m_chessPieces[i] = &br2;
			m_chessboard.placePiece(Coordinates{ 7, 7 }, m_chessPieces[i]);
			break;
		case 20:
			m_chessPieces[i] = &bb1;
			m_chessboard.placePiece(Coordinates{ 7, 2 }, m_chessPieces[i]);
			break;
		case 21:
			m_chessPieces[i] = &bb2;
			m_chessboard.placePiece(Coordinates{ 7, 5 }, m_chessPieces[i]);
			break;
		case 22:
			m_chessPieces[i] = &bn1;
			m_chessboard.placePiece(Coordinates{ 7, 1 }, m_chessPieces[i]);
			break;
		case 23:
			m_chessPieces[i] = &bn2;
			m_chessboard.placePiece(Coordinates{ 7, 6 }, m_chessPieces[i]);
			break;
		case 24:
			m_chessPieces[i] = &bp1;
			m_chessboard.placePiece(Coordinates{ 6, 0 }, m_chessPieces[i]);
			break;
		case 25:
			m_chessPieces[i] = &bp2;
			m_chessboard.placePiece(Coordinates{ 6, 1 }, m_chessPieces[i]);
			break;
		case 26:
			m_chessPieces[i] = &bp3;
			m_chessboard.placePiece(Coordinates{ 6, 2 }, m_chessPieces[i]);
			break;
		case 27:
			m_chessPieces[i] = &bp4;
			m_chessboard.placePiece(Coordinates{ 6, 3 }, m_chessPieces[i]);
			break;
		case 28:
			m_chessPieces[i] = &bp5;
			m_chessboard.placePiece(Coordinates{ 6, 4 }, m_chessPieces[i]);
			break;
		case 29:
			m_chessPieces[i] = &bp6;
			m_chessboard.placePiece(Coordinates{ 6, 5 }, m_chessPieces[i]);
			break;
		case 30:
			m_chessPieces[i] = &bp7;
			m_chessboard.placePiece(Coordinates{ 6, 6 }, m_chessPieces[i]);
			break;
		case 31:
			m_chessPieces[i] = &bp8;
			m_chessboard.placePiece(Coordinates{ 6, 7 }, m_chessPieces[i]);
			break;
		default:
			m_chessPieces[i] = nullptr;
			break;
		}
	}
}

ChessPiece& Model::getPromotionPiece(PieceColor color, PieceType type)
{
	// This isn't the best way to handle promoted pieces, but I'm not comfortable enough with smart pointers to use them just yet
	static NullPiece nullPiece{};
	static WhiteQueen promotedWhiteQueen{};
	static WhiteRook promotedWhiteRook{};
	static WhiteBishop promotedWhiteBishop{};
	static WhiteKnight promotedWhiteKnight{};
	static BlackQueen promotedBlackQueen{};
	static BlackRook promotedBlackRook{};
	static BlackBishop promotedBlackBishop{};
	static BlackKnight promotedBlackKnight{};

	if (color == PieceColor::white)
	{
		switch (type)
		{
		case PieceType::queen:
			return promotedWhiteQueen;
		case PieceType::rook:
			return promotedWhiteRook;
		case PieceType::bishop:
			return promotedWhiteBishop;
		case PieceType::knight:
			return promotedWhiteKnight;
		default:
			break;
		}
	}
	else if (color == PieceColor::white)
	{
		switch (type)
		{
		case PieceType::queen:
			return promotedBlackQueen;
		case PieceType::rook:
			return promotedBlackRook;
		case PieceType::bishop:
			return promotedBlackBishop;
		case PieceType::knight:
			return promotedBlackKnight;
		default:
			break;
		}
	}
	return nullPiece;
}

bool Model::hasNoCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const
{
	PieceColor pieceColor{ chessPiece.getPieceColor() }; 
	PieceType pieceType{ chessPiece.getPieceType() };
	switch (pieceType)
	{
	case PieceType::king:
	case PieceType::knight:
		return !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end).getPieceColor() != pieceColor;
	case PieceType::queen:
		return hasNoQueenCollision(chessPiece, start, end);
	case PieceType::rook:
		return hasNoRookCollision(chessPiece, start, end);
	case PieceType::bishop:
		return hasNoBishopCollision(chessPiece, start, end);
	case PieceType::pawn:
		return hasNoPawnCollision(chessPiece, start, end);
	case PieceType::null:
	default:
		return false;
	}
}

bool Model::hasNoQueenCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const
{
	bool onSameRankOrFile{ start.row == end.row || start.col == end.col };
	bool onSameDiagonal{ abs(start.row - end.row) == abs(start.col - end.col) };
	if (onSameRankOrFile) return hasNoRookCollision(chessPiece, start, end);
	if (onSameDiagonal) return hasNoBishopCollision(chessPiece, start, end);
	return false;
}

bool Model::hasNoRookCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const
{
	Coordinates currentCoordinates{ end };
	// Checks if end square is empty, or if is not empty, then checks if the piece on that square is oppositely colored
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end).getPieceColor() != chessPiece.getPieceColor() };

	bool isSameCol{ start.col == end.col };
	bool isSameRow{ start.row == end.row };
	assert(isSameRow != isSameCol);

	while (start.row != currentCoordinates.row ^ start.col != currentCoordinates.col)
	{
		// hasNoCollision set to false if there is a piece in the current square
		hasNoCollision = !m_chessboard.hasPiece(currentCoordinates);
		// If hasNoCollision is false at any point, the function returns false immediately
		if (!hasNoCollision) return false;

		if (isSameCol)
		{
			if (start.row > currentCoordinates.row) ++currentCoordinates.row;
			else --currentCoordinates.row;
		}
		else if (isSameRow)
		{
			if (start.col > currentCoordinates.col) ++currentCoordinates.col;
			else --currentCoordinates.col;
		}
	}

	return hasNoCollision;
}

bool Model::hasNoBishopCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const
{
	Coordinates currentCoordinates{ end };
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end).getPieceColor() != chessPiece.getPieceColor() };

	assert(abs(start.row - end.row) == abs(start.col - end.col));

	while (start.row != currentCoordinates.row && start.col != currentCoordinates.col)
	{
		// hasNoCollision set to false if there is a piece in the current square
		hasNoCollision = !m_chessboard.hasPiece(currentCoordinates);
		// If hasNoCollision is false at any point, the function returns false immediately
		if (!hasNoCollision) return false;
		
		if (start.row > currentCoordinates.row) ++currentCoordinates.row;
		else --currentCoordinates.row;

		if (start.col > currentCoordinates.col) ++currentCoordinates.col;
		else --currentCoordinates.col;
	}
	return hasNoCollision;
}

bool Model::hasNoPawnCollision(const ChessPiece& chessPiece, const Coordinates start, const Coordinates end) const
{
	bool isPawnCapture{ start.col != end.col };
	// If the move is a diagonal pawn capture
	if (isPawnCapture)
	{
		return m_chessboard.hasPiece(end) && m_chessboard.getPiece(end).getPieceColor() != chessPiece.getPieceColor();
	}

	// If the move is moving two spaces at the start
	bool isDoubleMove{ static_cast<int>(abs(end.row - start.row)) == 2 };
	if (isDoubleMove)
	{
		// The square between the start and the end
		Coordinates nextSquare{ (start.row + end.row) / 2, start.col };
		return !(m_chessboard.hasPiece(nextSquare) || m_chessboard.hasPiece(end));
	}
	
	// Else, the move must be a single move forwards
	return !m_chessboard.hasPiece(end);
}

std::vector<ChessMove> Model::generatePlausibleMoves()
{
	std::vector<ChessMove> plausibleMoves{};
	// Loop through all squares of the chessboard
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			// j is the row number, i is the col number
			Coordinates currentSquare{ j, i };
			ChessPiece& currentPiece{m_chessboard.getPiece(currentSquare)};
			// Skip the square if it has no piece, or if its piece is differently-colored from the current player
			if (!m_chessboard.hasPiece(currentSquare) ||
				currentPiece.getPieceColor() != static_cast<PieceColor>(m_currentPlayer)) continue;

			std::vector<Coordinates> targetSquares = currentPiece.getTargetSquares(currentSquare);

			for (auto targetSquare : targetSquares)
			{
				if (hasNoCollision(currentPiece, currentSquare, targetSquare))
				{
					bool isCapture{ m_chessboard.hasPiece(targetSquare) };
					ChessPiece* capturedPiece{ nullptr };
					if (isCapture) capturedPiece = &(m_chessboard.getPiece(targetSquare));
					// Account for promotion in generatePlausibleMoves(), because accounting for it later would require that I
					// replace existing plausibleMoves
					bool isPawn = currentPiece.getPieceType() == PieceType::pawn;
					bool isOnSeventhRank = currentPiece.getPieceColor() == PieceColor::white
							? currentSquare.row == 6 : currentSquare.row == 1;
					if (isPawn && isOnSeventhRank)
					{
						plausibleMoves.push_back(Promotion);
					}
					plausibleMoves.push_back(ChessMove{ &currentPiece, currentSquare, targetSquare, isCapture, capturedPiece});
				}
			}
		}
	}
	return plausibleMoves;
}

void Model::testMove()
{
	ChessMove move1{ m_chessPieces[6], Coordinates{ 0, 1 }, Coordinates{ 2, 2 }, false, nullptr };
	move1.applyMove(m_chessboard);
}

void Model::testUndoMove()
{
	ChessMove move1{ m_chessPieces[6], Coordinates{0, 1}, Coordinates{2,2}, false, nullptr };
	move1.undoMove(m_chessboard);
}

void Model::testPlausibleMoves()
{
	std::vector<ChessMove> plausibleMoves{ generatePlausibleMoves() };
	plausibleMoves;
}

void Model::testTargetSquares()
{
	std::vector<Coordinates> targetSquares1 = m_chessPieces[6]->getTargetSquares(Coordinates{ 0, 1 });
	std::cout << "Knight at b1:\n";
	for (int i = 0; i < targetSquares1.size(); ++i)
	{
		std::cout << "(" << targetSquares1.at(i).row << ", " << targetSquares1.at(i).col << ")\n";
	}

	std::cout << "Rook at a1:\n";
	std::vector<Coordinates> targetSquares2 = m_chessPieces[2]->getTargetSquares(Coordinates{ 0, 0 });
	for (int i = 0; i < targetSquares2.size(); ++i)
	{
		std::cout << "(" << targetSquares2.at(i).row << ", " << targetSquares2.at(i).col << ")\n";
	}

	std::cout << "Bishop at c1:\n";
	std::vector<Coordinates> targetSquares3 = m_chessPieces[4]->getTargetSquares(Coordinates{ 0, 2 });
	for (int i = 0; i < targetSquares3.size(); ++i)
	{
		std::cout << "(" << targetSquares3.at(i).row << ", " << targetSquares3.at(i).col << ")\n";
	}

	std::cout << "Queen at d1:\n";
	std::vector<Coordinates> targetSquares4 = m_chessPieces[1]->getTargetSquares(Coordinates{ 0, 3 });
	for (int i = 0; i < targetSquares4.size(); ++i)
	{
		std::cout << "(" << targetSquares4.at(i).row << ", " << targetSquares4.at(i).col << ")\n";
	}

	std::cout << "King at e1:\n";
	std::vector<Coordinates> targetSquares5 = m_chessPieces[0]->getTargetSquares(Coordinates{ 0, 4 });
	for (int i = 0; i < targetSquares5.size(); ++i)
	{
		std::cout << "(" << targetSquares5.at(i).row << ", " << targetSquares5.at(i).col << ")\n";
	}

	std::cout << "Pawn at h2:\n";
	std::vector<Coordinates> targetSquares6 = m_chessPieces[15]->getTargetSquares(Coordinates{ 1, 7 });
	for (int i = 0; i < targetSquares6.size(); ++i)
	{
		std::cout << "(" << targetSquares6.at(i).row << ", " << targetSquares6.at(i).col << ")\n";
	}

	std::cout << "Pawn at d7:\n";
	std::vector<Coordinates> targetSquares7 = m_chessPieces[27]->getTargetSquares(Coordinates{ 6, 3 });
	for (int i = 0; i < targetSquares7.size(); ++i)
	{
		std::cout << "(" << targetSquares7.at(i).row << ", " << targetSquares7.at(i).col << ")\n";
	}
}

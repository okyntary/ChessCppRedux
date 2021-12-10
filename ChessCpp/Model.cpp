#include <cassert>
#include <memory>
#include <vector>

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

	for (int i{ 0 }; i < 32; ++i)
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

	m_validMoves = generateValidMoves();
}

int Model::getTurnNumber() const
{
	return m_moveHistory.getTurnNumber();
}

ChessPiece& Model::getPromotionPiece(PieceColor color, PieceType type) const
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
	else if (color == PieceColor::black)
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

Player Model::getOtherPlayer(Player player)
{
	switch (player)
	{
	case Player::white:
		return Player::black;
	case Player::black:
		return Player::white;
	default:
		return Player::null;
	}
	
}

void Model::swapCurrentPlayer()
{
	m_currentPlayer = getOtherPlayer(m_currentPlayer);
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
	bool isSameCol{ start.col == end.col };
	bool isSameRow{ start.row == end.row };
	assert(isSameRow != isSameCol);

	Coordinates currentCoordinates{ end };
	// Checks if end square is empty, or if is not empty, then checks if the piece on that square is oppositely colored
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end).getPieceColor() != chessPiece.getPieceColor() };
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

	while ((start.row != currentCoordinates.row) ^ (start.col != currentCoordinates.col))
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
	assert(abs(start.row - end.row) == abs(start.col - end.col));

	Coordinates currentCoordinates{ end };
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end).getPieceColor() != chessPiece.getPieceColor() };
	if (!hasNoCollision) return false;

	if (start.row > currentCoordinates.row) ++currentCoordinates.row;
	else --currentCoordinates.row;

	if (start.col > currentCoordinates.col) ++currentCoordinates.col;
	else --currentCoordinates.col;

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

std::vector<std::shared_ptr<ChessMove>> Model::generatePlausibleMoves()
{
	return generatePlausibleMoves(m_currentPlayer);
}

std::vector<std::shared_ptr<ChessMove>> Model::generatePlausibleMoves(Player player)
{
	std::vector<std::shared_ptr<ChessMove>> plausibleMoves{};
	// Loop through all squares of the chessboard
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			// j is the row number, i is the col number
			Coordinates currentSquare{ j, i };
			ChessPiece& currentPiece{m_chessboard.getPiece(currentSquare)};
			// Skip the square if it has no piece, or if its piece is differently-colored from the current player
			if (!m_chessboard.hasPiece(currentSquare) ||
				currentPiece.getPieceColor() != static_cast<PieceColor>(player)) continue;

			std::vector<Coordinates> targetSquares = currentPiece.getTargetSquares(currentSquare);

			for (auto targetSquare : targetSquares)
			{
				if (hasNoCollision(currentPiece, currentSquare, targetSquare))
				{
					bool isCapture{ m_chessboard.hasPiece(targetSquare) };
					ChessPiece* capturedPiece{ nullptr };
					if (isCapture) capturedPiece = &(m_chessboard.getPiece(targetSquare));
					// Account for promotion in generatePlausibleMoves(), because accounting for it later would require that I
					// replace existing plausible moves
					PieceColor pieceColor = currentPiece.getPieceColor();
					PieceType pieceType = currentPiece.getPieceType();
					bool isPawn = pieceType == PieceType::pawn;
					bool isOnSeventhRank = pieceColor == PieceColor::white ? currentSquare.row == 6 : currentSquare.row == 1;
					if (isPawn && isOnSeventhRank)
					{
						plausibleMoves.push_back(std::make_shared<Promotion>(&currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, &getPromotionPiece(pieceColor, PieceType::queen)));
						plausibleMoves.push_back(std::make_shared<Promotion>(&currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, &getPromotionPiece(pieceColor, PieceType::rook)));
						plausibleMoves.push_back(std::make_shared<Promotion>(&currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, &getPromotionPiece(pieceColor, PieceType::bishop)));
						plausibleMoves.push_back(std::make_shared<Promotion>(&currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, &getPromotionPiece(pieceColor, PieceType::knight)));
					}
					else
					{
						plausibleMoves.push_back(std::make_shared<ChessMove>(&currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece));
					}
				}
			}
		}
	}
	return plausibleMoves;
}

std::vector<std::shared_ptr<ChessMove>> Model::generateValidMoves()
{
	std::vector<std::shared_ptr<ChessMove>> validMoves{};
	
	// Account for castling
	bool isCurrentlyChecked{ isChecked() };
	int castlingRow{ m_currentPlayer == Player::white ? 0 : 7 };
	PieceColor currentPlayer{ static_cast<PieceColor>(m_currentPlayer) };

	Coordinates kingSquare{ castlingRow, 4 };
	ChessPiece& king{ m_chessboard.getPiece(kingSquare) };
	bool kingHasNotMoved{m_chessboard.hasPiece(kingSquare) && king.isCorrectPiece(currentPlayer, PieceType::king) && !king.hasMoved()};

	ChessPiece& kingRook{ m_chessboard.getPiece({castlingRow, 7}) };
	bool kingRookHasNotMoved{ m_chessboard.hasPiece({ castlingRow, 7 }) && kingRook.isCorrectPiece(currentPlayer, PieceType::rook) && !kingRook.hasMoved()
};

	ChessPiece& queenRook{ m_chessboard.getPiece({castlingRow, 0}) };
	bool queenRookHasNotMoved{ m_chessboard.hasPiece({castlingRow, 0}) && queenRook.isCorrectPiece(currentPlayer, PieceType::rook) && !queenRook.hasMoved() };

	std::vector<std::shared_ptr<ChessMove>> opponentPlausibleMoves{ generatePlausibleMoves(getOtherPlayer(m_currentPlayer)) };

	// Check if short castling is possible
	if (!isCurrentlyChecked && kingHasNotMoved && kingRookHasNotMoved)
	{
		// Check if the space between king and rook is empty
		Coordinates oneSquareAway{ castlingRow, 5 };
		Coordinates twoSquaresAway{ castlingRow, 6 };
		if (!m_chessboard.hasPiece(oneSquareAway) && !m_chessboard.hasPiece(twoSquaresAway))
		{
			bool isSafeToCastle{ true };

			// Check if any square between king and its final destination is under attack
			for (auto& plausibleMove : opponentPlausibleMoves)
			{
				Coordinates endSquare{ plausibleMove->getEnd() };
				if ((endSquare.row == oneSquareAway.row && endSquare.col == oneSquareAway.col) ||
						(endSquare.row == twoSquaresAway.row && endSquare.col == twoSquaresAway.col))
				{
					isSafeToCastle = false;
					break;
				}
			}

			if (isSafeToCastle)
			{
				validMoves.push_back(std::make_shared<CastleShort>(&king, kingSquare, twoSquaresAway));
			}
		}
	}

	// Check if long castling is possible
	if (!isCurrentlyChecked && kingHasNotMoved && queenRookHasNotMoved)
	{
		// Check if the space between king and rook is empty
		Coordinates oneSquareAway{ castlingRow, 3 };
		Coordinates twoSquaresAway{ castlingRow, 2 };
		if (!m_chessboard.hasPiece(oneSquareAway) && !m_chessboard.hasPiece(twoSquaresAway))
		{
			bool isSafeToCastle{ true };

			// Check if any square between king and its final destination is under attack
			for (auto& plausibleMove : opponentPlausibleMoves)
			{
				Coordinates endSquare{ plausibleMove->getEnd() };
				if ((endSquare.row == oneSquareAway.row && endSquare.col == oneSquareAway.col) ||
						(endSquare.row == twoSquaresAway.row && endSquare.col == twoSquaresAway.col))
				{
					isSafeToCastle = false;
					break;
				}
			}

			if (isSafeToCastle)
			{
				validMoves.push_back(std::make_shared<CastleLong>(&king, kingSquare, twoSquaresAway));
			}
		}
	}
	
	// Account for en passant by checking the fifth rank from whichever player is currently playing
	for (Coordinates currentSquare{ m_currentPlayer == Player::white ? 4 : 3, 0}; currentSquare.col < 8; ++currentSquare.col)
	{
		if (!m_chessboard.hasPiece(currentSquare)) continue;

		ChessPiece& currentPiece{ m_chessboard.getPiece(currentSquare) };
		// Check if there is a pawn of the right color on the square
		if (currentPiece.isCorrectPiece(static_cast<PieceColor>(m_currentPlayer), PieceType::pawn))
		{
			// Find the target squares (diagonally adjacent to currentSquare);
			int targetSquareRow{ m_currentPlayer == Player::white ? 5 : 2 };
			std::vector<Coordinates> targetSquares{ {targetSquareRow, currentSquare.col - 1},
					{targetSquareRow, currentSquare.col + 1} };
			for (auto& targetSquare : targetSquares)
			{
				// Check that the target square is empty
				if (targetSquare.isOnBoard() && !m_chessboard.hasPiece(targetSquare))
				{
					// Get the adjacent square
					Coordinates adjacentSquare{ currentSquare.row, targetSquare.col };
					// Check if the piece in the adjacent square (1) is a pawn of the opposite color and (2) has just moved
					if (m_chessboard.hasPiece(adjacentSquare))
					{
						ChessPiece& adjacentPiece{m_chessboard.getPiece(adjacentSquare)};
						// Adjacent piece is pawn of opposite color
						if (adjacentPiece.isCorrectPiece(static_cast<PieceColor>(getOtherPlayer(m_currentPlayer)),
							PieceType::pawn))
						{
							if (getOtherPlayer(m_currentPlayer) == Player::white)
							{
								WhitePawn* adjacentPawn{dynamic_cast<WhitePawn*>(&adjacentPiece)};
								if (adjacentPawn->hasDoubleMoved() && adjacentPawn->getDoubleMoveTurn() == getTurnNumber())
								{
									validMoves.push_back(std::make_shared<EnPassant>(&currentPiece, currentSquare,
											targetSquare, adjacentPawn));
								}
							}
							else if (getOtherPlayer(m_currentPlayer) == Player::black)
							{
								BlackPawn* adjacentPawn{dynamic_cast<BlackPawn*>(&adjacentPiece)};
								if (adjacentPawn->hasDoubleMoved() && adjacentPawn->getDoubleMoveTurn() == getTurnNumber())
								{
									validMoves.push_back(std::make_shared<EnPassant>(&currentPiece, currentSquare,
											targetSquare, adjacentPawn));
								}
							}
						}
					}
				}
			}
		}
	}
	
	std::vector<std::shared_ptr<ChessMove>> playerPlausibleMoves{ generatePlausibleMoves() };
	for (auto& plausibleMove : playerPlausibleMoves)
	{
		Player currentPlayer{ m_currentPlayer };
		simulateMove(plausibleMove);
		if (!isChecked(currentPlayer)) validMoves.push_back(plausibleMove);
		undoMove(plausibleMove);
	}
	return validMoves;
}

bool Model::validateMove(const ChessMove& move) const
{
	// todo
	return true;
}

void Model::enterMove(const std::string& move) const
{
	// todo
}

Coordinates Model::getPlayerKingSquare(Player player)
{
	Coordinates playerKingSquare{ -1, -1 };
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			Coordinates currentSquare{ j ,i };
			if (m_chessboard.hasPiece(currentSquare))
			{
				ChessPiece& currentPiece{ m_chessboard.getPiece(currentSquare) };
				if (currentPiece.isCorrectPiece(static_cast<PieceColor>(player), PieceType::king)) return currentSquare;
			}
		}
	}
	return playerKingSquare;
}

bool Model::isChecked()
{
	return isChecked(m_currentPlayer);
}

bool Model::isChecked(Player player)
{
	std::vector<std::shared_ptr<ChessMove>> plausibleOpponentMoves{ generatePlausibleMoves(getOtherPlayer(player)) };
	Coordinates kingSquare{ getPlayerKingSquare(player) };
	for (auto& plausibleMove : plausibleOpponentMoves)
	{
		Coordinates endSquare{ plausibleMove->getEnd() };
		if (endSquare.row == kingSquare.row && endSquare.col == kingSquare.col) return true;
	}
	return false;
}

bool Model::isCheckmated()
{
	return isCheckmated(m_currentPlayer);
}

bool Model::isCheckmated(Player player)
{
	return isChecked(player) && m_validMoves.size() == 0;
}

bool Model::isStalemated()
{
	return isStalemated(m_currentPlayer);
}

bool Model::isStalemated(Player player)
{
	return !isChecked(player) && m_validMoves.size() == 0;
}

void Model::simulateMove(std::shared_ptr<ChessMove>& move)
{
	swapCurrentPlayer();
	m_moveHistory.addMove(move);
	move->applyMove(m_chessboard, getTurnNumber());
}

void Model::undoMove(std::shared_ptr<ChessMove>& move)
{
	move->undoMove(m_chessboard);
	m_moveHistory.popMove();
	swapCurrentPlayer();
}

void Model::applyMove(std::shared_ptr<ChessMove>& move)
{
	simulateMove(move);
	updateView();
	m_validMoves = generateValidMoves();

	// Check for stalemate and checkmate
	if (isCheckmated())
	{
		m_view->isCheckmated();
	}

	if (isStalemated())
	{
		m_view->isStalemated();
	}
}

void Model::testMoves()
{
	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move1{ std::make_shared<ChessMove>(m_chessPieces[12], Coordinates{1, 4},
			Coordinates{3, 4}, false, nullptr) };
	applyMove(move1);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move2{ std::make_shared<ChessMove>(m_chessPieces[27], Coordinates{6, 3}, Coordinates{5, 3}, false, nullptr) };
	applyMove(move2);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move3{ std::make_shared<ChessMove>(m_chessPieces[5], Coordinates{0, 5}, Coordinates{4, 1}, false, nullptr) };
	applyMove(move3);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move4{ std::make_shared<ChessMove>(m_chessPieces[26], Coordinates{6, 2}, Coordinates{5, 2}, false, nullptr) };
	applyMove(move4);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move5{ std::make_shared<ChessMove>(m_chessPieces[5], Coordinates{4, 1}, Coordinates{5, 2}, true, m_chessPieces[26]) };
	applyMove(move5);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move6{ std::make_shared<ChessMove>(m_chessPieces[17], Coordinates{7, 3}, Coordinates{6, 3}, false, nullptr) };
	applyMove(move6);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move7{ std::make_shared<ChessMove>(m_chessPieces[7], Coordinates{0, 6}, Coordinates{2, 5}, false, nullptr) };
	applyMove(move7);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move8{ std::make_shared<ChessMove>(m_chessPieces[28], Coordinates{6, 5}, Coordinates{4, 5}, false, nullptr) };
	applyMove(move8);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move9{ std::make_shared<ChessMove>(m_chessPieces[12], Coordinates{3, 4}, Coordinates{4, 5}, true, m_chessPieces[28]) };
	applyMove(move9);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move10{ std::make_shared<ChessMove>(m_chessPieces[30], Coordinates{6, 6}, Coordinates{4, 6}, false, nullptr) };
	applyMove(move10);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move11{ std::make_shared<CastleShort>(m_chessPieces[0], Coordinates{0, 4}, Coordinates{0, 6}) };
	applyMove(move11);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move12{ std::make_shared<ChessMove>(m_chessPieces[28], Coordinates{6, 4}, Coordinates{4, 4}, false, nullptr) };
	applyMove(move12);

	std::cout << isChecked() << '\n';
	std::shared_ptr<ChessMove> move13{ std::make_shared<EnPassant>(m_chessPieces[12], Coordinates{4, 5}, Coordinates{5, 4}, m_chessPieces[28]) };
	applyMove(move13);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move11{ std::make_shared<ChessMove>(m_chessPieces[0], Coordinates{0, 4}, Coordinates{0, 5}, false, nullptr) };
	//applyMove(move11);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move12{ std::make_shared<ChessMove>(m_chessPieces[17], Coordinates{6, 3}, Coordinates{5, 2}, true, m_chessPieces[5]) };
	//applyMove(move12);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move13{ std::make_shared<ChessMove>(m_chessPieces[12], Coordinates{4, 5}, Coordinates{5, 5}, false, nullptr) };
	//applyMove(move13);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move14{ std::make_shared<ChessMove>(m_chessPieces[16], Coordinates{7, 4}, Coordinates{7, 3}, false, nullptr) };
	//applyMove(move14);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move15{ std::make_shared<ChessMove>(m_chessPieces[12], Coordinates{5, 5}, Coordinates{6, 4}, true, m_chessPieces[28]) };
	//applyMove(move15);

	//std::cout << isChecked() << '\n';
	//std::shared_ptr<ChessMove> move16{ std::make_shared<ChessMove>(m_chessPieces[16], Coordinates{7, 3}, Coordinates{6, 2}, false, nullptr) };
	//applyMove(move16);

	;
}

void Model::testPlausibleMoves()
{
	std::vector<std::shared_ptr<ChessMove>> plausibleMovesWhite{ generatePlausibleMoves() };
	std::vector<std::shared_ptr<ChessMove>> plausibleMovesBlack{ generatePlausibleMoves(Player::black) };
	plausibleMovesWhite;
	plausibleMovesBlack;
}

void Model::testCheckmate()
{
	std::shared_ptr<ChessMove> move1{ std::make_shared<ChessMove>(m_chessPieces[13], Coordinates{1, 5}, Coordinates{3, 5}, false, nullptr) };
	applyMove(move1);

	std::shared_ptr<ChessMove> move2{ std::make_shared<ChessMove>(m_chessPieces[28], Coordinates{6, 4}, Coordinates{4, 4}, false, nullptr) };
	applyMove(move2);

	std::shared_ptr<ChessMove> move3{ std::make_shared<ChessMove>(m_chessPieces[14], Coordinates{1, 6}, Coordinates{3, 6}, false, nullptr) };
	applyMove(move3);
	
	std::shared_ptr<ChessMove> move4{ std::make_shared<ChessMove>(m_chessPieces[17], Coordinates{7, 3}, Coordinates{3, 7}, false, nullptr) };
	applyMove(move4);

	//std::cout << "Is checkmated: " << isCheckmated() << '\n';
}

void Model::testTargetSquares()
{
	std::vector<Coordinates> targetSquares1 = m_chessPieces[6]->getTargetSquares(Coordinates{ 0, 1 });
	std::cout << "Knight at b1:\n";
	for (int i{ 0 }; i < targetSquares1.size(); ++i)
	{
		std::cout << "(" << targetSquares1.at(i).row << ", " << targetSquares1.at(i).col << ")\n";
	}

	std::cout << "Rook at a1:\n";
	std::vector<Coordinates> targetSquares2 = m_chessPieces[2]->getTargetSquares(Coordinates{ 0, 0 });
	for (int i{ 0 }; i < targetSquares2.size(); ++i)
	{
		std::cout << "(" << targetSquares2.at(i).row << ", " << targetSquares2.at(i).col << ")\n";
	}

	std::cout << "Bishop at c1:\n";
	std::vector<Coordinates> targetSquares3 = m_chessPieces[4]->getTargetSquares(Coordinates{ 0, 2 });
	for (int i{ 0 }; i < targetSquares3.size(); ++i)
	{
		std::cout << "(" << targetSquares3.at(i).row << ", " << targetSquares3.at(i).col << ")\n";
	}

	std::cout << "Queen at d1:\n";
	std::vector<Coordinates> targetSquares4 = m_chessPieces[1]->getTargetSquares(Coordinates{ 0, 3 });
	for (int i{ 0 }; i < targetSquares4.size(); ++i)
	{
		std::cout << "(" << targetSquares4.at(i).row << ", " << targetSquares4.at(i).col << ")\n";
	}

	std::cout << "King at e1:\n";
	std::vector<Coordinates> targetSquares5 = m_chessPieces[0]->getTargetSquares(Coordinates{ 0, 4 });
	for (int i{ 0 }; i < targetSquares5.size(); ++i)
	{
		std::cout << "(" << targetSquares5.at(i).row << ", " << targetSquares5.at(i).col << ")\n";
	}

	std::cout << "Pawn at h2:\n";
	std::vector<Coordinates> targetSquares6 = m_chessPieces[15]->getTargetSquares(Coordinates{ 1, 7 });
	for (int i{ 0 }; i < targetSquares6.size(); ++i)
	{
		std::cout << "(" << targetSquares6.at(i).row << ", " << targetSquares6.at(i).col << ")\n";
	}

	std::cout << "Pawn at d7:\n";
	std::vector<Coordinates> targetSquares7 = m_chessPieces[27]->getTargetSquares(Coordinates{ 6, 3 });
	for (int i{ 0 }; i < targetSquares7.size(); ++i)
	{
		std::cout << "(" << targetSquares7.at(i).row << ", " << targetSquares7.at(i).col << ")\n";
	}
}

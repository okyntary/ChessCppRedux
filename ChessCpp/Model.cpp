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

void Model::setEngine(Engine* engine)
{
	m_engine = engine;
}

void Model::runEngine() const
{
	m_engine->playMove();
}

void Model::initialize()
{
	for (int i{ 0 }; i < 32; ++i)
	{
		switch (i)
		{
		case 0:
			m_chessPieces[i] = std::make_shared<WhiteKing>();
			m_chessboard.placePiece(Coordinates{ 0, 4 }, m_chessPieces[i]);
			break;
		case 1:
			m_chessPieces[i] = std::make_shared<WhiteQueen>();
			m_chessboard.placePiece(Coordinates{ 0, 3 }, m_chessPieces[i]);
			break;
		case 2:
			m_chessPieces[i] = std::make_shared<WhiteRook>();
			m_chessboard.placePiece(Coordinates{ 0, 0 }, m_chessPieces[i]);
			break;
		case 3:
			m_chessPieces[i] = std::make_shared<WhiteRook>();
			m_chessboard.placePiece(Coordinates{ 0, 7 }, m_chessPieces[i]);
			break;
		case 4:
			m_chessPieces[i] = std::make_shared<WhiteBishop>();
			m_chessboard.placePiece(Coordinates{ 0, 2 }, m_chessPieces[i]);
			break;
		case 5:
			m_chessPieces[i] = std::make_shared<WhiteBishop>();
			m_chessboard.placePiece(Coordinates{ 0, 5 }, m_chessPieces[i]);
			break;
		case 6:
			m_chessPieces[i] = std::make_shared<WhiteKnight>();
			m_chessboard.placePiece(Coordinates{ 0, 1 }, m_chessPieces[i]);
			break;
		case 7:
			m_chessPieces[i] = std::make_shared<WhiteKnight>();
			m_chessboard.placePiece(Coordinates{ 0, 6 }, m_chessPieces[i]);
			break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			m_chessPieces[i] = std::make_shared<WhitePawn>();
			m_chessboard.placePiece(Coordinates{ 1, i - 8 }, m_chessPieces[i]);
			break;
		case 16:
			m_chessPieces[i] = std::make_shared<BlackKing>();
			m_chessboard.placePiece(Coordinates{ 7, 4 }, m_chessPieces[i]);
			break;
		case 17:
			m_chessPieces[i] = std::make_shared<BlackQueen>();
			m_chessboard.placePiece(Coordinates{ 7, 3 }, m_chessPieces[i]);
			break;
		case 18:
			m_chessPieces[i] = std::make_shared<BlackRook>();
			m_chessboard.placePiece(Coordinates{ 7, 0 }, m_chessPieces[i]);
			break;
		case 19:
			m_chessPieces[i] = std::make_shared<BlackRook>();
			m_chessboard.placePiece(Coordinates{ 7, 7 }, m_chessPieces[i]);
			break;
		case 20:
			m_chessPieces[i] = std::make_shared<BlackBishop>();
			m_chessboard.placePiece(Coordinates{ 7, 2 }, m_chessPieces[i]);
			break;
		case 21:
			m_chessPieces[i] = std::make_shared<BlackBishop>();
			m_chessboard.placePiece(Coordinates{ 7, 5 }, m_chessPieces[i]);
			break;
		case 22:
			m_chessPieces[i] = std::make_shared<BlackKnight>();
			m_chessboard.placePiece(Coordinates{ 7, 1 }, m_chessPieces[i]);
			break;
		case 23:
			m_chessPieces[i] = std::make_shared<BlackKnight>();
			m_chessboard.placePiece(Coordinates{ 7, 6 }, m_chessPieces[i]);
			break;
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			m_chessPieces[i] = std::make_shared<BlackPawn>();
			m_chessboard.placePiece(Coordinates{ 6, i - 24 }, m_chessPieces[i]);
			break;
		default:
			m_chessPieces[i] = nullptr;
			break;
		}
	}

	m_validMoves = generateValidMoves();
}

void Model::resetChessboard()
{
	for (auto& chessPiece : m_chessPieces)
	{
		chessPiece->resetPiece();
	}

	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			m_chessboard.removePiece({i, j});
		}
	}
	m_validMoves = {};
	m_moveHistory = {};
	m_currentPlayer = Player::white;

	for (int i{ 0 }; i < 32; ++i)
	{
		switch (i)
		{
		case 0:
			m_chessboard.placePiece(Coordinates{ 0, 4 }, m_chessPieces[i]);
			break;
		case 1:
			m_chessboard.placePiece(Coordinates{ 0, 3 }, m_chessPieces[i]);
			break;
		case 2:
			m_chessboard.placePiece(Coordinates{ 0, 0 }, m_chessPieces[i]);
			break;
		case 3:
			m_chessboard.placePiece(Coordinates{ 0, 7 }, m_chessPieces[i]);
			break;
		case 4:
			m_chessboard.placePiece(Coordinates{ 0, 2 }, m_chessPieces[i]);
			break;
		case 5:
			m_chessboard.placePiece(Coordinates{ 0, 5 }, m_chessPieces[i]);
			break;
		case 6:
			m_chessboard.placePiece(Coordinates{ 0, 1 }, m_chessPieces[i]);
			break;
		case 7:
			m_chessboard.placePiece(Coordinates{ 0, 6 }, m_chessPieces[i]);
			break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			m_chessboard.placePiece(Coordinates{ 1, i - 8 }, m_chessPieces[i]);
			break;
		case 16:
			m_chessboard.placePiece(Coordinates{ 7, 4 }, m_chessPieces[i]);
			break;
		case 17:
			m_chessboard.placePiece(Coordinates{ 7, 3 }, m_chessPieces[i]);
			break;
		case 18:
			m_chessboard.placePiece(Coordinates{ 7, 0 }, m_chessPieces[i]);
			break;
		case 19:
			m_chessboard.placePiece(Coordinates{ 7, 7 }, m_chessPieces[i]);
			break;
		case 20:
			m_chessboard.placePiece(Coordinates{ 7, 2 }, m_chessPieces[i]);
			break;
		case 21:
			m_chessboard.placePiece(Coordinates{ 7, 5 }, m_chessPieces[i]);
			break;
		case 22:
			m_chessboard.placePiece(Coordinates{ 7, 1 }, m_chessPieces[i]);
			break;
		case 23:
			m_chessboard.placePiece(Coordinates{ 7, 6 }, m_chessPieces[i]);
			break;
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			m_chessboard.placePiece(Coordinates{ 6, i - 24 }, m_chessPieces[i]);
			break;
		default:
			break;
		}
	}
	m_validMoves = generateValidMoves();

	updateView();
}

int Model::getTurnNumber() const
{
	return m_moveHistory.getTurnNumber();
}

std::shared_ptr<ChessPiece> Model::getPromotionPiece(PieceColor color, PieceType type) const
{
	if (color == PieceColor::white)
	{
		switch (type)
		{
		case PieceType::queen:
			return std::make_shared<WhiteQueen>();
		case PieceType::rook:
			return std::make_shared<WhiteRook>();
		case PieceType::bishop:
			return std::make_shared<WhiteBishop>();
		case PieceType::knight:
			return std::make_shared<WhiteKnight>();
		default:
			break;
		}
	}
	else if (color == PieceColor::black)
	{
		switch (type)
		{
		case PieceType::queen:
			return std::make_shared<BlackQueen>();
		case PieceType::rook:
			return std::make_shared<BlackRook>();
		case PieceType::bishop:
			return std::make_shared<BlackBishop>();
		case PieceType::knight:
			return std::make_shared<BlackKnight>();
		default:
			break;
		}
	}
	return std::shared_ptr<NullPiece>();
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

bool Model::hasNoCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const
{
	PieceColor pieceColor{ chessPiece->getPieceColor() }; 
	PieceType pieceType{ chessPiece->getPieceType() };
	switch (pieceType)
	{
	case PieceType::king:
	case PieceType::knight:
		return !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end)->getPieceColor() != pieceColor;
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

bool Model::hasNoQueenCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const
{
	bool onSameRankOrFile{ start.row == end.row || start.col == end.col };
	bool onSameDiagonal{ abs(start.row - end.row) == abs(start.col - end.col) };
	if (onSameRankOrFile) return hasNoRookCollision(chessPiece, start, end);
	if (onSameDiagonal) return hasNoBishopCollision(chessPiece, start, end);
	return false;
}

bool Model::hasNoRookCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const
{
	bool isSameCol{ start.col == end.col };
	bool isSameRow{ start.row == end.row };
	assert(isSameRow != isSameCol);

	Coordinates currentCoordinates{ end };
	// Checks if end square is empty, or if is not empty, then checks if the piece on that square is oppositely colored
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end)->getPieceColor() != chessPiece->getPieceColor() };
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

bool Model::hasNoBishopCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const
{
	assert(abs(start.row - end.row) == abs(start.col - end.col));

	Coordinates currentCoordinates{ end };
	bool hasNoCollision{ !m_chessboard.hasPiece(end) || m_chessboard.getPiece(end)->getPieceColor() != chessPiece->getPieceColor() };
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

bool Model::hasNoPawnCollision(std::shared_ptr<ChessPiece> chessPiece, const Coordinates start, const Coordinates end) const
{
	bool isPawnCapture{ start.col != end.col };
	// If the move is a diagonal pawn capture
	if (isPawnCapture)
	{
		return m_chessboard.hasPiece(end) && m_chessboard.getPiece(end)->getPieceColor() != chessPiece->getPieceColor();
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
			std::shared_ptr<ChessPiece> currentPiece{m_chessboard.getPiece(currentSquare)};
			// Skip the square if it has no piece, or if its piece is differently-colored from the current player
			if (!m_chessboard.hasPiece(currentSquare) ||
				currentPiece->getPieceColor() != static_cast<PieceColor>(player)) continue;

			std::vector<Coordinates> targetSquares = currentPiece->getTargetSquares(currentSquare);

			for (auto targetSquare : targetSquares)
			{
				if (hasNoCollision(currentPiece, currentSquare, targetSquare))
				{
					bool isCapture{ m_chessboard.hasPiece(targetSquare) };
					std::shared_ptr<ChessPiece> capturedPiece{ nullptr };
					if (isCapture) capturedPiece = m_chessboard.getPiece(targetSquare);
					// Account for promotion in generatePlausibleMoves(), because accounting for it later would require that I
					// replace existing plausible moves
					PieceColor pieceColor = currentPiece->getPieceColor();
					PieceType pieceType = currentPiece->getPieceType();
					bool isPawn{ pieceType == PieceType::pawn };
					bool isOnSeventhRank{ pieceColor == PieceColor::white ? currentSquare.row == 6 : currentSquare.row == 1 };
					bool isPromotionCapture{ isCapture && currentSquare.col != targetSquare.col };
					bool isPromotionMove{ !isCapture && currentSquare.col == targetSquare.col };
					if (isPawn && isOnSeventhRank && (isPromotionCapture || isPromotionMove))
					{
						plausibleMoves.push_back(std::make_shared<Promotion>(currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, getPromotionPiece(pieceColor, PieceType::queen)));
						plausibleMoves.push_back(std::make_shared<Promotion>(currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, getPromotionPiece(pieceColor, PieceType::rook)));
						plausibleMoves.push_back(std::make_shared<Promotion>(currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, getPromotionPiece(pieceColor, PieceType::bishop)));
						plausibleMoves.push_back(std::make_shared<Promotion>(currentPiece, currentSquare, targetSquare,
								isCapture, capturedPiece, getPromotionPiece(pieceColor, PieceType::knight)));
					}
					else
					{
						plausibleMoves.push_back(std::make_shared<ChessMove>(currentPiece, currentSquare, targetSquare,
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
	std::vector<std::shared_ptr<ChessMove>> playerPlausibleMoves = generatePlausibleMoves();
	
	// Account for castling
	bool isCurrentlyChecked{ isChecked() };
	int castlingRow{ m_currentPlayer == Player::white ? 0 : 7 };
	PieceColor currentPlayer{ static_cast<PieceColor>(m_currentPlayer) };

	Coordinates kingSquare{ castlingRow, 4 };
	std::shared_ptr<ChessPiece> king{ m_chessboard.getPiece(kingSquare) };
	bool kingHasNotMoved{m_chessboard.hasPiece(kingSquare)
			&& king->isCorrectPiece(currentPlayer, PieceType::king) && !king->hasMoved()};

	std::shared_ptr<ChessPiece> kingRook{ m_chessboard.getPiece({castlingRow, 7}) };
	bool kingRookHasNotMoved{ m_chessboard.hasPiece({ castlingRow, 7 })
			&& kingRook->isCorrectPiece(currentPlayer, PieceType::rook) && !kingRook->hasMoved() };

	std::shared_ptr<ChessPiece> queenRook{ m_chessboard.getPiece({castlingRow, 0}) };
	bool queenRookHasNotMoved{ m_chessboard.hasPiece({castlingRow, 0})
			&& queenRook->isCorrectPiece(currentPlayer, PieceType::rook) && !queenRook->hasMoved() };

	std::vector<std::shared_ptr<ChessMove>> opponentPlausibleMoves = generatePlausibleMoves(getOtherPlayer(m_currentPlayer));

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
				playerPlausibleMoves.push_back(std::make_shared<CastleShort>(king, kingSquare, twoSquaresAway));
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
				playerPlausibleMoves.push_back(std::make_shared<CastleLong>(king, kingSquare, twoSquaresAway));
			}
		}
	}
	
	// Account for en passant by checking the fifth rank from whichever player is currently playing
	for (Coordinates currentSquare{ m_currentPlayer == Player::white ? 4 : 3, 0}; currentSquare.col < 8; ++currentSquare.col)
	{
		if (!m_chessboard.hasPiece(currentSquare)) continue;

		std::shared_ptr<ChessPiece> currentPiece{ m_chessboard.getPiece(currentSquare) };
		// Check if there is a pawn of the right color on the square
		if (currentPiece->isCorrectPiece(static_cast<PieceColor>(m_currentPlayer), PieceType::pawn))
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
						std::shared_ptr<ChessPiece> adjacentPiece{m_chessboard.getPiece(adjacentSquare)};
						// Adjacent piece is pawn of opposite color
						if (adjacentPiece->isCorrectPiece(static_cast<PieceColor>(getOtherPlayer(m_currentPlayer)),
							PieceType::pawn))
						{
							if (getOtherPlayer(m_currentPlayer) == Player::white)
							{
								if (dynamic_cast<WhitePawn&>(*adjacentPiece).hasDoubleMoved()
										&& dynamic_cast<WhitePawn&>(*adjacentPiece).getDoubleMoveTurn() == getTurnNumber())
								{
									playerPlausibleMoves.push_back(std::make_shared<EnPassant>(currentPiece, currentSquare,
											targetSquare, adjacentPiece));
								}
							}
							else if (getOtherPlayer(m_currentPlayer) == Player::black)
							if (getOtherPlayer(m_currentPlayer) == Player::white)
							{
								if (dynamic_cast<BlackPawn&>(*adjacentPiece).hasDoubleMoved()
										&& dynamic_cast<BlackPawn&>(*adjacentPiece).getDoubleMoveTurn() == getTurnNumber())
								{
									playerPlausibleMoves.push_back(std::make_shared<EnPassant>(currentPiece, currentSquare,
											targetSquare, adjacentPiece));
								}
							}
						}
					}
				}
			}
		}
	}
	
	std::vector<std::shared_ptr<ChessMove>> validMoves{};
	for (auto& plausibleMove : playerPlausibleMoves)
	{
		Player currentPlayer{ m_currentPlayer };
		simulateMove(plausibleMove);
		if (!isChecked(currentPlayer)) validMoves.push_back(plausibleMove);
		undoMove(plausibleMove);
	}
	return validMoves;
}

std::shared_ptr<ChessMove> Model::validateMove(const std::shared_ptr<ChessMove> move) const
{
	for (auto& validMove : m_validMoves)
	{
		bool sameStart{ validMove->getStart().row == move->getStart().row && validMove->getStart().col == move->getStart().col};
		bool sameEnd{ validMove->getEnd().row == move->getEnd().row && validMove->getEnd().col == move->getEnd().col};
		if (sameStart && sameEnd) return validMove;
	}
	return nullptr;
}

void Model::enterMove(std::string move)
{
	std::shared_ptr<ChessMove> enteredMove{};
	if (move == "0-0") {
		Coordinates kingSquare{ getPlayerKingSquare(m_currentPlayer) };
		std::shared_ptr<ChessPiece> king{ m_chessboard.getPiece(kingSquare) };
		Coordinates twoSquaresAway{ kingSquare.row, 6 };
		enteredMove = std::make_shared<CastleShort>(king, kingSquare, twoSquaresAway);
	}
	else if (move == "0-0-0")
	{
		Coordinates kingSquare{ getPlayerKingSquare(m_currentPlayer) };
		std::shared_ptr<ChessPiece> king{ m_chessboard.getPiece(kingSquare) };
		Coordinates twoSquaresAway{ kingSquare.row, 2 };
		enteredMove = std::make_shared<CastleLong>(king, kingSquare, twoSquaresAway);
	}
	else
	{
		assert(move.size() == 4 || move.size() == 5);

		Coordinates startSquare{ static_cast<int>(move[1] - 49), static_cast<int>(move[0] - 65) };
		Coordinates endSquare{ static_cast<int>(move[3] - 49), static_cast<int>(move[2] - 65) };

		std::shared_ptr<ChessPiece> currentPiece{ m_chessboard.getPiece(startSquare) };
		bool isCapture{ m_chessboard.hasPiece(endSquare) };
		std::shared_ptr<ChessPiece> capturedPiece{ isCapture ? m_chessboard.getPiece(endSquare) : nullptr };
		enteredMove = std::make_shared<ChessMove>(currentPiece, startSquare, endSquare, isCapture, capturedPiece);
	}

	std::shared_ptr<ChessMove> validMove{ validateMove(enteredMove) };
	if (validMove)
	{
		applyMove(validMove);
		if (!m_validMoves.empty()) runEngine();
	}
	else
	{
		m_view->invalidMoveEntered();
	}
}

void Model::enterMove(std::shared_ptr<ChessMove> move)
{
	applyMove(move);
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
				std::shared_ptr<ChessPiece> currentPiece{ m_chessboard.getPiece(currentSquare) };
				if (currentPiece->isCorrectPiece(static_cast<PieceColor>(player), PieceType::king)) return currentSquare;
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
	if (move)
	{
		swapCurrentPlayer();
		m_moveHistory.addMove(move);
		move->applyMove(m_chessboard, getTurnNumber());
	}
}

void Model::undoMove(std::shared_ptr<ChessMove>& move)
{
	if (move)
	{
		move->undoMove(m_chessboard);
		m_moveHistory.popMove();
		swapCurrentPlayer();
	}
}

void Model::undoLastMove()
{
	if (!m_moveHistory.isEmpty())
	{
		std::shared_ptr<ChessMove> lastMove{ m_moveHistory.getLastMove() };
		undoMove(lastMove);
	}
	m_validMoves = generateValidMoves();
}

void Model::applyMove(std::shared_ptr<ChessMove>& move)
{
	simulateMove(move);
	updateView();
	m_validMoves = generateValidMoves();

	// Check for stalemate and checkmate
	if (isCheckmated()) m_view->isCheckmated();
	else if (isChecked()) m_view->isChecked();
	else if (isStalemated()) m_view->isStalemated();
}

const int Model::getEvaluation() const
{
	return m_engine->evaluate();
}

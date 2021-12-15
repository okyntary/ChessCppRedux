#include "View.h"

#include <iostream>
#include <string>

const std::string View::m_welcomeMessage{"Welcome to ChessCpp (Redux).\n"
										 "Written by okyntary in Dec 2021.\n"};

const std::string View::m_helpMessage{"This is the ChessCpp help. ChessCpp is a program written in C++ that allows you to simulate a game of chess, and to play against a basic chess AI.\n\n"

"Capitalization of commands does not matter. All commands will be spelled in capital letters.\n"
"Below are the complete list of commands to use the program:\n\n"

"Core:\n"
  "\"HELP\"/\"H\"         - Shows this help message.\n"
  "\"PLAYERN\" / \"PN\"   - Sets the player to null. When the game starts, ChessCpp will not play any moves.\n"
  "\"PLAYERW\" / \"PW\"   - Sets the player to play White. When the game starts, ChessCpp will play as Black.\n"
  "\"PLAYERB\" / \"PB\"   - Sets the player to play Black. When the game starts, ChessCpp will play as White.\n"
  "\"START\"            - Starts the chess game.\n"
  "\"RESET\"            - Resets the chess game, allowing for a fresh game to be played.\n"
  "\"QUIT\" / \"Q\"       - Quits ChessCpp.\n\n"

"Playing moves:\n"
  "Moves are played, and pieces moved, by entering exactly 4 characters. The first two characters are the coordinates of the starting square of a particular piece.The last two characters are the coordinates of the ending square of that piece again.e.g. \"e2e4\" to move the piece on e2 to e4.\n\n"

  "There are three exceptions to the above rule:\n"
	"1) If the move to be made is a promotion, enter the 4 characters as detailed above, followed by an \"=\", followed by the letter of the piece to be promoted to, e.g. \"g7g8=N\" to promote a pawn to a knight on g8.If no piece is specified, the pawn automatically promotes to a queen.\n"
	"2) If the move to be made is castling kingside, enter \"0-0\".\n"
	"3) If the move to be made is castling queenside, enter \"0-0-0\".\n\n"

"Utility:\n"
  "\"UNDO\" / \"UN\"      - Undoes the last move. Cannot be used when playing against ChessCpp.\n\n"

"QOL:\n"
  "\"VALID\" / \"V\"      - Shows all legal moves that the current player can play.\n"
  "\"CAPTURED\" / \"CAP\" - Shows all the currently captured pieces.\n"
  "\"HISTORY\" / \"HIS\"  - Shows all the moves played in the game so far.\n"
  "\"DISPLAY\" / \"D\"    - Forces ChessCpp to print the chessboard.\n\n"

"Cosmetic:\n"
  "\"SIZES\" / \"SS\"     - Sets the chessboard to a small size.\n"
  "\"SIZEM\" / \"SM\"     - Sets the chessboard to a medium size.\n"
  "\"SIZEL\" / \"SL\"     - Sets the chessboard to a large size.\n"
  "\"TOGGLEF\" / \"TF\"   - Toggle the orientation of the chessboard.\n"
  "\"TOGGLEC\" / \"TC\    - Toggle showing the coordinates at the side of the chessboard.\n"};

const std::string View::mediumUpperLineBreak{ " ______ ______ ______ ______ ______ ______ ______ ______ \n"
											  "|      |      |      |      |      |      |      |      |\n" };
const std::string View::mediumInnerLineBreak{ "|______|______|______|______|______|______|______|______|\n"
											  "|      |      |      |      |      |      |      |      |\n" };
const std::string View::mediumLowerLineBreak{ "|______|______|______|______|______|______|______|______|\n" };


const std::string View::largeUpperLineBreak{ " __________ __________ __________ __________ __________ __________ __________ __________ \n"
						                     "|          |          |          |          |          |          |          |          |\n"
						                     "|          |          |          |          |          |          |          |          |\n" };
const std::string View::largeInnerLineBreak{ "|          |          |          |          |          |          |          |          |\n"
                                             "|__________|__________|__________|__________|__________|__________|__________|__________|\n"
							                 "|          |          |          |          |          |          |          |          |\n"
							                 "|          |          |          |          |          |          |          |          |\n" };
const std::string View::largeLowerLineBreak{ "|          |          |          |          |          |          |          |          |\n"
											 "|__________|__________|__________|__________|__________|__________|__________|__________|\n" };

void View::showValidMoves() const
{
	std::cout << "Valid moves for current player: \n";

	int turnNumber{m_model->getTurnNumber()};
	Player currentPlayer{ m_model->m_currentPlayer };
	for (auto& validMove : m_model->m_validMoves)
	{
		const std::string turn{std::to_string(turnNumber) + ". "};
		const std::string playerColor{currentPlayer == Player::white ? "" : "..."};
		std::cout << turn + playerColor + validMove->toString() + '\n';
	}
}

void View::validMoveEntered() const
{
	std::cout << "Valid move entered.\n";
}

void View::invalidMoveEntered() const
{
	std::cout << "Invalid move entered.\n";
}

void View::undoLastMove()
{
	std::cout << "Last move undone.\n";
	update();
	display();
}

void View::resetChessboard() const
{
	std::cout << "Chessboard reset.";
}

void View::showSwapColors() const
{
	std::cout << "Swapping colors.";
}

void View::showCapturedPieces() const
{
	std::cout << "Captured pieces: \n";
	std::string capturedPiecesString{};
	for (auto& piece : m_model->m_chessPieces)
	{
		if (piece->isCaptured()) capturedPiecesString += piece->toString() + "\n";
	}
	std::cout << capturedPiecesString;
}

void View::showMoveHistory() const
{
	std::cout << "Moves played so far:\n";
	const std::string moveHistoryString{m_model->m_moveHistory.toString()};
	std::cout << m_model->m_moveHistory.toString();
}

void View::showWelcome() const
{
	std::cout << m_welcomeMessage;
}

void View::showHelpMessage() const
{
	std::cout << m_helpMessage;
}

void View::showGameStarted() const
{
	std::cout << "Game has started.\n";
}

void View::showGameNotStarted() const
{
	std::cout << "Game has not started yet.\n";
}

void View::showGameAlreadyStarted() const
{
	std::cout << "Game has already started.\n";
}

void View::showChooseColor(Player player) const
{
	if (player == Player::null)
	{
		std::cout << "No player.\n";
	}
	else if (player == Player::white)
	{
		std::cout << "White to play.\n";
	}
	else if (player == Player::black)
	{
		std::cout << "Black to play.\n";
	}
}

void View::showCannotChooseColor() const
{
	std::cout << "The game has already started. Reset the game to change colors.\n";
}

void View::isCheckmated() const
{
	const std::string currentPlayer{m_model->m_currentPlayer == Player::white ? "White" : "Black"};
	std::cout << currentPlayer << " is checkmated.\n";
}

void View::isChecked() const
{
	const std::string currentPlayer{m_model->m_currentPlayer == Player::white ? "White" : "Black"};
	std::cout << currentPlayer << " is checked.\n";
}

void View::isStalemated() const
{
	const std::string currentPlayer{m_model->m_currentPlayer == Player::white ? "White" : "Black"};
	std::cout << currentPlayer << " is stalemated.\n";
}
void View::setSize(Size size)
{
	m_size = size;
	update();
	display();
}

void View::toggleFlippedStatus()
{
	m_flippedStatus = m_flippedStatus ^ 1;
	update();
	display();
}

void View::toggleCoords()
{
	m_showCoords = m_showCoords ^ 1;
	update();
	display();
}

void View::showEngineEvaluation() const
{
	std::cout << "Evaluation: " + std::to_string(m_model->getEvaluation()) + "\n";
}

void View::update()
{
	// std::cout << "Updating chessboard.\n";
	if (m_size == Size::small)
	{
		if (!m_flippedStatus)
		{
			if (!m_showCoords) updateUnflippedSmallCoordless();
			else updateUnflippedSmallCoordful();
		}
		else
		{
			if (!m_showCoords) updateFlippedSmallCoordless();
			else updateFlippedSmallCoordful();
		}
	}
	else if (m_size == Size::medium)
	{
		if (!m_flippedStatus)
		{
			if (!m_showCoords) updateUnflippedMediumCoordless();
			else updateUnflippedMediumCoordful();
;
		}
		else
		{
			if (!m_showCoords) updateFlippedMediumCoordless();
			else updateFlippedMediumCoordful();
		}
	}
	else if (m_size == Size::large)
	{
		if (!m_flippedStatus)
		{
			if (!m_showCoords) updateUnflippedLargeCoordless();
			else updateUnflippedLargeCoordful();
		}
		else
		{
			if (!m_showCoords) updateFlippedLargeCoordless();
			else updateFlippedLargeCoordful();
		}
	}
	// Remove later?
	// if (m_model) showEngineEvaluation();
}

void View::updateUnflippedSmallCoordless()
{
	m_display = "";
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|" + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString();
			}
			else
			{
				m_display += "|  ";
			}
		}
		m_display += "|\n";
	}
}

void View::updateUnflippedSmallCoordful()
{
	char currChar{ '8' };
	m_display = "";
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|" + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString();
			}
			else
			{
				m_display += "|  ";
			}
		}
		m_display += {'|', ' ', currChar, '\n'};
		--currChar;
	}
	m_display += " A  B  C  D  E  F  G  H";
}

void View::updateFlippedSmallCoordless()
{
	m_display = "";
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|" + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString();
			}
			else
			{
				m_display += "|  ";
			}
		}
		m_display += "|\n";
	}
}

void View::updateFlippedSmallCoordful()
{
	char currChar { '1' };
	m_display = "";
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|" + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString();
			}
			else
			{
				m_display += "|  ";
			}
		}
		m_display += {'|', ' ', currChar, '\n'};
		++currChar;
	}
	m_display += " H  G  F  E  D  C  B  A";
}

void View::updateUnflippedMediumCoordless()
{
	m_display = mediumUpperLineBreak;
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|  " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "  ";
			}
			else
			{
				m_display += "|      ";
			}
		}
		if (i > 0) m_display += "|\n" + mediumInnerLineBreak;
		else m_display += "|\n" + mediumLowerLineBreak;
	}
}

void View::updateUnflippedMediumCoordful()
{
	m_display = mediumUpperLineBreak;
	char currChar{ '8' };
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|  " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "  ";
			}
			else
			{
				m_display += "|      ";
			}
		}
		if (i > 0) m_display += std::string{ '|', ' ', currChar, '\n'} + mediumInnerLineBreak;
		else m_display += std::string{'|', ' ', currChar, '\n'} + mediumLowerLineBreak;
		--currChar;
	}
	m_display += "   A      B      C      D      E      F      G      H";
}

void View::updateFlippedMediumCoordless()
{
	m_display = mediumUpperLineBreak;
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|  " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "  ";
			}
			else
			{
				m_display += "|      ";
			}
		}
		if (i < 7) m_display += "|\n" + mediumInnerLineBreak;
		else m_display += "|\n" + mediumLowerLineBreak;
	}
}

void View::updateFlippedMediumCoordful()
{
	m_display = mediumUpperLineBreak;
	char currChar{ '1' };
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|  " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "  ";
			}
			else
			{
				m_display += "|      ";
			}
		}
		if (i < 7) m_display += std::string{ '|', ' ', currChar, '\n'} + mediumInnerLineBreak;
		else m_display += std::string{'|', ' ', currChar, '\n'} + mediumLowerLineBreak;
		++currChar;
	}
	m_display += "   H      G      F      E      D      C      B      A";
}

void View::updateUnflippedLargeCoordless()
{
	m_display = largeUpperLineBreak;
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|    " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "    ";
			}
			else
			{
				m_display += "|          ";
			}
		}
		if (i > 0) m_display += "|\n" + largeInnerLineBreak;
		else m_display += "|\n" + largeLowerLineBreak;
	}
}

void View::updateUnflippedLargeCoordful()
{
	m_display = largeUpperLineBreak;
	char currChar{ '8' };
	for (int i{ 7 }; i >= 0; --i)
	{
		for (int j{ 0 }; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|    " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "    ";
			}
			else
			{
				m_display += "|          ";
			}
		}
		if (i > 0) m_display += std::string{'|', ' ', ' ', currChar, '\n'} + largeInnerLineBreak;
		else m_display += std::string{'|', ' ', ' ', currChar, '\n'} + largeLowerLineBreak;
		--currChar;
	}
	m_display += "\n     A          B          C          D          E          F          G          H";
}

void View::updateFlippedLargeCoordless()
{
	m_display = largeUpperLineBreak;
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|    " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "    ";
			}
			else
			{
				m_display += "|          ";
			}
		}
		if (i < 7) m_display += "|\n" + largeInnerLineBreak;
		else m_display += "|\n" + largeLowerLineBreak;
	}
}

void View::updateFlippedLargeCoordful()
{
	m_display = largeUpperLineBreak;
	char currChar{ '1' };
	for (int i{ 0 }; i < 8; ++i)
	{
		for (int j{ 7 }; j >= 0; --j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(Coordinates{ i, j });
			if (hasPiece)
			{
				m_display += "|    " + m_model->m_chessboard.getPiece(Coordinates{ i, j })->toString() + "    ";
			}
			else
			{
				m_display += "|          ";
			}
		}
		if (i < 7) m_display += std::string{'|', ' ', ' ', currChar, '\n'} + largeInnerLineBreak;
		else m_display += std::string{'|', ' ', ' ', currChar, '\n'} + largeLowerLineBreak;
		++currChar;
	}
	m_display += "\n     H          G          F          E          D          C          B          A";
}

void View::display() const
{
	// std::cout << "Displaying chessboard.\n";
	std::cout << m_display << '\n';
}

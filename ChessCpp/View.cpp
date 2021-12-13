#include "View.h"

#include <iostream>
#include <string>

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
	std::cout << "Updating chessboard.\n";
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
	if (m_model) showEngineEvaluation();
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
	std::cout << "Displaying chessboard.\n";
	std::cout << m_display << '\n';
}

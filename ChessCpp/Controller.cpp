#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Controller.h"

Controller::Controller(Model* const model, View* const view) : m_model{ model }, m_view{ view } {}

bool Controller::readInput() 
{
	// Todo: preprocess string (trimming)?

	std::string input;
	std::getline(std::cin >> std::ws , input);
	Controller::Command command{};
	std::vector<std::string> params{};

	for (auto& letter : input)
	{
		letter = toupper(letter);
	}

	if (input == "QUIT" || input == "Q")
	{
		command = Command::quit;
	}
	else if (input == "DISPLAY" || input == "D")
	{
		command = Command::display;
	}
	else if (input == "VALID" || input == "V")
	{
		command = Command::validMoves;
	}
	else if (isPlausibleMove(input))
	{
		command = Command::enterMove;
		for (auto& letter : input)
		{
			letter = toupper(letter);
		}
		params.push_back(input);
	}
	else if (input == "RESET")
	{
		command = Command::resetChessboard;
	}
	else if (input == "CAPTURED" || input == "CAP")
	{
		command = Command::showCaptured;
	}
	else if (input == "HISTORY" || input == "HIS")
	{
		command = Command::showMoveHistory;
	}
	else if (input == "SIZES" || input == "SS")
	{
		command = Command::setSize;
		params.push_back("small");
	}
	else if (input == "SIZEM" || input == "SM")
	{
		command = Command::setSize;
		params.push_back("medium");
	}
	else if (input == "SIZEL" || input == "SL")
	{
		command = Command::setSize;
		params.push_back("large");
	}
	else if (input == "TOGGLEF" || input == "TF")
	{
		command = Command::toggleFlippedStatus;
	}
	else if (input == "TOGGLEC" || input == "TC")
	{
		command = Command::toggleCoords;
	}
	else
	{
		command = Command::null;
	}

	switch (command)
	{
	case Controller::Command::quit:
		return quit();
	case Controller::Command::display:
		return display();
	case Controller::Command::validMoves:
		return showValidMoves();
	case Controller::Command::enterMove:
		return enterMove(params.at(0));
	case Controller::Command::resetChessboard:
		return resetChessboard();
	case Controller::Command::showCaptured:
		return showCapturedPieces();
	case Controller::Command::showMoveHistory:
		return showMoveHistory();
	case Controller::Command::setSize:
		return setSize(params.at(0));
	case Controller::Command::toggleFlippedStatus:
		return toggleFlippedStatus();
	case Controller::Command::toggleCoords:
		return toggleCoords();
	case Controller::Command::null:
		return null();
	default:
		return false;
	}
}

bool Controller::isPlausibleMove(std::string& move)
{
	if (move == "0-0" || move == "0-0-0") return true;
	if (move.size() == 5)
	{
		char lastChar{ move[4] };
		if (lastChar == 'Q' || lastChar == 'R' || lastChar == 'B' || lastChar == 'N') return true;
		Coordinates startSquare{static_cast<int>(move[1] - 49), static_cast<int>(move[0] - 65)};
		Coordinates endSquare{static_cast<int>(move[3] - 49), static_cast<int>(move[2] - 65)};
		return startSquare.isOnBoard() && endSquare.isOnBoard();
	}
	if (move.size() != 4) return false;
	Coordinates startSquare{static_cast<int>(move[1] - 49), static_cast<int>(move[0] - 65)};
	Coordinates endSquare{static_cast<int>(move[3] - 49), static_cast<int>(move[2] - 65)};
	return startSquare.isOnBoard() && endSquare.isOnBoard();
}

bool Controller::quit() const
{
	std::cout << "Quitting.\n";
	return true;
}

bool Controller::display() const
{
	m_view->display();
	return false;
}

bool Controller::showValidMoves() const
{
	m_view->showValidMoves();
	return false;
}

bool Controller::enterMove(std::string move) const
{
	m_model->enterMove(move);
	return false;
}

bool Controller::showCapturedPieces() const
{
	m_view->showCapturedPieces();
	return false;
}

bool Controller::showMoveHistory() const
{
	m_view->showMoveHistory();
	return false;
}

bool Controller::resetChessboard()
{
	m_view->resetChessboard();
	m_model->resetChessboard();
	return false;
}

bool Controller::setSize(std::string size) const
{
	std::cout << "Setting chessboard size to " << size << ".\n";
	View::Size viewSize{};
	if (size == "small")
	{
		viewSize = View::Size::small;
	}
	else if (size == "medium")
	{
		viewSize = View::Size::medium;
	}
	else if (size == "large")
	{
		viewSize = View::Size::large;
	}
	m_view->setSize(viewSize);
	return false;
}

bool Controller::toggleFlippedStatus() const
{
	std::cout << "Toggling flipped status.\n";
	m_view->toggleFlippedStatus();
	return false;
}

bool Controller::toggleCoords() const
{
	std::cout << "Toggling coordinates.\n";
	m_view->toggleCoords();
	return false;
}

bool Controller::null() const
{
	std::cout << "Enter valid input.\n";
	return false;
}

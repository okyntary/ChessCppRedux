#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Controller.h"

Controller::Controller(Model* const model, View* const view) : m_model{ model }, m_view{ view },
		m_gameStart{ false }, m_controllerPlayer{ ControllerPlayer::null } {}

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
	else if (input == "START")
	{
		command = Command::startGame;
	}
	else if (input == "UNDO" || input == "UN")
	{
		command = Command::undoLastMove;
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
	else if (input == "PLAYERN" || input == "PN")
	{
		command = Command::chooseColor;
		params.push_back("null");
	}
	else if (input == "PLAYERW" || input == "PW")
	{
		command = Command::chooseColor;
		params.push_back("white");
	}
	else if (input == "PLAYERB" || input == "PB")
	{
		command = Command::chooseColor;
		params.push_back("black");
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
	case Controller::Command::startGame:
		return startGame();
	case Controller::Command::enterMove:
		return enterMove(params.at(0));
	case Controller::Command::undoLastMove:
		return undoLastMove();
	case Controller::Command::resetChessboard:
		return resetChessboard();
	case Controller::Command::showCaptured:
		return showCapturedPieces();
	case Controller::Command::showMoveHistory:
		return showMoveHistory();
	case Controller::Command::chooseColor:
		return chooseColor(params.at(0));
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
	if (m_gameStart) m_view->showValidMoves();
	else m_view->showGameNotStarted();
	return false;
}

bool Controller::startGame()
{
	if (!m_gameStart)
	{
		if (m_controllerPlayer == ControllerPlayer::black)
		{
			m_model->runEngine();
		}
		m_gameStart = true;
	}
	return false;
}
bool Controller::enterMove(std::string move) const
{
	if (m_gameStart) m_model->enterMove(move);
	else m_view->showGameNotStarted();
	return false;
}

bool Controller::undoLastMove()
{
	if (m_gameStart)
	{
		m_model->undoLastMove();
		m_view->undoLastMove();
	}
	else m_view->showGameNotStarted();
	return false;
}

bool Controller::showCapturedPieces() const
{
	if (m_gameStart) m_view->showCapturedPieces();
	else m_view->showGameNotStarted();
	return false;
}

bool Controller::showMoveHistory() const
{
	if (m_gameStart) m_view->showMoveHistory();
	else m_view->showGameNotStarted();
	return false;
}

bool Controller::chooseColor(std::string color)
{
	ControllerPlayer controllerPlayer{};
	if (color == "null")
	{
		controllerPlayer = ControllerPlayer::null;
	}
	else if (color == "white")
	{
		controllerPlayer = ControllerPlayer::white;
	}
	else if (color == "black")
	{
		controllerPlayer = ControllerPlayer::black;
	}

	if (!m_gameStart)
	{
		m_controllerPlayer = controllerPlayer;
		switch (controllerPlayer)
		{
		case ControllerPlayer::null:
			m_view->showChooseColor(Player::null);
			break;
		case ControllerPlayer::white:
			m_view->showChooseColor(Player::white);
			break;
		case ControllerPlayer::black:
			m_view->showChooseColor(Player::black);
			break;
		default:
			break;
		}
	}
	else
	{
		m_view->showCannotChooseColor();
	}
	return false;
}

bool Controller::resetChessboard()
{
	m_gameStart = false;
	m_controllerPlayer = ControllerPlayer::null;
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

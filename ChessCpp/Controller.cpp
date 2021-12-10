#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Controller.h"

Controller::Controller(Model* const model, View* const view) : m_model{ model }, m_view{ view } {}

bool Controller::readInput() const
{
	// Todo: preprocess string (trimming)?

	std::string input;
	std::getline(std::cin >> std::ws , input);
	Controller::Command command{};
	std::vector<std::string> params{};

	if (input == "quit" || input == "q")
	{
		command = Command::quit;
	}
	else if (input == "display" || input == "d")
	{
		command = Command::display;
	}
	else if (input == "valid" || input == "v")
	{
		command = Command::validMoves;
	}
	else if (isPlausibleMove(input))
	{
		command = Command::enterMove;
		params.push_back({input[1], input[0]});
		params.push_back({input[3], input[2]});
	}
	else if (input == "sizes" || input == "ss")
	{
		command = Command::setSize;
		params.push_back("small");
	}
	else if (input == "sizem" || input == "sm")
	{
		command = Command::setSize;
		params.push_back("medium");
	}
	else if (input == "sizel" || input == "sl")
	{
		command = Command::setSize;
		params.push_back("large");
	}
	else if (input == "togglef" || input == "tf")
	{
		command = Command::toggleFlippedStatus;
	}
	else if (input == "togglec" || input == "tc")
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

bool Controller::isPlausibleMove(const std::string& move)
{
	if (move == "0-0" || move == "0-0-0") return true;
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

bool Controller::enterMove(const std::string& move) const
{
	m_model->enterMove(move);
	return false;
}

bool Controller::setSize(const std::string& size) const
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

#include <string>
#include <iostream>
#include <sstream>

#include "Controller.h"

Controller::Controller(Model* const model, View* const view) : m_model{ model }, m_view{ view } {}

bool Controller::readInput() const
{
	// Todo: preprocess string (trimming)

	std::string input;
	std::getline(std::cin >> std::ws , input);
	Controller::Command command{};

	if (input == "exit" || input == "e")
	{
		command = Command::exit;
	}
	else if (input == "display" || input == "d")
	{
		command = Command::display;
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
	case Controller::Command::exit:
		return exit();
	case Controller::Command::display:
		return display();
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

bool Controller::exit() const
{
	std::cout << "Exiting.\n";
	return true;
}

bool Controller::display() const
{
	m_view->display();
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

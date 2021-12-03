#include <string>
#include <iostream>
#include <sstream>

#include "Controller.h"

Controller::Controller(const Model* const model, const View* const view) : m_model{ model }, m_view{ view } {}

bool Controller::readInput() const
{
	// Todo: preprocess string (trim)

	std::string input;
	std::getline(std::cin >> std::ws , input);
	Controller::Command command;

	if (input == "exit")
	{
		command = Command::exit;
	}
	else
	{
		command = Command::null;
	}

	switch (command)
	{
	case Controller::Command::exit:
		return exit();
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

bool Controller::null() const
{
	std::cout << "Enter valid input.\n";
	return false;
}

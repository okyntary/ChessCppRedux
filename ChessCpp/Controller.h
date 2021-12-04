#pragma once

#include <iostream>

class Model;
#include "Model.h"

class View;
#include "View.h"

class Controller
{
	enum class Command
	{
		exit,
		display,
		toggleFlippedStatus,
		toggleCoords,
		null
	};

private:
	Model* const m_model{};
	View* const m_view{};

public:
	Controller(Model* const model, View* const view);
	bool readInput() const;

	bool exit() const;
	bool display() const;
	bool toggleFlippedStatus() const;
	bool toggleCoords() const;
	bool null() const;
};

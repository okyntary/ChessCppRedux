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
		null
	};

private:
	const Model* const m_model{};
	const View* const m_view{};

public:
	Controller(const Model* const model, const View* const view);
	bool readInput() const;

	bool exit() const;
	bool null() const;
};

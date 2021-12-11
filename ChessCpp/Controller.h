#pragma once

#include <iostream>
#include <string>

class Model;
#include "Model.h"

class View;
#include "View.h"

class Controller
{
	enum class Command
	{
		quit,
		display,
		validMoves,
		enterMove,
		resetChessboard,
		showCaptured,
		showMoveHistory,
		setSize,
		toggleFlippedStatus,
		toggleCoords,
		null
	};

private:
	Model* const m_model{};
	View* const m_view{};

public:
	Controller(Model* const model, View* const view);
	bool readInput();
	static bool isPlausibleMove(std::string& move);

	bool quit() const;
	bool display() const;
	bool showValidMoves() const;
	bool enterMove(std::string move) const;
	bool showCapturedPieces() const;
	bool showMoveHistory() const;
	bool resetChessboard();

	bool setSize(std::string size) const;
	bool toggleFlippedStatus() const;
	bool toggleCoords() const;

	bool null() const;
};

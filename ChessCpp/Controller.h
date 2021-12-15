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
		showHelpMessage,
		display,
		validMoves,
		startGame,
		enterMove,
		undoLastMove,
		resetChessboard,
		showCaptured,
		showMoveHistory,
		chooseColor,
		setSize,
		toggleFlippedStatus,
		toggleCoords,
		null
	};

	enum class ControllerPlayer
	{
		null,
		white,
		black
	};

private:
	Model* const m_model{};
	View* const m_view{};
	bool m_gameStart{ false };
	ControllerPlayer m_controllerPlayer{ ControllerPlayer::null };

public:
	Controller(Model* const model, View* const view);
	bool readInput();
	static bool isPlausibleMove(std::string& move);

	bool quit() const;
	bool showWelcome() const;
	bool showHelpMessage() const;
	bool display() const;
	bool showValidMoves() const;
	bool startGame();
	bool enterMove(std::string move) const;
	bool undoLastMove();
	bool showCapturedPieces() const;
	bool showMoveHistory() const;
	bool chooseColor(std::string color);
	bool resetChessboard();

	bool setSize(std::string size) const;
	bool toggleFlippedStatus() const;
	bool toggleCoords() const;

	bool null() const;
};

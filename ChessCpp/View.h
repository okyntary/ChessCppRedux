#pragma once

#include <iostream>
#include <string>

class Model;
#include "Model.h"

class View
{
public:
	enum class Size
	{
		small,
		medium,
		large
	};

private:
	// Link to Model
	// Circular dependency here, acceptable since scope of program is small
	const Model* const m_model{};

	// Contents to display
	std::string m_display{};
	// Settings for the content to display
	Size m_size{ Size::small };
	bool m_flippedStatus{ false };
	bool m_showCoords{ false };

	static const std::string mediumUpperLineBreak;
	static const std::string mediumInnerLineBreak;
	static const std::string mediumLowerLineBreak;

	static const std::string largeUpperLineBreak;
	static const std::string largeInnerLineBreak;
	static const std::string largeLowerLineBreak;

public:
	View(const Model * const model) : m_model{ model } {};


	// Move-related methods:
	// Show all currently valid moves
	void showValidMoves() const;
	void validMoveEntered() const;
	void invalidMoveEntered() const;

	// Utility methods
	void resetChessboard() const;
	void showCapturedPieces() const;
	void showMoveHistory() const;

	void isCheckmated() const;
	void isChecked() const;
	void isStalemated() const;

	// Set the values of the respective members of the class
	// Change View settings
	void setSize(Size size);
	void toggleFlippedStatus();
	void toggleCoords();

	// Update the contents to be displayed
	void update();

	// Update methods for Size::small
	void updateUnflippedSmallCoordless();
	void updateUnflippedSmallCoordful();
	void updateFlippedSmallCoordless();
	void updateFlippedSmallCoordful();

	// Update methods for Size::medium
	void updateUnflippedMediumCoordless();
	void updateUnflippedMediumCoordful();
	void updateFlippedMediumCoordless();
	void updateFlippedMediumCoordful();

	// Update methods for Size::large
	void updateUnflippedLargeCoordless();
	void updateUnflippedLargeCoordful();
	void updateFlippedLargeCoordless();
	void updateFlippedLargeCoordful();

	// Display the internal contents 
	void display() const;
};

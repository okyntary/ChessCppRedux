#pragma once

#include <iostream>
#include <string>

class Model;
#include "Model.h"

class View
{
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

public:
	View(const Model * const model) : m_model{ model } {};

	// Set the values of the respective members of the class
	void setSize(Size size);
	// Change the settings of View
	void toggleFlippedStatus();
	void toggleCoords();

	// Update the contents to be displayed
	void update();
	void updateUnflippedSmallCoordless();
	void updateUnflippedSmallCoordful();
	void updateFlippedSmallCoordless();
	void updateFlippedSmallCoordful();

	// Display the internal contents 
	void display() const;
};

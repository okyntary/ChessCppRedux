#pragma once

#include <iostream>
#include <string>

class Model;
#include "Model.h"

class View
{
	enum class Size
	{
		SIZE_SMALL,
		SIZE_MEDIUM,
		SIZE_LARGE
	};

private:
	// Link to Model
	// Circular dependency here, acceptable since scope of program is small
	const Model* const m_model{};

	// Contents to display
	std::string m_display{};
	// Settings for the content to display
	Size m_size{ Size::SIZE_SMALL };
	bool m_flippedStatus{};

public:
	View(const Model * const model) : m_model{ model } {};

	// Set the values of the respective members of the class
	void setSize(Size size);
	void setFlippedStatus(bool flippedStatus);

	// Update the contents to be displayed
	void update();

	// Display the internal contents 
	void display() const;
};

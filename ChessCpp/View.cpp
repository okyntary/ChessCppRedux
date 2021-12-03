#include "View.h"

#include <iostream>

void View::setSize(Size size)
{
	m_size = size;
}

void View::setFlippedStatus(bool flippedStatus)
{
	m_flippedStatus = flippedStatus;
}

void View::update()
{
	m_display = "Displaying chessboard!";
}

void View::display() const
{
	std::cout << m_display << '\n';
}

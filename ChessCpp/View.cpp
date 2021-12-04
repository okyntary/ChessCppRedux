#include "View.h"

#include <iostream>
#include <string>

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
	std::cout << "Updating chessboard!\n";
	if (!m_flippedStatus)
	{
		if (m_size == Size::small)
		{
			if (!m_showCoords) updateUnflippedSmallCoordless();
			else ;
		}
	}
	else
	{

	}
}

void View::updateUnflippedSmallCoordless()
{
	static std::string lineBreak = " __ __ __ __ __ __ __ __ \n";
	// std::cout << "Update unflipped small\n";
	m_display = "";
	for (int i = 7; i >= 0; --i)
	{
		m_display += lineBreak;
		for (int j = 0; j < 8; ++j)
		{
			bool hasPiece = m_model->m_chessboard.hasPiece(i, j);
			if (hasPiece)
			{
				m_display += "|" + m_model->m_chessboard.getPiece(i, j).toString();
			}
			else
			{
				m_display += "|  ";
			}
		}
		m_display += "|\n";
	}
	m_display += lineBreak;
}

void View::display() const
{
	std::cout << "Displaying chessboard!\n";
	std::cout << m_display << '\n';
}

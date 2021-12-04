#include "View.h"

#include <iostream>
#include <string>

void View::setSize(Size size)
{
	m_size = size;
}

void View::toggleFlippedStatus()
{
	m_flippedStatus = m_flippedStatus ^ 1;
	update();
}

void View::toggleCoords()
{
	m_showCoords = m_showCoords ^ 1;
	update();
}

void View::update()
{
	std::cout << "Updating chessboard.\n";
	if (m_size == Size::small)
	{
		if (!m_flippedStatus)
		{
			if (!m_showCoords) updateUnflippedSmallCoordless();
			else updateUnflippedSmallCoordful();
		}
		else
		{
			if (!m_showCoords) updateFlippedSmallCoordless();
			else updateFlippedSmallCoordful();
		}

	}
	else if (m_size == Size::medium)
	{

	}
	else if (m_size == Size::large)
	{

	}
}

void View::updateUnflippedSmallCoordless()
{
	m_display = "";
	for (int i = 7; i >= 0; --i)
	{
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
}

void View::updateUnflippedSmallCoordful()
{
	char currChar = '8';
	m_display = "";
	for (int i = 7; i >= 0; --i)
	{
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
		m_display += {'|', ' ', currChar, '\n'};
		--currChar;
	}
	m_display += " A  B  C  D  E  F  G  H";
}

void View::updateFlippedSmallCoordless()
{
	m_display = "";
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 7; j >= 0; --j)
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
}

void View::updateFlippedSmallCoordful()
{
	char currChar = '1';
	m_display = "";
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 7; j >= 0; --j)
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
		m_display += {'|', ' ', currChar, '\n'};
		++currChar;
	}
	m_display += " H  G  F  E  D  C  B  A";
}

void View::display() const
{
	std::cout << "Displaying chessboard.\n";
	std::cout << m_display << '\n';
}

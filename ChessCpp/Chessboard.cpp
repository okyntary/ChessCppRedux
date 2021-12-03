#include "Chessboard.h"

Square::Square(int row, int col) : m_row(row), m_col(col) {};

Chessboard::Chessboard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_chessboard[i][j] = Square(i, j);
		}
	}
}

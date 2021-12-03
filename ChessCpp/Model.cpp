#include "Model.h"

Model::Model()
{
	initialize();
}

void Model::setView(View* view)
{
	m_view = view;
}

void Model::updateView() const
{
	m_view->update();
}

void Model::initialize()
{
	for (int i = 0; i < 32; i++)
	{
		switch (i)
		{
		case 0:
			m_chessPieces[i] = WhiteKing();
			m_chessboard.setPiece(0, 4, &m_chessPieces[i]);
			break;
		case 15:
			m_chessPieces[i] = BlackKing();
			m_chessboard.setPiece(7, 4, &m_chessPieces[i]);
			break;
		default:
			break;
		}
	}
}

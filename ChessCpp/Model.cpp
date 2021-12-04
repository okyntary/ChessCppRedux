#include "Model.h"

Model::Model()
{
	initialize();
}

void Model::setView(View* view)
{
	m_view = view;
	updateView();
}

void Model::updateView() const
{
	m_view->update();
	m_view->display();
}

void Model::initialize()
{
	static WhiteKing wk1{};
	static BlackKing bk1{};

	for (int i = 0; i < 32; ++i)
	{
		switch (i)
		{
		case 0:
			m_chessPieces[i] = &wk1;
			m_chessboard.placePiece(0, 4, m_chessPieces[i]);
			break;
		case 16:
			m_chessPieces[i] = &bk1;
			m_chessboard.placePiece(7, 4, m_chessPieces[i]);
			break;
		default:
			m_chessPieces[i] = nullptr;
			break;
		}
	}
}

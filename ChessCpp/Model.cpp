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
	for (int i = 0; i <= 32; i++)
	{
		switch (i)
		{
		case 0:
			break;
		case 1:
			m_chessPieces[i] = WhiteKing();
			break;
		case 16:
			m_chessPieces[i] = BlackKing();
			break;
		default:
			break;
		}
	}
}

#include "Model.h"

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
	// Todo
}

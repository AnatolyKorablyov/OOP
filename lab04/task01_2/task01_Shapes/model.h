#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "ShapesView.h"

class CModel
{
public:
	std::vector<std::shared_ptr<IShape>> m_vectorShapes;
	std::vector<std::shared_ptr<IShapeView>> m_vectorShapesView;
};
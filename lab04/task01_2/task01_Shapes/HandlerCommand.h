#pragma once
#include "stdafx.h"
#include "model.h"
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "LineSegment.h"
#include "ShapesView.h"
#include "CircleView.h"
#include "RectangleView.h"
#include "LineView.h"
#include "TriangleView.h"

typedef std::vector<std::shared_ptr<IShape>> VectorShapes;
typedef std::vector<std::shared_ptr<IShapeView>> VectorShapesView;

bool AddPoint(std::stringstream & params, CModel & model);
bool AddLine(std::stringstream & params, CModel & model);
bool AddCircle(std::stringstream & params, CModel & model);
bool AddTriangle(std::stringstream & params, CModel & model);
bool AddRectangle(std::stringstream & params, CModel & model);

ColorInfo ParseColor(std::string & colorStr);
bool HandleCommand(std::string & commandStr, CModel & model);
#pragma once
#include "stdafx.h"
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
typedef std::vector<std::shared_ptr<CShapesView>> VectorShapesView;

bool AddPoint(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView);
bool AddLine(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView);
bool AddCircle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView);
bool AddTriangle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView);
bool AddRectangle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView);

ColorInfo ParseColor(std::string & colorStr);
bool HandleCommand(std::string & commandStr, VectorShapes & vectorShapes, VectorShapesView & vectorShapesView);
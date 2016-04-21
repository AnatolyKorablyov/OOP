#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "LineSegment.h"

ColorInfo parseColor(std::string & colorStr);
bool HandlerCommand(std::string & commandStr, std::vector<std::shared_ptr<IShape>> & vectorShapes);
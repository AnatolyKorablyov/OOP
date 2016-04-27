#include "stdafx.h"
#include "HandlerCommand.h"

ColorInfo ParseColor(std::string & colorStr)
{
	ColorInfo color;
	if (colorStr.length() == 6)
	{
		
		std::stringstream(colorStr.substr(0, 2)) >> std::hex >> color.r;
		std::stringstream(colorStr.substr(2, 2)) >> std::hex >> color.g;
		std::stringstream(colorStr.substr(4, 2)) >> std::hex >> color.b;
	}
	else if (colorStr.length() == 8)	
	{
		std::stringstream(colorStr.substr(0, 2)) >> std::hex >> color.r;
		std::stringstream(colorStr.substr(2, 2)) >> std::hex >> color.g;
		std::stringstream(colorStr.substr(4, 2)) >> std::hex >> color.b;
		std::stringstream(colorStr.substr(6, 2)) >> std::hex >> color.Transparent;
	}
	return color;
}

bool AddPoint(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView)
{
	float args[2];
	params >> args[0] >> args[1];
	vectorShapes.push_back(std::make_shared<CPoint>(args[0], args[1]));
	return true;
}

bool AddLine(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView)
{
	sf::Vector2f args[2];
	params >> args[0].x >> args[0].y;
	params >> args[1].x >> args[1].y;
	CPoint startDot(args[0].x, args[0].y);
	CPoint endDot(args[1].x, args[1].y);

	std::string colorStr;
	params >> colorStr;
	ColorInfo colorLine = ParseColor(colorStr);
	vectorShapes.push_back(std::make_shared<CLineSegment>(startDot, endDot, colorLine));
	vectorShapesView.push_back(std::make_shared<CLineView>(CLineSegment(startDot, endDot, colorLine)));
	return true;
}

bool AddCircle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView)
{
	sf::Vector2f posCenter;
	params >> posCenter.x >> posCenter.y;
	CPoint pointCenter(posCenter.x, posCenter.y);

	float radius;
	params >> radius;
	std::string colorStrLine;
	params >> colorStrLine;
	ColorInfo colorLine = ParseColor(colorStrLine);
	std::string colorStrFill;
	params >> colorStrFill;
	ColorInfo colorFill = ParseColor(colorStrFill);

	vectorShapes.push_back(std::make_shared<CCircle>(pointCenter, radius, colorLine, colorFill));
	vectorShapesView.push_back(std::make_shared<CCircleView>(CCircle(pointCenter, radius, colorLine, colorFill)));
	return true;
}


bool AddTriangle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView)
{
	sf::Vector2f posFirstVertex;
	params >> posFirstVertex.x >> posFirstVertex.y;
	CPoint firstDot(posFirstVertex.x, posFirstVertex.y);

	sf::Vector2f posSecondVertex;
	params >> posSecondVertex.x >> posSecondVertex.y;
	CPoint secondDot(posSecondVertex.x, posSecondVertex.y);

	sf::Vector2f posThirdVertex;
	params >> posThirdVertex.x >> posThirdVertex.y;
	CPoint thirdDot(posThirdVertex.x, posThirdVertex.y);

	std::string colorStrLine;
	params >> colorStrLine;
	ColorInfo colorLine = ParseColor(colorStrLine);
	std::string colorStrFill;
	params >> colorStrFill;
	ColorInfo colorFill = ParseColor(colorStrFill);

	vectorShapes.push_back(std::make_shared<CTriangle>(firstDot, secondDot, thirdDot, colorLine, colorFill));
	vectorShapesView.push_back(std::make_shared<CTriangleView>(CTriangle(firstDot, secondDot, thirdDot, colorLine, colorFill)));

	return true;
}

bool AddRectangle(std::stringstream & params, std::vector<std::shared_ptr<IShape>> & vectorShapes, VectorShapesView & vectorShapesView)
{
	sf::Vector2f posTopLeftPoint;
	params >> posTopLeftPoint.x >> posTopLeftPoint.y;
	CPoint dotTopLeft(posTopLeftPoint.x, posTopLeftPoint.y);
	float width;
	params >> width;
	float height;
	params >> height;

	std::string colorStrLine;
	params >> colorStrLine;
	ColorInfo colorLine = ParseColor(colorStrLine);
	std::string colorStrFill;
	params >> colorStrFill;
	ColorInfo colorFill = ParseColor(colorStrFill);

	vectorShapes.push_back(std::make_shared<CRectangle>(dotTopLeft, width, height, colorLine, colorFill));
	vectorShapesView.push_back(std::make_shared<CRectangleView>(CRectangle(dotTopLeft, width, height, colorLine, colorFill)));

	return true;
}

// extract funks from this
bool HandleCommand(std::string & commandStr, VectorShapes & vectorShapes, VectorShapesView & vectorShapesView)
{
	commandStr.erase(std::remove_if(commandStr.begin(), commandStr.end(), ispunct), commandStr.end());
	std::stringstream ss(commandStr);
	std::string shapeName;
	ss >> shapeName;

	if (shapeName == "point")
	{
		AddPoint(ss, vectorShapes, vectorShapesView);
	}
	else if (shapeName == "line")
	{
		AddLine(ss, vectorShapes, vectorShapesView);
	}
	else if (shapeName == "circle")
	{
		AddCircle(ss, vectorShapes, vectorShapesView);
	}
	else if (shapeName == "triangle")
	{
		AddTriangle(ss, vectorShapes, vectorShapesView);
	}
	else if (shapeName == "rectangle")
	{
		AddRectangle(ss, vectorShapes, vectorShapesView);
	}
	else
	{
		return false;
	}
	return true;
}
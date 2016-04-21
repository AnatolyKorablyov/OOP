#include "stdafx.h"
#include "HandlerCommand.h"

ColorInfo parseColor(std::string & colorStr)
{
	ColorInfo color;
	if (colorStr.length() == 7)
	{
		colorStr.erase(0, 1);
		std::stringstream(colorStr.substr(0, 2)) >> std::hex >> color.R;
		std::stringstream(colorStr.substr(2, 2)) >> std::hex >> color.G;
		std::stringstream(colorStr.substr(4, 2)) >> std::hex >> color.B;
	}
	if (colorStr.length() == 9)
	{
		colorStr.erase(0, 1);
		std::stringstream(colorStr.substr(0, 2)) >> std::hex >> color.R;
		std::stringstream(colorStr.substr(2, 2)) >> std::hex >> color.G;
		std::stringstream(colorStr.substr(4, 2)) >> std::hex >> color.B;
		std::stringstream(colorStr.substr(4, 2)) >> std::hex >> color.Transparent;
	}
	return color;
}

bool HandlerCommand(std::string & commandStr, std::vector<std::shared_ptr<IShape>> & vectorShapes)
{
	commandStr.erase(std::remove_if(commandStr.begin(), commandStr.end(), ispunct), commandStr.end());
	std::stringstream ss(commandStr);
	std::string shapeName;
	ss >> shapeName;

	if (shapeName == "point")
	{
		float args[2];
		ss >> args[0] >> args[1];
		vectorShapes.push_back(std::make_shared<CPoint>(args[0], args[1]));
	}
	else if (shapeName == "line")
	{
		sf::Vector2f args[2];
		ss >> args[0].x >> args[0].y;
		ss >> args[1].x >> args[1].y;
		std::string colorStr;
		ss >> colorStr;
		ColorInfo colorLine = parseColor(colorStr);
		vectorShapes.push_back(std::make_shared<CLineSegment>(args[0], args[1], colorLine));
	}
	else if (shapeName == "circle")
	{
		sf::Vector2f posCenter;
		ss >> posCenter.x >> posCenter.y;
		float radius;
		ss >> radius;
		std::string colorStrLine;
		ss >> colorStrLine;
		ColorInfo colorLine = parseColor(colorStrLine);
		std::string colorStrFill;
		ss >> colorStrFill;
		ColorInfo colorFill = parseColor(colorStrFill);

		vectorShapes.push_back(std::make_shared<CCircle>(posCenter, radius, colorLine, colorFill));
	}
	else if (shapeName == "triangle")
	{
		sf::Vector2f posFirstVertex;
		ss >> posFirstVertex.x >> posFirstVertex.y;
		sf::Vector2f posSecondVertex;
		ss >> posSecondVertex.x >> posSecondVertex.y;
		sf::Vector2f posThirdVertex;
		ss >> posThirdVertex.x >> posThirdVertex.y;

		std::string colorStrLine;
		ss >> colorStrLine;
		ColorInfo colorLine = parseColor(colorStrLine);
		std::string colorStrFill;
		ss >> colorStrFill;
		ColorInfo colorFill = parseColor(colorStrFill);

		vectorShapes.push_back(std::make_shared<CTriangle>(posFirstVertex, posSecondVertex, posThirdVertex, colorLine, colorFill));
	}
	else if (shapeName == "rectangle")
	{
		sf::Vector2f posTopLeftPoint;
		ss >> posTopLeftPoint.x >> posTopLeftPoint.y;
		float width;
		ss >> width;
		float height;
		ss >> height;

		std::string colorStrLine;
		ss >> colorStrLine;
		ColorInfo colorLine = parseColor(colorStrLine);
		std::string colorStrFill;
		ss >> colorStrFill;
		ColorInfo colorFill = parseColor(colorStrFill);

		vectorShapes.push_back(std::make_shared<CRectangle>(posTopLeftPoint, width, height, colorLine, colorFill));
	}
	else
	{
		return false;
	}
	return true;
}
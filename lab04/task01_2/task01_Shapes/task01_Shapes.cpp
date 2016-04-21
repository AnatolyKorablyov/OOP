// task01_Shapes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Point.h"

int main()
{
	std::vector<std::shared_ptr<IShape>> shapesVector;
	
	shapesVector.push_back(std::make_shared<CRectangle>());
	shapesVector.push_back(std::make_shared<CCircle>());
	shapesVector.push_back(std::make_shared<CPoint>());
	//shapesVector.push_back(std::make_shared<CTriangle>());

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
									 
		for (auto i : shapesVector)
		{
			std::cout << i->ToString() << std::endl;
			window.draw(i->shape);
		}
		window.display();
	}
    return 0;
}


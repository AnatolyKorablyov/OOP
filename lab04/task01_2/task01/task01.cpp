// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"

int main()
{
	std::vector<sf::ConvexShape> ShapeVertex;
	ShapeVertex.push_back(CRectangle().shape);
	sf::RenderWindow window(sf::VideoMode(800, 480), "task1_2");
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
		for (auto i : ShapeVertex)
		{
			 std::e
		}

		window.display();
	}
    return 0;
}


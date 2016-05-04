#include "stdafx.h"
#include "HandlerCommand.h"

void printBySort(std::vector<std::shared_ptr<IShape>> & vectorShapes, const std::string & outFileName)
{
	std::ofstream outFile(outFileName);

	outFile << "Sort by Square" << std::endl;
	std::sort(vectorShapes.begin(), vectorShapes.end(), [](const std::shared_ptr<IShape> & first, const std::shared_ptr<IShape> & second)
	{
		return first->GetArea() < second->GetArea();
	});
	for (auto i : vectorShapes)
	{
		outFile << i->ToString() << std::endl;
	}

	outFile << std::endl << "Sort by Perimeter" << std::endl;
	std::sort(vectorShapes.begin(), vectorShapes.end(), [](const std::shared_ptr<IShape> & first, const std::shared_ptr<IShape> & second)
	{
		return first->GetPerimeter() < second->GetPerimeter();
	});
	for (auto i : vectorShapes)
	{
		outFile << i->ToString() << std::endl;
	}
}


void DrawShapes(const std::vector<std::shared_ptr<IShapeView>> & vectorShapesView)
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "ShapesView");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		for (auto &i : vectorShapesView)
		{
			window.draw(*i);
		}
		window.display();
	}
}
bool ReadFromFile(const std::string & inputFileName, const std::string & outFileName)
{
	std::ifstream inputFile(inputFileName);

	std::string string;
	CModel m_model;
	while (std::getline(inputFile, string))
	{
		if (!HandleCommand(string, m_model))
		{
			std::cout << "Unknown command: " << string << std::endl;
			return false;
		}
	}
	DrawShapes(m_model.m_vectorShapesView);
	printBySort(m_model.m_vectorShapes, outFileName);
	return true;
}


int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ReadFromFile(argv[1], argv[2]);
	}
	return 0;
}
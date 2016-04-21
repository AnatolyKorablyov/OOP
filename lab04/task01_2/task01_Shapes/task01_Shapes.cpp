#include "stdafx.h"
#include "HandlerCommand.h"

void printBySort(std::vector<std::shared_ptr<IShape>> & vectorShapes, const std::string & outFileName)
{
	std::ofstream outFile(outFileName);
	outFile << "Sort by Square" << std::endl;
	std::sort(vectorShapes.begin(), vectorShapes.end(), [](const std::shared_ptr<IShape> & first, const std::shared_ptr<IShape> & second) 
	{
		return first->GetShapeArea() < second->GetShapeArea();
	});
	for (auto i : vectorShapes)
	{
		outFile << i->ToString() << std::endl;
	}

	outFile << std::endl << "Sort by Perimetr" << std::endl;
	std::sort(vectorShapes.begin(), vectorShapes.end(), [](const std::shared_ptr<IShape> & first, const std::shared_ptr<IShape> & second)
	{
		return first->GetShapePerimetr() < second->GetShapePerimetr();
	});
	for (auto i : vectorShapes)
	{
		outFile << i->ToString() << std::endl;
	}
}

bool ReadFromFile(const std::string & inputFileName, const std::string & outFileName)
{
	std::ifstream inputFile(inputFileName);

	std::string string;
	std::vector<std::shared_ptr<IShape>> vectorShapes;
	while (std::getline(inputFile, string))
	{
		if (!HandlerCommand(string, vectorShapes))
		{
			std::cout << "Unknown command: " << string << std::endl;
			return false;
		}
	}
	printBySort(vectorShapes, outFileName);
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
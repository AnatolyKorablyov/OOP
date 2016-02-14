#include <iostream>
#include <fstream>
#include <string>


bool CheckValue(std::string string, int & num)
{
	int len = string.length();
	while ((string[num] >= '0' && string[num] <= '9') || string[num] == '.' && num < len) {
		num++;
	}
	return (num <= len || string[num] == '\n' || string[num] == ' ');

}

void ReadFile(const std::string & nameFile, float (&matrix)[3][3]) 
{
	std::ifstream inpFile(nameFile);
	if (!inpFile.is_open())
	{
		std::cout << "Error open file\n";
		system("pause");
		exit(1);
	}
	int countX = 0;
	while (!inpFile.eof())
	{
		int countY = 0;
		std::string string;
		std::getline(inpFile, string);
		int num = 0;
		int m_start = 0;

		for (int i = 0; i < 3; i++)
		{
			if (CheckValue(string, num))
			{
				matrix[countX][i] = float(atof(string.substr(m_start, num).c_str()));
				num++;
				m_start = num;
			}
			else
			{
				std::cout << "incorrect matrix";
			}
		}
		countX++;
	}
}


float CalcDeterminateThirdOrder(const float(&matrix)[3][3])
{
	float determinate = 0;
	determinate = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) +
		matrix[1][0] * (matrix[2][1] * matrix[0][2] - matrix[0][1] * matrix[2][2]) +
		matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);
	return determinate;
}

float CalcDeterminateSecondOrder(const float(&matrix)[2][2])
{
	float determinate = 0;
	determinate = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return determinate;
}

float CalcMinor(const float(&matrix)[3][3], int str, int column)
{
	float minor[2][2];
	int numStr = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i != str)
		{	
			int numColumn = 0;
			for (int j = 0; j < 3; j++)
			{
				if (j != column)
				{
					minor[numStr][numColumn] = matrix[i][j];
					numColumn += 1;
				}
			}
			numStr += 1;
		}
	}
	return CalcDeterminateSecondOrder(minor);
}


void CalcTransposeMatrixThirdOrder(float(&matrix)[3][3])
{
	float trasposeMatrix[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			trasposeMatrix[j][i] = matrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = trasposeMatrix[i][j];
		}
	}
}

void CalculateMatrixMinors(const float(&matrix)[3][3], float (&matrixMinors)[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixMinors[i][j] = CalcMinor(matrix, i, j) * int(pow((-1), i + j));
		}
	}
	CalcTransposeMatrixThirdOrder(matrixMinors);
}

void MultiplyNumberAndMatrix(float number, float (&matrix)[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] *= number;
		}
	}
}

void Application(float (&matrix)[3][3])
{

	float determinate = CalcDeterminateThirdOrder(matrix);
	if (determinate != 0)
	{
		float matrixMinor[3][3];
		CalculateMatrixMinors(matrix, matrixMinor);
		MultiplyNumberAndMatrix(1 / determinate, matrixMinor);
		std::cout.precision(3);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << matrixMinor[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "Inverse matrix is not possible. Determinant = 0";
	}
}

int main(int argc, char * argv[])
{
	if (argc == 2)
	{
		float matrix[3][3];
		ReadFile(argv[1], matrix);
		Application(matrix);
	}
	else
	{
		std::cout << "Example: task3.exe \"file.txt\"";
	}
	return 0;
}
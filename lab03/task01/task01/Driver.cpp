#include "stdafx.h"
#include "Driver.h"


void PrintInfoAboutCar(const InfoAboutCar & indicators)
{
	std::cout << "���������: " << (indicators.conditionEngine ? "�������" : "��������") << std::endl;
	std::cout << "��������: " << indicators.speed << std::endl;
	std::cout << "��������: " << indicators.gear << std::endl;
	std::cout << "�����������: " << DIRECTION_NAME.find(indicators.dir)->second << std::endl;
}

void PrintResultEngineOnCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "��������� �������" << std::endl;
		break;
	case 1:
		std::cout << "��������� ��� �������" << std::endl;
		break;
	case 2:
		std::cout << "��������� �� �������, �.�. �������� ��������" << std::endl;
		break;
	}
}

void PrintResultEngineOffCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "��������� ��������" << std::endl;
		break;
	case 1:
		std::cout << "��������� ��� ��������" << std::endl;
		break;
	case 2:
		std::cout << "��������� �� ��������, �.�. �������� ��������" << std::endl;
		break;
	case 3:
		std::cout << "��������� �� ��������, �.�. �������� �� �������" << std::endl;
		break;
	}
}

void PrintResultSetGearCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "�������� �����������" << std::endl;
		break;
	case 1:
		std::cout << "�������� �� ����������� �� ������, �.�. ������ ���� ������" << std::endl;
		break;
	case 2:
		std::cout << "�������� �� ����������� �� �������������, �.�. ������ ���� �����" << std::endl;
		break;
	case 3:
		std::cout << "�������� �� �����������, �.�. ��� ����� ��������" << std::endl;
		break;
	case 4:
		std::cout << "�������� �� �����������, �.�. �������� �� ������������ ��������� ����� ��������" << std::endl;
		break;
	}
}

void PrintResultSetSpeedCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "�������� �����������" << std::endl;
		break;
	case 1:
		std::cout << "�������� �� ������� ��������, �.�. ��������� ��������" << std::endl;
		break;
	case 2:
		std::cout << "�������� �� ������� ��������, �.�. ����������� ����������� ��������" << std::endl;
		break;
	case 3:
		std::cout << "�������� �� ������� ��������, �.�. �������� �� ������������ ��������� ������������� ��������" << std::endl;
		break;
	}
}

void CarDriver()
{
	CCar bmwX5;
	std::string mainStr;
	std::getline(std::cin, mainStr);

	size_t posLastEnd = 0;
	size_t posStart = 0;

	std::string strValue;
	std::string commandControl;
	while (mainStr != "...")
	{
		posLastEnd = 0;
		posStart = mainStr.find(" ");
		commandControl.clear();
		commandControl.append(mainStr, posLastEnd, posStart - posLastEnd);
		posLastEnd = mainStr.find("<");
		posStart = mainStr.find(">");
		strValue.clear();
		if (posStart != std::string::npos && posLastEnd != std::string::npos) 
		{
			strValue.append(mainStr, posLastEnd + 1, posStart - posLastEnd);
		}

		if (commandControl == "Info")
		{
			PrintInfoAboutCar(bmwX5.GetInfo());
		}
		else if (commandControl == "EngineOn")
		{
			PrintResultEngineOnCommand(bmwX5.TurnOnEngine());
		}
		else if (commandControl == "EngineOff")
		{
			PrintResultEngineOffCommand(bmwX5.TurnOffEngine());
		}
		else if (commandControl == "SetGear")
		{
			PrintResultSetGearCommand(bmwX5.SetGear(std::atoi(strValue.c_str())));
		}
		else if (commandControl == "SetSpeed")
		{
			PrintResultSetSpeedCommand(bmwX5.SetSpeed(std::atoi(strValue.c_str())));
		}

		std::cout << std::endl;
		std::getline(std::cin, mainStr);
	}
}
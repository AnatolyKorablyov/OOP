#include "stdafx.h"
#include "Driver.h"


void Tazovod()
{
	CCar Taz;
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

		if (posStart != std::string::npos) 
		{
			strValue.append(mainStr, posLastEnd, posStart - posLastEnd);
		}

		if (commandControl == "Info")
		{
			InfoAboutCar indicators = Taz.GetInfo();
			std::cout << "���������: " << (indicators.conditionEngine ? "�������" : "��������") << std::endl;
			std::cout << "��������: " << indicators.speed << std::endl;
			std::cout << "��������: " << indicators.gear << std::endl;
			std::cout << "�����������: " << DIRECTION_NAME.find(indicators.dir)->second << std::endl;
		}
		else if (commandControl == "EngineOn")
		{
			if (Taz.TurnOnEngine())
			{
				std::cout << "��������� �������" << std::endl;
			}
			else
			{
				std::cout << "��������� �� ������� ��������" << std::endl;
			}
		}
		else if (commandControl == "EngineOff")
		{
			if (Taz.TurnOffEngine())
			{
				std::cout << "��������� ��������" << std::endl;
			}
			else
			{
				std::cout << "��������� �� ������� ���������" << std::endl;
			}
		}
		else if (commandControl == "SetGear")
		{
			if (Taz.SetGear(std::atoi(strValue.c_str())))
			{
				std::cout << "�������� ��������" << std::endl;
			}
			else
			{
				std::cout << "�������� �� ������� ��������" << std::endl;
			}
		}
		else if (commandControl == "SetSpeed")
		{
			if (Taz.SetSpeed(std::atoi(strValue.c_str())))
			{
				std::cout << "�������� �����������" << std::endl;
			}
			else
			{
				std::cout << "�������� �� ������� ����������" << std::endl;
			}
		}

		std::cout << std::endl;
		std::getline(std::cin, mainStr);
	}
}
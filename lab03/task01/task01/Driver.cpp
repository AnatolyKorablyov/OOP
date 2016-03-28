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
			std::cout << "Двигатель: " << (indicators.conditionEngine ? "запущен" : "выключен") << std::endl;
			std::cout << "Скорость: " << indicators.speed << std::endl;
			std::cout << "Передача: " << indicators.gear << std::endl;
			std::cout << "Направление: " << DIRECTION_NAME.find(indicators.dir)->second << std::endl;
		}
		else if (commandControl == "EngineOn")
		{
			if (Taz.TurnOnEngine())
			{
				std::cout << "Двигатель включен" << std::endl;
			}
			else
			{
				std::cout << "Двигатель не удалось включить" << std::endl;
			}
		}
		else if (commandControl == "EngineOff")
		{
			if (Taz.TurnOffEngine())
			{
				std::cout << "Двигатель выключен" << std::endl;
			}
			else
			{
				std::cout << "Двигатель не удалось выключить" << std::endl;
			}
		}
		else if (commandControl == "SetGear")
		{
			if (Taz.SetGear(std::atoi(strValue.c_str())))
			{
				std::cout << "Передача включена" << std::endl;
			}
			else
			{
				std::cout << "Передача не удалось включить" << std::endl;
			}
		}
		else if (commandControl == "SetSpeed")
		{
			if (Taz.SetSpeed(std::atoi(strValue.c_str())))
			{
				std::cout << "Скорость установлена" << std::endl;
			}
			else
			{
				std::cout << "Скорость не удалось установить" << std::endl;
			}
		}

		std::cout << std::endl;
		std::getline(std::cin, mainStr);
	}
}
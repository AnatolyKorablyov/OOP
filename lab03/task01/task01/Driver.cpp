#include "stdafx.h"
#include "Driver.h"

void PrintHelp()
{
	std::cout << "Info - показать состояние машины" << std::endl;
	std::cout << "EngineOn - включить двигатель" << std::endl;
	std::cout << "EngineOff - выключить двигатель" << std::endl;
	std::cout << "SetGear <value> - задать передачу value" << std::endl;
	std::cout << "SetSpeed <value> - задать скорость value" << std::endl;
}

void PrintInfoAboutCar(const InfoAboutCar & indicators)
{
	std::cout << "Двигатель: " << (indicators.conditionEngine ? "запущен" : "выключен") << std::endl;
	std::cout << "Скорость: " << indicators.speed << std::endl;
	std::cout << "Передача: " << indicators.gear << std::endl;
	std::cout << "Направление: " << DIRECTION_NAME.find(indicators.dir)->second << std::endl;
}

void PrintResultEngineOnCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "Двигатель включен" << std::endl;
		break;
	case 1:
		std::cout << "Двигатель уже включен" << std::endl;
		break;
	case 2:
		std::cout << "Двигатель не включен, т.к. включена передача" << std::endl;
		break;
	}
}

void PrintResultEngineOffCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "Двигатель выключен" << std::endl;
		break;
	case 1:
		std::cout << "Двигатель уже выключен" << std::endl;
		break;
	case 2:
		std::cout << "Двигатель не выключен, т.к. включена передача" << std::endl;
		break;
	case 3:
		std::cout << "Двигатель не выключен, т.к. скорость не нулевая" << std::endl;
		break;
	}
}

void PrintResultSetGearCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "Передача переключена" << std::endl;
		break;
	case 1:
		std::cout << "Передача не переключена на заднюю, т.к. машина едет вперед" << std::endl;
		break;
	case 2:
		std::cout << "Передача не переключена на положительную, т.к. машина едет назад" << std::endl;
		break;
	case 3:
		std::cout << "Передача не переключена, т.к. нет такой передачи" << std::endl;
		break;
	case 4:
		std::cout << "Передача не переключена, т.к. скорость не соответсвует диапазону новой передачи" << std::endl;
		break;
	}
}

void PrintResultSetSpeedCommand(const int & value)
{
	switch (value)
	{
	case 0:
		std::cout << "Скорость установлена" << std::endl;
		break;
	case 1:
		std::cout << "Скорость не удалось изменить, т.к. двигатель выключен" << std::endl;
		break;
	case 2:
		std::cout << "Скорость не удалось повысить, т.к. установлена нейтральная передача" << std::endl;
		break;
	case 3:
		std::cout << "Скорость не удалось изменить, т.к. скорость не соответсвует диапазону установленной передачи" << std::endl;
		break;
	}
}

void HandlerCommands(const std::string & commandControl, const std::string & strValue, CCar & car)
{
	if (commandControl == "Info")
	{
		PrintInfoAboutCar(car.GetInfo());
	}
	else if (commandControl == "EngineOn")
	{
		PrintResultEngineOnCommand(car.TurnOnEngine());
	}
	else if (commandControl == "EngineOff")
	{
		PrintResultEngineOffCommand(car.TurnOffEngine());
	}
	else if (commandControl == "SetGear")
	{
		PrintResultSetGearCommand(car.SetGear(std::atoi(strValue.c_str())));
	}
	else if (commandControl == "SetSpeed")
	{
		PrintResultSetSpeedCommand(car.SetSpeed(std::atoi(strValue.c_str())));
	}
	else
	{
		PrintHelp();
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

		HandlerCommands(commandControl, strValue, bmwX5);

		std::cout << std::endl;
		std::getline(std::cin, mainStr);
	}
}
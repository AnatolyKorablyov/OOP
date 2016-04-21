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

void PrintResultEngineOnCommand(const ReturnCodeEngineOn & wasError)
{
	switch (wasError)
	{
	case ReturnCodeEngineOn::EngineOn:
		std::cout << "Двигатель включен" << std::endl;
		break;
	case ReturnCodeEngineOn::EngineWasOn:
		std::cout << "Двигатель уже включен" << std::endl;
		break;
	case ReturnCodeEngineOn::EngineNotOnWithGear:
		std::cout << "Двигатель не включен, т.к. включена передача" << std::endl;
		break;
	}
}

void PrintResultEngineOffCommand(const ReturnCodeEngineOff & wasError)
{
	switch (wasError)
	{
	case ReturnCodeEngineOff::EngineOff:
		std::cout << "Двигатель выключен" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineWasOff:
		std::cout << "Двигатель уже выключен" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineNotOffWithGear:
		std::cout << "Двигатель не выключен, т.к. включена передача" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineNotOffWithSpeed:
		std::cout << "Двигатель не выключен, т.к. скорость не нулевая" << std::endl;
		break;
	}
}

void PrintResultSetGearCommand(const ReturnCodeSetGear & wasError)
{
	switch (wasError)
	{
	case ReturnCodeSetGear::GearOn:
		std::cout << "Передача переключена" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnReverse:
		std::cout << "Передача не переключена на заднюю, т.к. машина едет вперед" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnWithReverseSpeed:
		std::cout << "Передача не переключена на положительную, т.к. машина едет назад" << std::endl;
		break;
	case ReturnCodeSetGear::NoGear:
		std::cout << "Передача не переключена, т.к. нет такой передачи" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnWithSpeed:
		std::cout << "Передача не переключена, т.к. скорость не соответсвует диапазону новой передачи" << std::endl;
		break;
	}
}

void PrintResultSetSpeedCommand(const ReturnCodeSetSpeed & wasError)
{
	switch (wasError)
	{
	case ReturnCodeSetSpeed::SpeedOn:
		std::cout << "Скорость установлена" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotWithEngine:
		std::cout << "Скорость не удалось изменить, т.к. двигатель выключен" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotAddWithNeutralGear:
		std::cout << "Скорость не удалось повысить, т.к. установлена нейтральная передача" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotRange:
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
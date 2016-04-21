#include "stdafx.h"
#include "Driver.h"

void PrintHelp()
{
	std::cout << "Info - �������� ��������� ������" << std::endl;
	std::cout << "EngineOn - �������� ���������" << std::endl;
	std::cout << "EngineOff - ��������� ���������" << std::endl;
	std::cout << "SetGear <value> - ������ �������� value" << std::endl;
	std::cout << "SetSpeed <value> - ������ �������� value" << std::endl;
}

void PrintInfoAboutCar(const InfoAboutCar & indicators)
{
	std::cout << "���������: " << (indicators.conditionEngine ? "�������" : "��������") << std::endl;
	std::cout << "��������: " << indicators.speed << std::endl;
	std::cout << "��������: " << indicators.gear << std::endl;
	std::cout << "�����������: " << DIRECTION_NAME.find(indicators.dir)->second << std::endl;
}

void PrintResultEngineOnCommand(const ReturnCodeEngineOn & wasError)
{
	switch (wasError)
	{
	case ReturnCodeEngineOn::EngineOn:
		std::cout << "��������� �������" << std::endl;
		break;
	case ReturnCodeEngineOn::EngineWasOn:
		std::cout << "��������� ��� �������" << std::endl;
		break;
	case ReturnCodeEngineOn::EngineNotOnWithGear:
		std::cout << "��������� �� �������, �.�. �������� ��������" << std::endl;
		break;
	}
}

void PrintResultEngineOffCommand(const ReturnCodeEngineOff & wasError)
{
	switch (wasError)
	{
	case ReturnCodeEngineOff::EngineOff:
		std::cout << "��������� ��������" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineWasOff:
		std::cout << "��������� ��� ��������" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineNotOffWithGear:
		std::cout << "��������� �� ��������, �.�. �������� ��������" << std::endl;
		break;
	case ReturnCodeEngineOff::EngineNotOffWithSpeed:
		std::cout << "��������� �� ��������, �.�. �������� �� �������" << std::endl;
		break;
	}
}

void PrintResultSetGearCommand(const ReturnCodeSetGear & wasError)
{
	switch (wasError)
	{
	case ReturnCodeSetGear::GearOn:
		std::cout << "�������� �����������" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnReverse:
		std::cout << "�������� �� ����������� �� ������, �.�. ������ ���� ������" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnWithReverseSpeed:
		std::cout << "�������� �� ����������� �� �������������, �.�. ������ ���� �����" << std::endl;
		break;
	case ReturnCodeSetGear::NoGear:
		std::cout << "�������� �� �����������, �.�. ��� ����� ��������" << std::endl;
		break;
	case ReturnCodeSetGear::GearNotOnWithSpeed:
		std::cout << "�������� �� �����������, �.�. �������� �� ������������ ��������� ����� ��������" << std::endl;
		break;
	}
}

void PrintResultSetSpeedCommand(const ReturnCodeSetSpeed & wasError)
{
	switch (wasError)
	{
	case ReturnCodeSetSpeed::SpeedOn:
		std::cout << "�������� �����������" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotWithEngine:
		std::cout << "�������� �� ������� ��������, �.�. ��������� ��������" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotAddWithNeutralGear:
		std::cout << "�������� �� ������� ��������, �.�. ����������� ����������� ��������" << std::endl;
		break;
	case ReturnCodeSetSpeed::SpeedNotRange:
		std::cout << "�������� �� ������� ��������, �.�. �������� �� ������������ ��������� ������������� ��������" << std::endl;
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
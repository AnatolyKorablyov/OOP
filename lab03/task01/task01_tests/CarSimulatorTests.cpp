#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task01\Car.h"

BOOST_AUTO_TEST_SUITE(Go_Ride)
BOOST_AUTO_TEST_CASE(EngineOnFailed)
{
	CCar Taz;
	Taz.SetGear(1);
	BOOST_CHECK(Taz.TurnOnEngine() != 0);
}

BOOST_AUTO_TEST_CASE(EngineOffFailed)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(1);
	BOOST_CHECK(Taz.TurnOffEngine() != 0);
}

BOOST_AUTO_TEST_CASE(SetGear_HigherSpeedRange_Failed)
{
	CCar Taz;
	Taz.TurnOnEngine();
	BOOST_CHECK(Taz.SetGear(2) != 0);
}

BOOST_AUTO_TEST_CASE(SetGearComplete)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(1);
	Taz.SetSpeed(25);
	BOOST_CHECK(Taz.SetGear(2) == 0);
}

BOOST_AUTO_TEST_CASE(SetGear_ReverseGear_Failed)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(1);
	Taz.SetSpeed(10);
	BOOST_CHECK(Taz.SetGear(-1) != 0);
}

BOOST_AUTO_TEST_CASE(EngineOff_Complete)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(0);
	Taz.SetSpeed(0);

	BOOST_CHECK(Taz.TurnOffEngine() == 0);
}

BOOST_AUTO_TEST_CASE(SetMaxSpeed)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(1);
	Taz.SetSpeed(30);
	Taz.SetGear(3);
	Taz.SetSpeed(50);
	Taz.SetGear(5);
	Taz.SetSpeed(150);

	BOOST_CHECK(Taz.SetSpeed(151) != 0 && Taz.GetInfo().speed == 150);
}

BOOST_AUTO_TEST_CASE(SetMaxGear)
{
	CCar Taz;
	Taz.TurnOnEngine();
	Taz.SetGear(1);
	Taz.SetSpeed(30);
	Taz.SetGear(3);
	Taz.SetSpeed(50);
	Taz.SetGear(5);
	Taz.SetSpeed(150);

	BOOST_CHECK(Taz.SetGear(6) != 0 && Taz.GetInfo().gear == 5);
}

BOOST_AUTO_TEST_SUITE_END()
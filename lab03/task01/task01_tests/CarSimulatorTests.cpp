#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task01\Car.h"
#include <boost/test/unit_test_suite.hpp>


struct InitCar
{
	CCar Lancer;
};

BOOST_FIXTURE_TEST_SUITE(carInitialization, InitCar)

	BOOST_AUTO_TEST_CASE(EngineOn_complite)
	{
		Lancer.TurnOnEngine();
		BOOST_CHECK(Lancer.GetInfo().conditionEngine);
	}
	BOOST_AUTO_TEST_CASE(EngineOn_failed_wasOn)
	{
		Lancer.TurnOnEngine();
		BOOST_CHECK(Lancer.TurnOnEngine() == ReturnCodeEngineOn::EngineWasOn);
	}
	BOOST_AUTO_TEST_CASE(EngineOn_failed_withGearOn)
	{
		Lancer.SetGear(1);
		BOOST_CHECK(Lancer.TurnOnEngine() == ReturnCodeEngineOn::EngineNotOnWithGear);
		BOOST_CHECK(!Lancer.GetInfo().conditionEngine);
	}

	BOOST_AUTO_TEST_CASE(SetGear_complite_with_EngineOff)
	{
		BOOST_CHECK(Lancer.GetInfo().gear == 0);
		Lancer.SetGear(1);
		BOOST_CHECK(Lancer.GetInfo().gear == 1);
		Lancer.SetGear(-1);
		BOOST_CHECK(Lancer.GetInfo().gear == -1);
	}

	BOOST_AUTO_TEST_CASE(SetGear_failed_with_EngineOff_and_speed_not_range)
	{
		BOOST_CHECK(Lancer.GetInfo().gear == 0);
		BOOST_CHECK(Lancer.SetGear(2) == ReturnCodeSetGear::GearNotOnWithSpeed);
		BOOST_CHECK(Lancer.GetInfo().gear == 0);
	}

	BOOST_AUTO_TEST_CASE(SetSpeed_with_EngineOff)
	{
		BOOST_CHECK(Lancer.SetSpeed(10) == ReturnCodeSetSpeed::SpeedNotWithEngine);
		BOOST_CHECK(Lancer.GetInfo().speed == 0);
	}

	BOOST_AUTO_TEST_CASE(EngineOff_wasOff)
	{												 
		BOOST_CHECK(Lancer.TurnOffEngine() == ReturnCodeEngineOff::EngineWasOff);
	}

	struct car_EngineOn	: InitCar
	{
		car_EngineOn()
		{
			Lancer.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(EngineOn_in_car, car_EngineOn)

		BOOST_AUTO_TEST_CASE(EngineOff_Complete)
		{
			BOOST_CHECK(Lancer.GetInfo().conditionEngine);
			Lancer.TurnOffEngine();
			BOOST_CHECK(!Lancer.GetInfo().conditionEngine);
		}
		BOOST_AUTO_TEST_CASE(EngineOff_withGearOn)
		{
			Lancer.SetGear(1);
			BOOST_CHECK(Lancer.GetInfo().conditionEngine);
			BOOST_CHECK(Lancer.TurnOffEngine() == ReturnCodeEngineOff::EngineNotOffWithGear);
		}

		BOOST_AUTO_TEST_CASE(EngineOff_withSpeedOn)
		{
			Lancer.SetGear(1);
			Lancer.SetSpeed(10);
			Lancer.SetGear(0);
			BOOST_CHECK(Lancer.GetInfo().conditionEngine);
			BOOST_CHECK(Lancer.GetInfo().gear == 0);
			BOOST_CHECK(Lancer.GetInfo().speed == 10);
			BOOST_CHECK(Lancer.TurnOffEngine() == ReturnCodeEngineOff::EngineNotOffWithSpeed);
		}
		
		BOOST_AUTO_TEST_CASE(SpeedOn_complite_withGearOn)
		{
			Lancer.SetGear(1);
			Lancer.SetSpeed(20);
			Lancer.SetGear(2);
			Lancer.SetSpeed(40);
			BOOST_CHECK(Lancer.GetInfo().speed == 40);
			BOOST_CHECK(Lancer.GetInfo().dir == Direction::Forward);
		}

		BOOST_AUTO_TEST_CASE(SpeedOn_Reverse_complite)
		{
			Lancer.SetGear(-1);
			Lancer.SetSpeed(10);
			BOOST_CHECK(Lancer.GetInfo().speed == 10);
			BOOST_CHECK(Lancer.GetInfo().dir == Direction::Backward);
		}

		BOOST_AUTO_TEST_CASE(SpeedOn_failed_withGearNeutral)
		{
			BOOST_CHECK(Lancer.SetSpeed(10) == ReturnCodeSetSpeed::SpeedNotAddWithNeutralGear);
		}

		BOOST_AUTO_TEST_CASE(SpeedOn_failed_withSpeedNotRange)
		{
			Lancer.SetGear(1);
			BOOST_CHECK(Lancer.SetSpeed(40) == ReturnCodeSetSpeed::SpeedNotRange);
		}

	BOOST_AUTO_TEST_SUITE_END()

	

BOOST_AUTO_TEST_SUITE_END()
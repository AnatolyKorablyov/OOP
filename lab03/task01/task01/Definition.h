#pragma once
#include "stdafx.h"

enum class Transmission
{
	Reverse,	// задн€€
	Neutral,	// нейтральна€
	First,		// перва€
	Second,		// втора€
	Third,		// треть€
	Fourth,		// четверта€
	Fifth		// п€та€
};

enum class Direction
{
	Forward,	// вперед
	Backward,	// назад
	Stand		// стоим
};

struct Border
{
	int bottomBound;	// нижн€€ граница
	int upperBound;		// верхн€€ граница
};

struct InfoAboutCar
{
	bool conditionEngine;	// состо€ние двигател€
	Direction dir;			// направление
	int speed;				// скорость
	int gear;				// передача
};


// ƒ»јѕј«ќЌ — ќ–ќ—“≈…
static const Border REVERSE_GEAR_SPEED = { 0, 20 };
static const Border FIRST_GEAR_SPEED = { 0, 30 };
static const Border SECOND_GEAR_SPEED = { 20, 50 };
static const Border THIRD_GEAR_SPEED = { 30, 60 };
static const Border FOURTH_GEAR_SPEED = { 40, 90 };
static const Border FIFTH_GEAR_SPEED = { 50, 150 };
static const Border NEUTRAL_GEAR_SPEED = { 0, FIFTH_GEAR_SPEED.upperBound };

static const Border GEAR_RANGE = { -1, 5 };

static const std::map<int, Border> SPEED_RANGE =
{
	{ -1, REVERSE_GEAR_SPEED },
	{ 0, NEUTRAL_GEAR_SPEED },
	{ 1, FIRST_GEAR_SPEED },
	{ 2, SECOND_GEAR_SPEED },
	{ 3, THIRD_GEAR_SPEED },
	{ 4, FOURTH_GEAR_SPEED },
	{ 5, FIFTH_GEAR_SPEED }
};

const std::map<Direction, std::string> DIRECTION_NAME =
{
	{ Direction::Forward, "вперед" },
	{ Direction::Backward, "назад" },
	{ Direction::Stand, "стоим на месте" }
};
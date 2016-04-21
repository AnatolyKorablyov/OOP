#pragma once
#include "stdafx.h"
#include "Definition.h"

struct ColorInfo
{
	unsigned R = 0;
	unsigned G = 0;
	unsigned B = 0;
	unsigned Transparent = 0;
	ColorInfo()
	{};
	ColorInfo(unsigned red, unsigned green, unsigned blue, unsigned t)
		: R(red)
		, G(green)
		, B(blue)
		, Transparent(t)
	{};
};

class IShape
{
public:
	virtual ~IShape() = default;
	virtual float GetShapeArea() const = 0;
	virtual float GetShapePerimetr() const = 0;
	virtual std::string ToString() const = 0;
	virtual ColorInfo GetColorLine() const = 0;
};


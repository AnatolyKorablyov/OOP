#pragma once
#include "stdafx.h"

// uppercase
struct ColorInfo
{
	unsigned r = 0;
	unsigned g = 0;
	unsigned b = 0;
	unsigned Transparent = 255;

	ColorInfo()
	{};
	ColorInfo(unsigned red, unsigned green, unsigned blue, unsigned t)
		: r(red)
		, g(green)
		, b(blue)
		, Transparent(t)
	{};
};

// GetArea...
class IShape
{
public:
	virtual ~IShape() = default;
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual ColorInfo GetColorLine() const = 0;
};
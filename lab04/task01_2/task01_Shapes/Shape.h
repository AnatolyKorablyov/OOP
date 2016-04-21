#pragma once
#include "stdafx.h"

// uppercase
struct ColorInfo
{
	unsigned R = 0;
	unsigned G = 0;
	unsigned B = 0;
	unsigned Transparent = 255;

	//ColorInfo(ColorInfo const& info) {}

	ColorInfo()
	{};
	ColorInfo(unsigned red, unsigned green, unsigned blue, unsigned t)
		: R(red)
		, G(green)
		, B(blue)
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
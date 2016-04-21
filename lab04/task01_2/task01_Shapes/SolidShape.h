#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
public:
	virtual ColorInfo GetColorLine() const override;
	ColorInfo GetColorFill();
protected:
	ColorInfo m_colorFill;
	ColorInfo m_colorLine;
};

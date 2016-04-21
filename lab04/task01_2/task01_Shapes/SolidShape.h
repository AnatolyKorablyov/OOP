#pragma once
#include "Shape.h"

// abstract class
class ISolidShape : public IShape
{
public:
	virtual ColorInfo GetColorLine() const override;
	ColorInfo GetColorFill() const;
protected:
	ColorInfo m_colorFill;
	ColorInfo m_colorLine;
};

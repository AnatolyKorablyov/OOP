#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\task01_Shapes\Circle.h"
#include "..\task01_Shapes\Point.h"
#include "..\task01_Shapes\LineSegment.h"
#include "..\task01_Shapes\Rectangle.h"
#include "..\task01_Shapes\Triangle.h"

///////////////////////////////////////////////
// Dot
///////////////////////////////////////////////


struct DotFixture
{
	CPoint dot;
	DotFixture()
		: dot({1.f, 2.f})
	{};
};

BOOST_FIXTURE_TEST_SUITE(addDot, DotFixture)

BOOST_AUTO_TEST_CASE(dot_must_return_coord_specified_in_the_constructor)
{
	BOOST_CHECK_EQUAL(dot.GetPos().x, 1.f);
	BOOST_CHECK_EQUAL(dot.GetPos().y, 2.f);
}
BOOST_AUTO_TEST_CASE(dot_has_zero_perimeter)
{
	BOOST_CHECK_EQUAL(dot.GetPerimeter(), 0.f);
}
BOOST_AUTO_TEST_CASE(dot_has_zero_area)
{
	BOOST_CHECK_EQUAL(dot.GetArea(), 0);
}
BOOST_AUTO_TEST_CASE(dot_has_black_color)
{
	BOOST_CHECK_EQUAL(dot.GetColorLine().r, 0);
	BOOST_CHECK_EQUAL(dot.GetColorLine().g, 0);
	BOOST_CHECK_EQUAL(dot.GetColorLine().b, 0);
}

BOOST_AUTO_TEST_CASE(dot_has_a_string_representation)
{
	BOOST_CHECK_EQUAL(dot.ToString(), "point <1, 2>, S = 0, P = 0");
}	

BOOST_AUTO_TEST_SUITE_END()

///////////////////////////////////////////////
// Line
///////////////////////////////////////////////

struct LineFixture
{
	CLineSegment line;
	LineFixture()
		: line(CPoint(2.f, 4.f), CPoint(6.f, 8.f), ColorInfo(125, 234, 111, 134))
	{}
};

BOOST_FIXTURE_TEST_SUITE(addLine, LineFixture)

	BOOST_AUTO_TEST_CASE(line_get_start_point)
	{
		BOOST_CHECK_EQUAL(line.GetCoordStartDot().GetPos().x, 2.f);
		BOOST_CHECK_EQUAL(line.GetCoordStartDot().GetPos().y, 4.f);
	}
	BOOST_AUTO_TEST_CASE(line_get_end_point)
	{
		BOOST_CHECK_EQUAL(line.GetCoordEndDot().GetPos().x, 6.f);
		BOOST_CHECK_EQUAL(line.GetCoordEndDot().GetPos().y, 8.f);
	}
	BOOST_AUTO_TEST_CASE(line_calc_perimeter)
	{
		BOOST_CHECK_EQUAL(round(line.GetPerimeter() * 10 / 10), 6);
	}
	BOOST_AUTO_TEST_CASE(line_calc_area_zero)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(line_get_color_greenwood)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(line_has_a_string_representation)
	{
		BOOST_CHECK_EQUAL(line.ToString(), "line <2, 4>, <6, 8>, S = 0, P = 5.65685");
	}
BOOST_AUTO_TEST_SUITE_END()


///////////////////////////////////////////////
// Circle
///////////////////////////////////////////////

struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		: circle(CPoint(25.f, 4.f), 24.f, ColorInfo(0, 0, 0, 255), ColorInfo(255, 0, 0, 255))
	{}
};

BOOST_FIXTURE_TEST_SUITE(addCircle, CircleFixture)

BOOST_AUTO_TEST_CASE(circle_get_center_point)
{
	BOOST_CHECK_EQUAL(circle.GetPosCenter().GetPos().x, 25.f);
	BOOST_CHECK_EQUAL(circle.GetPosCenter().GetPos().y, 4.f);
}
BOOST_AUTO_TEST_CASE(circle_get_radius_point)
{
	BOOST_CHECK_EQUAL(circle.GetRadius(), 24.f);
}

BOOST_AUTO_TEST_CASE(circle_calc_perimeter)
{
	BOOST_CHECK_EQUAL(round(circle.GetPerimeter() * 10 / 10), 151);
}
BOOST_AUTO_TEST_CASE(circle_calc_area_zero)
{	
	BOOST_CHECK_EQUAL(round(circle.GetArea() * 10 /10), 1810);
}
BOOST_AUTO_TEST_CASE(circle_get_color_fill_red)
{
	BOOST_CHECK_EQUAL(circle.GetColorFill().r, 255);
	BOOST_CHECK_EQUAL(circle.GetColorFill().g, 0);
	BOOST_CHECK_EQUAL(circle.GetColorFill().b, 0);
	BOOST_CHECK_EQUAL(circle.GetColorFill().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(circle_get_color_line_black)
{
	BOOST_CHECK_EQUAL(circle.GetColorLine().r, 0);
	BOOST_CHECK_EQUAL(circle.GetColorLine().g, 0);
	BOOST_CHECK_EQUAL(circle.GetColorLine().b, 0);
	BOOST_CHECK_EQUAL(circle.GetColorLine().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(circle_has_a_string_representation)
{
	BOOST_CHECK_EQUAL(circle.ToString(), "circle <25, 4>, radius = 24, S = 1809.56, P = 150.796");
}
BOOST_AUTO_TEST_SUITE_END()


///////////////////////////////////////////////
// Rectangle
///////////////////////////////////////////////

struct RectangleFixture
{
	CRectangle rect;
	RectangleFixture()
		: rect(CPoint(25.f, 4.f), 24.f, 400.56f, ColorInfo(0, 0, 0, 255), ColorInfo(255, 0, 0, 255))
	{}
};

BOOST_FIXTURE_TEST_SUITE(addRectangle, RectangleFixture)

BOOST_AUTO_TEST_CASE(rectangle_get_center_point)
{
	BOOST_CHECK_EQUAL(rect.GetTopLeftPoint().GetPos().x, 25.f);
	BOOST_CHECK_EQUAL(rect.GetTopLeftPoint().GetPos().y, 4.f);
}
BOOST_AUTO_TEST_CASE(rectangle_get_height)
{
	BOOST_CHECK_EQUAL(round(rect.GetHeight() * 10 / 10), 401.f);
}
BOOST_AUTO_TEST_CASE(rectangle_get_width)
{
	BOOST_CHECK_EQUAL(round(rect.GetWidth() * 10 / 10), 24);
}
BOOST_AUTO_TEST_CASE(rectangle_calc_perimeter)
{
	BOOST_CHECK_EQUAL(round(rect.GetPerimeter() * 10 / 10), 849.f);
}
BOOST_AUTO_TEST_CASE(rectangle_calc_area_zero)
{
	BOOST_CHECK_EQUAL(round(rect.GetArea() * 10 / 10), 9613.f);
}
BOOST_AUTO_TEST_CASE(rectangle_get_color_fill_red)
{
	BOOST_CHECK_EQUAL(rect.GetColorFill().r, 255);
	BOOST_CHECK_EQUAL(rect.GetColorFill().g, 0);
	BOOST_CHECK_EQUAL(rect.GetColorFill().b, 0);
	BOOST_CHECK_EQUAL(rect.GetColorFill().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(rectangle_get_color_line_black)
{
	BOOST_CHECK_EQUAL(rect.GetColorLine().r, 0);
	BOOST_CHECK_EQUAL(rect.GetColorLine().g, 0);
	BOOST_CHECK_EQUAL(rect.GetColorLine().b, 0);
	BOOST_CHECK_EQUAL(rect.GetColorLine().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(rectangle_has_a_string_representation)
{
	BOOST_CHECK_EQUAL(rect.ToString(), "rectangle <25, 4>, height = 400.56, width = 24, S = 9613.44, P = 849.12");
}
BOOST_AUTO_TEST_SUITE_END()


///////////////////////////////////////////////
// Triangle
///////////////////////////////////////////////

struct triangleFixture
{
	CTriangle triangle;
	triangleFixture()
		: triangle(CPoint(25.f, 4.f), CPoint(100.f, 4.f), CPoint(60.f, 40.f), ColorInfo(0, 0, 0, 255), ColorInfo(255, 0, 0, 255))
	{}
};

BOOST_FIXTURE_TEST_SUITE(addTriangle, triangleFixture)

BOOST_AUTO_TEST_CASE(trianglee_get_points)
{
	BOOST_CHECK_EQUAL(triangle.GetPoints()["A"].GetPos().x, 25.f);
	BOOST_CHECK_EQUAL(triangle.GetPoints()["A"].GetPos().y, 4.f);

	BOOST_CHECK_EQUAL(triangle.GetPoints()["B"].GetPos().x, 100.f);
	BOOST_CHECK_EQUAL(triangle.GetPoints()["B"].GetPos().y, 4.f);

	BOOST_CHECK_EQUAL(triangle.GetPoints()["C"].GetPos().x, 60.f);
	BOOST_CHECK_EQUAL(triangle.GetPoints()["C"].GetPos().y, 40.f);
}
BOOST_AUTO_TEST_CASE(triangle_calc_perimeter)
{
	BOOST_CHECK_EQUAL(round(triangle.GetPerimeter() * 10 / 10), 179.f);
}
BOOST_AUTO_TEST_CASE(triangle_calc_area_zero)
{
	BOOST_CHECK_EQUAL(round(triangle.GetArea() * 10 / 10), 1350.f);
}
BOOST_AUTO_TEST_CASE(triangle_get_color_fill_red)
{
	BOOST_CHECK_EQUAL(triangle.GetColorFill().r, 255);
	BOOST_CHECK_EQUAL(triangle.GetColorFill().g, 0);
	BOOST_CHECK_EQUAL(triangle.GetColorFill().b, 0);
	BOOST_CHECK_EQUAL(triangle.GetColorFill().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(triangle_get_color_line_black)
{
	BOOST_CHECK_EQUAL(triangle.GetColorLine().r, 0);
	BOOST_CHECK_EQUAL(triangle.GetColorLine().g, 0);
	BOOST_CHECK_EQUAL(triangle.GetColorLine().b, 0);
	BOOST_CHECK_EQUAL(triangle.GetColorLine().Transparent, 255);
}
BOOST_AUTO_TEST_CASE(triangle_has_a_string_representation)
{
	BOOST_CHECK_EQUAL(triangle.ToString(), "triangle FirstVertex <25, 4>, SecondVertex <100, 4>, ThirdVertex <60, 40>, S = 1350, P = 179.024");
}
BOOST_AUTO_TEST_SUITE_END()
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
		: dot({ 1, 2 })
	{};
};

BOOST_FIXTURE_TEST_SUITE(Dot, DotFixture)

BOOST_AUTO_TEST_CASE(must_return_coord_specified_in_the_constructor)
{
	BOOST_CHECK_EQUAL(dot.GetPos().x, 1);
	BOOST_CHECK_EQUAL(dot.GetPos().y, 2);
}
BOOST_AUTO_TEST_CASE(has_zero_perimeter)
{
	BOOST_CHECK_EQUAL(dot.GetPerimetr(), 0);
}
BOOST_AUTO_TEST_CASE(has_zero_area)
{
	BOOST_CHECK_EQUAL(dot.GetArea(), 0);
}
BOOST_AUTO_TEST_CASE(has_black_color)
{
	BOOST_CHECK_EQUAL(dot.GetColorLine().R, 0);
	BOOST_CHECK_EQUAL(dot.GetColorLine().G, 0);
	BOOST_CHECK_EQUAL(dot.GetColorLine().B, 0);
}

BOOST_AUTO_TEST_CASE(has_a_string_representation)
{
	BOOST_CHECK_EQUAL(dot.ToString(), "point <1, 2>, S = 0, P = 0");
}	

BOOST_AUTO_TEST_SUITE_END()

///////////////////////////////////////////////
// Line
///////////////////////////////////////////////

struct lineFixture
{
	CLineSegment line;
	lineFixture()
		: line(sf::Vector2f(3, 5), sf::Vector2f(6, 2), ColorInfo(123, 121, 251, 230))
	{};
};

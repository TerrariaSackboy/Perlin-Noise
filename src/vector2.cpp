#include <cmath>
#include "vector2.hpp"

using namespace trsb;

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(double x, double y)
{
	this -> x = x;
	this -> y = y;
}

double Vector2::Dot(const Vector2& other)
{
	return x * other.x + y * other.y;
}

double Vector2::Magnitude()
{
	return sqrt(x*x + y*y);
}


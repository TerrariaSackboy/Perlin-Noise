#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

namespace trsb
{
	struct Vector2
	{
		double x;
		double y;

		Vector2();
		Vector2(double x, double y);

		double Dot(const Vector2& other);
		double Magnitude();
	};
}

#endif//__VECTOR2_HPP__


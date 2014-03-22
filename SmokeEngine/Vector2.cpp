#include "Vector2.h"
#include "math.h"


		Vector2::Vector2(float x, float y)
		{
			Vector2::X = x;
			Vector2::Y = y;
		}
		Vector2::Vector2(void)
		{
			Vector2::X = 0;
			Vector2::Y = 0;
		}
		
		Vector2::~Vector2(void)
		{
		}

		Vector2 Vector2::operator+(const Vector2& other)
		{
			return Vector2(other.X + X,Y + other.Y);
		}

		Vector2 Vector2::operator*(const Vector2& other)
		{
			return Vector2(X*other.X ,Y * other.Y);
		}
		Vector2 Vector2::operator/(const Vector2& other)
		{
			return Vector2(X/other.X ,Y / other.Y);
		}

		Vector2 Vector2::GetUnitVector()
		{
			float llength = GetLength();
			return Vector2(X/llength,Y/llength);
		}

		float Vector2::GetLength()
		{
			return sqrt(X *X+ Y * Y);
		}
	
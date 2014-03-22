#pragma once


class Vector2
{
	public:
		float X; 
		float Y;

		Vector2(float x, float y);
		Vector2(void);
		~Vector2(void);

		Vector2 operator+(const Vector2& other);
		Vector2 operator*(const Vector2& other);
		Vector2 operator/(const Vector2& other);

		//returns the unit vector
		Vector2 GetUnitVector();
		//returns the lenght of the vector
		float GetLength();
};


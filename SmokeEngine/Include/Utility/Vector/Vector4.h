#pragma once
class Vector4
{


public:
	float X; 
	float Y;
	float Z;
	float W;

	Vector4(float x, float y ,float z,float w);
	Vector4(void);
	~Vector4(void);

	Vector4 operator+(const Vector4& other);
	Vector4 operator*(const Vector4& other);
	Vector4 operator/(const Vector4& other);

	Vector4 GetUnitVector();
	float GetLength();
};


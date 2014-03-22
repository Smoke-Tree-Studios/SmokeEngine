#include "Vector4.h"
#include "math.h"

Vector4::Vector4(float x, float y ,float z,float w)
{
}
Vector4::Vector4(void)
{
}
Vector4::~Vector4(void)
{
}

Vector4 Vector4::operator+(const Vector4& other)
{
	return Vector4(other.X + X, other.Y + Y, other.Z + Z, other.W + W);
}
Vector4 Vector4::operator*(const Vector4& other)
{
	return Vector4(other.X * X, other.Y * Y, other.Z * Z, other.W * W);
}
Vector4 Vector4::operator/(const Vector4& other)
{
	return Vector4(other.X / X, other.Y / Y, other.Z / Z, other.W / W);
}

Vector4 Vector4::GetUnitVector()
{
	float llength = GetLength();
	return Vector4(X/llength,Y/llength,Z/llength,W/llength);
}
float Vector4::GetLength()
{
	return sqrt(X * X+ Y * Y + Z * Z + W * W);
}

#include "Vector3.h"
#include "math.h"

Vector3::Vector3(float x, float y ,float z)
{
	Vector3::X = x;
	Vector3::Y = y;
	Vector3::Z = z;
}

Vector3::Vector3()
{
	Vector3::X = 0;
	Vector3::Y = 0;
	Vector3::Z = 0;
}


Vector3::~Vector3(void)
{
}


Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(other.X + Vector3::X,Vector3::Y + other.Y,  Vector3::Z + other.Z);
}

Vector3 Vector3::operator*(const Vector3& other)
{
	return Vector3(other.X * Vector3::X,Vector3::Y * other.Y,  Vector3::Z * other.Z);
}

Vector3 Vector3::operator/(const Vector3& other)
{
	return Vector3(Vector3::X/other.X ,Vector3::Y / other.Y,  Vector3::Z / other.Z);
}


float Vector3::GetLength()
{
	return sqrt(X * X+ Y * Y + Z * Z);
}

Vector3 Vector3::GetUnitVector(){
	float llength = GetLength();
	return Vector3(X/llength,Y/llength,Z/llength);
}
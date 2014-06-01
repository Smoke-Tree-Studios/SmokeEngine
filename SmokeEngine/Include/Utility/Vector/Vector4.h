#pragma once
class Vector4
{


public:
	float X; 
	float Y;
	float Z;
	float W;
	
	/**
	 * cretes a vector4 object for the xyzw component
	 **/
	Vector4(float x, float y ,float z,float w);
	/**
	 * creates a black vector4 with the components(0,0,0,0)
	 **/
	Vector4(void);
	
	~Vector4(void);
	
	/**
	 * adds two vector4
	 **/
	Vector4 operator+(const Vector4& other);
	/**
	 * multiply two vector4 elements
	 **/
	Vector4 operator*(const Vector4& other);
	/**
	 * divides the two vector 4 elements
	 **/
	Vector4 operator/(const Vector4& other);
	
	/**
	 * retrives the unit vector4 element
	 **/
	Vector4 GetUnitVector();
	
	/**
	 *retrieves the lenght of the vector
	**/
	float GetLength();
};


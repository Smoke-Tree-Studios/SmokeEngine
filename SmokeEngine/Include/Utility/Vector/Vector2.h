#pragma once


class Vector2
{
	public:
		float X; 
		float Y;

		Vector2(float x, float y);
		Vector2(void);
		~Vector2(void);
		
		/**
		 * adds two vector3 objects together
		 **/
		Vector2 operator+(const Vector2& other);
		/**
		 * multiply the two vector2 objects together
		 **/
		Vector2 operator*(const Vector2& other);
		
		/**
		 * divide two vector2 objects together
		 **/
		Vector2 operator/(const Vector2& other);

		/**
		*returns the unit vector
		**/
		Vector2 GetUnitVector();

		/**
		*returns the lenght of the vector
		**/
		float GetLength();
};


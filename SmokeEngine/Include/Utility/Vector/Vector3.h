#pragma once


		class Vector3
		{

			public:
				float X; 
				float Y;
				float Z;
				
				/**
				 * creates a vector3 object
				 **/
				Vector3(float x, float y ,float z);
				Vector3(void);
				~Vector3(void);
				
				/**
				 * adds two vector3 object together
				 **/
				Vector3 operator+(const Vector3& other);
				
				/**
				 * multiply two vector3 elements together
				 **/
				Vector3 operator*(const Vector3& other);
				
				/**
				 *multiply the vector3 elements against a single float
				 **/
				Vector3 operator*(const float& other);
				
				/**
				 * divides two vector3 elements together
				 **/
				Vector3 operator/(const Vector3& other);

				/**
				 * retrieves the unit lenght for the vector3 elements
				 **/
				Vector3 GetUnitVector();
				
				/**
				 *retrieves the lenght of the vector3 element
				 **/ 
				float GetLength();
		};

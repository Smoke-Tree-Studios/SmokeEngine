#pragma once


		class Vector3
		{

			public:
				float X; 
				float Y;
				float Z;

				Vector3(float x, float y ,float z);
				Vector3(void);
				~Vector3(void);

				Vector3 operator+(const Vector3& other);
				Vector3 operator*(const Vector3& other);
				Vector3 operator*(const float& other);
				Vector3 operator/(const Vector3& other);


				Vector3 GetUnitVector();
				float GetLength();
		};

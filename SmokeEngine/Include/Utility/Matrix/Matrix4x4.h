#pragma once
#include "Utility\Quaternion.h"
#include "Utility\Vector\Vector3.h"
#include <GLES2\gl2.h>

class Matrix4x4 
{

	public:
		float m11;
		float m21;
		float m31;
		float m41;

		float m12;
		float m22;
		float m32;
		float m42;

		float m13;
		float m23;
		float m33;
		float m43;

		float m14;
		float m24;
		float m34;
		float m44;

		static Matrix4x4 Translation(float x, float y, float z);
		static Matrix4x4 Translation(Vector3 translation);

		static Matrix4x4 RotationX(float amount);
		static Matrix4x4 RotationY(float amount);
		static Matrix4x4 RotationZ(float amount);
		static Matrix4x4 Rotation(Quaternion quanterion);

		static Matrix4x4 Scale(float x, float y,float z);
		static Matrix4x4 Scale(Vector3 scale);

		static Matrix4x4 Orthographic(float left, float right, float top, float bottom,float far, float near);
		static Matrix4x4 Perspective(float fov, float aspect, float znear, float zfar);

		static Matrix4x4 Idenity();

		Matrix4x4 operator+(const Matrix4x4& other);
		Matrix4x4 operator-(const Matrix4x4& other);
		Matrix4x4 operator*(const Matrix4x4& other);
		Matrix4x4 operator*(const float& other);


		Matrix4x4(void);
		Matrix4x4(float m11, float m21, float m31, float m41, float m12, float m22, float m32, float m42,float m13, float m23, float m33, float m43,float m14, float m24, float m34, float m44);
		~Matrix4x4(void);
	};

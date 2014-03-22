#include "Utility\Matrix\Matrix4x4.h"
#include "math.h"
Matrix4x4::Matrix4x4(void)
{
	m11 = 1;
	m21 = 0;
	m31 = 0;
	m41 = 0;

	m12 = 0;
	m22 = 1;
	m32 = 0;
	m42 = 0;

	m13 = 0;
	m23 = 0;
	m33 = 1;
	m43 = 0;

	m14 = 0;
	m24 = 0;
	m34 = 0;
	m44 = 1;
}

Matrix4x4::Matrix4x4(float m11, float m21, float m31, float m41, float m12, float m22, float m32, float m42,float m13, float m23, float m33, float m43,float m14, float m24, float m34, float m44)
{
	Matrix4x4::m11= m11;
	Matrix4x4::m21 = m12;
	Matrix4x4::m31 = m13;
	Matrix4x4::m41 = m14;

	Matrix4x4::m12 = m21;
	Matrix4x4::m22 = m22;
	Matrix4x4::m32 = m23;
	Matrix4x4::m42 = m24;

	Matrix4x4::m13 = m31;
	Matrix4x4::m23 = m32;
	Matrix4x4::m33= m33;
	Matrix4x4::m43 = m34;

	Matrix4x4::m14 = m41;
	Matrix4x4::m24 = m42;
	Matrix4x4::m34 = m43;
	Matrix4x4::m44 = m44;
		
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other)
{
			
	return Matrix4x4(
		m11 + other.m11,
		m21 + other.m21,
		m31 + other.m31,
		m41 + other.m41,
		m21 + other.m21,
		m22 + other.m22,
		m23 + other.m23,
		m24 + other.m24,
		m31 + other.m31,
		m32 + other.m32,
		m33 + other.m33,
		m34 + other.m34,
		m14 + other.m14,
		m24 + other.m24,
		m34 + other.m34,
		m44 + other.m44);
}
Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other)
{
		return Matrix4x4(
		m11 - other.m11,
		m21 - other.m21,
		m31 - other.m31,
		m41 - other.m41,
		m21 - other.m21,
		m22 - other.m22,
		m23 - other.m23,
		m24 - other.m24,
		m31 - other.m31,
		m32 - other.m32,
		m33 - other.m33,
		m34 - other.m34,
		m14 - other.m14,
		m24 - other.m24,
		m34 - other.m34,
		m44 - other.m44);
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other)
{
	return Matrix4x4(
		m11 * other.m11 + m21 * other.m12 + m31 * other.m13 + m41 * other.m14,
		m11 * other.m21 + m21 * other.m22 + m31 * other.m23 + m41 * other.m24,
		m11 * other.m31 + m21 * other.m32 + m31 * other.m33 + m41 * other.m34,
		m11 * other.m41 + m21 * other.m42 + m31 * other.m43 + m41 * other.m44,

		m12 * other.m11 + m22 * other.m12 + m32 * other.m13 + m42 * other.m14,
		m12 * other.m21 + m22 * other.m22 + m32 * other.m23 + m42 * other.m24,
		m12 * other.m31 + m22 * other.m32 + m32 * other.m33 + m42 * other.m34,
		m12 * other.m41 + m22 * other.m42 + m32 * other.m43 + m42 * other.m44,

		m13 * other.m11 + m23 * other.m12 + m33 * other.m13 + m43 * other.m14,
		m13 * other.m21 + m23 * other.m22 + m33 * other.m23 + m43 * other.m24,
		m13 * other.m31 + m23 * other.m32 + m33 * other.m33 + m43 * other.m34,
		m13 * other.m41 + m23 * other.m42 + m33 * other.m43 + m43 * other.m44,

		m14 * other.m11 + m24 * other.m12 + m34 * other.m13+ m44 * other.m14,
		m14 * other.m21 + m24 * other.m22 + m34 * other.m23+ m44 * other.m24,
		m14 * other.m31 + m24 * other.m32 + m34 * other.m33+ m44 * other.m34,
		m14 * other.m41 + m24 * other.m42 + m34 * other.m43+ m44 * other.m44);
}

Matrix4x4 Matrix4x4::operator*(const float& other)
{
	return Matrix4x4(m11 * other,m21 * other,m31 * other,m41 * other,m12 * other,m22 * other,m32 * other,m42  * other,m13  * other,m23  * other,m33  * other,m43  * other,m14 * other,m24  * other,m34  * other,m44  * other);
}

 Matrix4x4 Matrix4x4::Translation(float x, float y, float z)
{
	return Matrix4x4(
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		x,y,z,1
		);
}

 Matrix4x4 Matrix4x4::Translation(Vector3 translation)
{
	return Matrix4x4(
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translation.X,translation.Y,translation.Z,1);
}

Matrix4x4 Matrix4x4::RotationX(float amount)
{
	return Matrix4x4(
		1,0,0,0,
		0,cos(amount),sin(amount),0,
		0,-sin(amount),cos(amount),0,
		0,0,0,1);
}

Matrix4x4 Matrix4x4::RotationY(float amount)
{
	return Matrix4x4(
		cos(amount),0,-sin(amount),0,
		0,1,0,0,
		sin(amount),0,cos(amount),0,
		0,0,0,1);
}

Matrix4x4 Matrix4x4::RotationZ(float amount)
{
	return Matrix4x4(
		cos(amount),sin(amount),0,0,
		-sin(amount),cos(amount),0,0,
		0,0,1,0,
		0,0,0,1);
}

Matrix4x4 Matrix4x4::Rotation(Quanterion quanterion)
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::Scale(float x, float y,float z)
{
		return Matrix4x4(
			x,0,0,0,
			0,y,0,0,
			0,0,z,0,
			0,0,0,1);
}

Matrix4x4 Matrix4x4::Orthographic(float left, float right, float top, float bottom,float far, float near)
{
	Matrix4x4 lfinal = Matrix4x4();
	lfinal.m11 = 2/(right-left);
	lfinal.m22 = 2/(top-bottom);
	lfinal.m33 = (-2)/(far-near);
	lfinal.m41 = -((right+left)/(right-left));
	lfinal.m42 = -((top+bottom)/(top-bottom));
	lfinal.m43 = ((far+near)/(far-near));
	return lfinal;
	
}
Matrix4x4 Matrix4x4::Perspective(float fov, float aspect, float znear, float zfar)
{
		float lh = znear * tan(fov);
		float lneg_depgh = znear - zfar;
		return Matrix4x4(
			lh/aspect,0,0,0,
			0,lh,0,0,
			0,0,(zfar+znear)/lneg_depgh,-1,
			0,0,2.0f * (znear*zfar)/lneg_depgh,0);
}



Matrix4x4 Matrix4x4::Scale(Vector3 scale)
{
	return Matrix4x4(
		scale.X,0,0,0,
		0,scale.Y,0,0,
		0,0,scale.Z,0,
		0,0,0,1);
}

Matrix4x4::~Matrix4x4(void)
{
}


/*******************************************************************
 * \file Matrix.h
 *
 * \author puppet_master
 * \date 2018/05/20
 * \https://blog.csdn.net/puppet_master
 * \������ʵ�֣������ľ������㣬�Լ���������������
 *******************************************************************/
#pragma once
#include"Vector3.h"

class Matrix
{
public:

	float value[4][4];

	Matrix();
	~Matrix();

	Matrix operator + (const Matrix& right) const;
	Matrix operator - (const Matrix& right) const;
	Matrix operator * (const Matrix& right) const;
	Matrix operator * (float k) const;

	Vector3 MultiplyVector3(const Vector3& v) const;
	void Identity();
	void Transpose();

	void Print();

};


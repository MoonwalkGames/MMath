#pragma once
#include <cmath>
#include <iostream>
#include "MVector.h"
using namespace std;

	MVector::MVector()
	{
		x = 0;
		y = 0;
		z = 0;
		cout << "[" << x << ", " << y << ", " << z << "]" << endl;
	}


	void MVector::setVector(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	void MVector::setVecX(float X)
	{
		x = X;
	}
	void MVector::setVecY(float Y)
	{
		y = Y;
	}
	void MVector::setVecZ(float Z)
	{
		z = Z;
	}

	float MVector::getVecX() const
	{
		return x;
	}
	float MVector::getVecY() const
	{
		return y;
	}
	float MVector::getVecZ() const
	{
		return z;
	}

	MVector MVector::convert2D(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = 0;
	}

	float MVector::magnitude(float x, float y, float z)
	{
		float magnitude;
		return magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	MVector MVector::normalize(float X, float Y, float Z)
	{
		MVector vector;
		float length;
		x = X;
		y = Y;
		z = Z;

		length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		vector.x = x / length;
		vector.y = y / length;
		vector.z = z / length;
		return vector;
	}

	MVector MVector::operator+(const MVector & vect)
	{
		MVector vector;
		vector.x = x + vect.x;
		vector.y = y + vect.y;
		vector.z = z + vect.z;
		return vector;
	}

	MVector MVector::operator-(const MVector & vect)
	{
		MVector vector;
		vector.x = x - vect.x;
		vector.y = y - vect.y;
		vector.z = z - vect.z;
		return vector;
	}

	MVector operator+(const MVector& vect1, const MVector& vect2)
	{
		MVector vector;
		vector.x = vect1.x + vect2.x;
		vector.y = vect1.y + vect2.y;
		vector.z = vect1.z + vect2.z;
		return vector;
	}
	MVector operator-(const MVector& vect1, const MVector& vect2)
	{
		MVector vector;
		vector.x = vect1.x - vect2.x;
		vector.y = vect1.y - vect2.y;
		vector.z = vect1.z - vect2.z;
		return vector;
	}

	MVector operator*(const MVector& vect1, const MVector& vect2)
	{
		MVector vector;
		vector.x = vect1.x * vect2.x;
		vector.y = vect1.y * vect2.y;
		vector.z = vect1.z * vect2.z;
		float total = vector.x + vector.y + vector.z;
		return total;
	}

	static const MVector crossProd(const MVector& vect1, const MVector& vect2)
	{
		MVector vector;
		vector.x = (vect1.y * vect2.z) - (vect1.z - vect2.y);
		vector.y = (vect1.z * vect2.x) - (vect1.x - vect2.z);
		vector.z = (vect1.x * vect2.y) - (vect1.y - vect2.x);
		return vector;
	}

	static const MVector proj(const MVector& vect1, const MVector& vect2)
	{
		return (((dotProd(vect1, vect2)) / pow(vect2.magnitude(), 2)) * vect2);
	}
	static const MVector vect_Left()
	{
		MVector vector;
		vector.x = 1;
		vector.y = 0;
		vector.z = 0;
		return vector;
	}

	static const MVector vect_Right()
	{
		MVector vector;
		vector.x = -1;
		vector.y = 0;
		vector.z = 0;
		return vector;
	}
	static const MVector vect_Up()
	{
		MVector vector;
		vector.x = 0;
		vector.y = 1;
		vector.z = 0;
		return vector;
	}
	static const MVector vect_Down()
	{
		MVector vector;
		vector.x = 0;
		vector.y = -1;
		vector.z = 0;
		return vector;
	}
	static const MVector vect_Forward()
	{
		MVector vector;
		vector.x = 0;
		vector.y = 0;
		vector.z = 1;
		return vector;
	}
	static const MVector vect_Back()
	{
		MVector vector;
		vector.x = 0;
		vector.y = 0;
		vector.z = -1;
		return vector;
	}

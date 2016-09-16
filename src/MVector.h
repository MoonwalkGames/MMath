#pragma once
#include <cmath>

class MVector
{

public:


	MVector();		//Class constructor

	void setVector(float X, float Y, float Z);
	void setVecX(float X);
	void setVecY(float Y);
	void setVecZ(float Z);
	float getVecX() const;
	float getVecY() const;
	float getVecZ() const;

	MVector convert2D(float X, float Y, float Z);
	float magnitude(float X, float Y, float Z);
	MVector normalize(float X, float Y, float Z);

	MVector operator+(const MVector& vect);
	MVector operator-(const MVector& vect);
	MVector operator*(const MVector& vect);


	static const MVector crossProd(const MVector& vect1, const MVector& vect2);
	static const MVector proj(const MVector& vect1, const MVector& vect2);
	static const MVector vect_Left();
	static const MVector vect_Right();
	static const MVector vect_Up();
	static const MVector vect_Down();
	static const MVector vect_Forward();
	static const MVector vect_Back();
	
	float x, y, z;


private:
	

};


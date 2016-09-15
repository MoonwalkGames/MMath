#pragma once
class MoonMath
{
	
};

class MoonCollisions
{
	struct Collision
	{
	public:
		bool getCollisionStatus();

	private:
		bool isColliding;
		vector2d penetrationVector;
		vector3d penetrationVector;

	};
};

class vector2d
{
public:
	vector2d(float xcoord, float ycoord);
	float x, y;

	vector2d operator+(const vector2d& vect);

	vector2d operator-(const vector2d& vect);

	vector2d operator*(const vector2d& vect); //Dot Product

	vector2d normalize(float xcoord, float ycoord); //This needs #include <cmath>

};

class vector3d
{
public:
	vector3d(float xcoord, float ycoord, float zcoord);
	float x, y, z;

	vector3d operator+(const vector3d& vect);

	vector3d operator-(const vector3d& vect);

	vector3d operator*(const vector3d& vect); //Dot Product

	vector3d normalize(float xcoord, float ycoord, float zcoord); //This needs #include <cmath>

};
//vector Library
#pragma once
#include <map>

class vector2
{
public:
	vector2(void);
	vector2(float changeX,float changeY);
	~ vector2();
	void operator -= (vector2 change);
	void operator += (vector2 change);
	void operator -= (float change);
	void operator += (float change);
	void operator *= (float change);
	void operator << (vector2 change);
	bool operator == (vector2 change);
	bool operator != (vector2 change);
	vector2 operator - (vector2 change);
	vector2 operator + (vector2 change);
	vector2 operator - (float change);
	vector2 operator + (float change);
	vector2 operator * (float change);
	bool checkSpace (vector2 cord,int dist);
	//Maths
	float magnitude();
	float dotProduct(vector2 change);
	float crossProduct(vector2 change);
	void normalise();
	vector2 getNormal();
	vector2 linearInterp(float alpha,vector2 change);
	float eulerAngle(vector2 change);


	float x,y;
};
class vector3
{
public:
	vector3();
	vector3(float changeX,float changeY,float changeZ);
	~ vector3();
	void operator -= (vector3 change);
	void operator += (vector3 change);
	void operator -= (float change);
	void operator += (float change);
	void operator *= (float change);
	void operator << (vector3 change);
	vector3 operator - (vector3 change);
	vector3 operator + (vector3 change);
	vector3 operator - (float change);
	vector3 operator + (float change);
	vector3 operator * (float change);
	vector3 empty(void);
	//Maths
	float magnitude();
	float magnitudeSqured() const;
	float dotProduct(vector3 change);
	float dot(vector3 & other) const;
	vector3 crossProduct(vector3 change);
	vector3 linearInterp(float alpha, vector3 change);
	void normalise();
	void fill(float x,float y, float z);
	vector3 getNormal();
	float eulerAngle(vector3 change);
	float getPart(int choice);


	float x,y,z;
};
class vector4
{
public:
	vector4(void);
	vector4(char*r, char*b, char*g);
	vector4(float a,float b, float c, float d);
	void operator << (vector4 change);
	void setPart(int i,float change);
	void set(float a, float b, float c, float d);
	void normalise();
	float getPart(int change);
	float magnitude();
	float a,b,c,d;
};
class Matrix
{
public:
	Matrix(void);
	Matrix(vector4 change,int size);
	Matrix(vector4 changeOne,vector4 changeTwo,vector4 changeThree);
	Matrix(vector4 changeOne,vector4 changeTwo,vector4 changeThree,vector4 changeFour);
	
	void operator += (Matrix change);
	void operator -= (Matrix change);
	void operator *= (Matrix change);

	Matrix projection(Matrix change);
	Matrix createScale(float scaler);
	Matrix rotate(char axis, float angle);
	Matrix createOrthographic(float left,float  right,float  bottom,float  top,float  near,float  far);
	void scaleThis(float scaler);
	void transformP(vector3 point);
	void transformP(vector4 point);
	void transformV(vector3 change);
	void transformV(vector4 change);

	void setMatrix(Matrix change);
	void setIdentity();
	void setZero();
	void transpose();

	//size is either 3 or 4
//private:
	int size;
	vector4 line[4];
};

void convertRtD(float & change);
void convertDtR(float & change);

bool closestPowTwo(float & value);
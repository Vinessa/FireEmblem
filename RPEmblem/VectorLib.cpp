#include"stdafx.h"
#include "VectorLib.h"
#include <iostream>

using namespace std;

vector2::vector2(void)
{
	x = 0;
	y = 0;
}
vector2::vector2(float changeX, float changeY)
{
	x = changeX;
	y = changeY;
}
vector2::~vector2(void)
{
}

void vector2::operator -= (vector2 change)
{
	x -= change.x;
	y -= change.y;
}
void vector2::operator += (vector2 change)
{
	x += change.x;
	y += change.y;
}
void vector2::operator -= (float change)
{
	
	x -= change;
	y -= change;
}
void vector2::operator += (float change)
{
	x += change;
	y += change;
}
void vector2::operator *= (float change)
{
	x *= change;
	y *= change;
}
void vector2::operator << (vector2 change)
{
	x = change.x;
	y = change.y;
}
bool vector2::operator == (vector2 change)
{
	if (x == change.x && y == change.y)
		return true;
	else
		return false;
}
bool vector2::operator != (vector2 change)
{
	if (x != change.x && y != change.y)
		return true;
	else
		return false;
}

vector2 vector2::operator - (vector2 change)
{
	vector2 temp(x - change.x,y - change.y);
	return temp;
}
vector2 vector2::operator + (vector2 change)
{
	vector2 temp(x + change.x,y + change.y);
	return temp;
}
vector2 vector2::operator - (float change)
{
	vector2 temp(x - change,y - change);
	return temp;
}
vector2 vector2::operator + (float change)
{
	vector2 temp(x + change,y + change);
	return temp;
}
vector2 vector2::operator * (float change)
{
	vector2 temp(x * change, y * change);
	return temp;
}
bool vector2::checkSpace (vector2 cord, int dist)
{
	if ((x - dist <= cord.x && x + dist >= cord.x) && (y - dist <= cord.y && y + dist >= cord.y))
	return true;
	return false;
}
//Maths
float vector2::magnitude()
{
	return (float)sqrt((powf(x,2) + pow(y,2)));
}
float vector2::dotProduct(vector2 change)
{
	return ((x*change.x) + (y*change.y));
}
float vector2::crossProduct(vector2 change)
{
	return x * change.y - y * change.x;
}
float vector2::eulerAngle(vector2 change)
{
	//A.B = |A| *|B| * Cos(theta)
	// theta =ArcCos( A.B/|AB|)
	vector2 temp(x,y);
	float theta = acos(dotProduct(change) / temp.magnitude());
	temp.x = x;
	temp.y = y;
	return (temp.magnitude() * change.magnitude() * cos(theta));
}

void vector2::normalise()
{
	x = x/magnitude();
	y = y/magnitude();
}

vector2 vector2::getNormal()
{
	vector2 temp(x/magnitude(),y/magnitude());
	return temp;
}
vector2 vector2::linearInterp(float alpha,vector2 change)
{
	//(1-alpha)Av + alphaBv
	alpha = 1- alpha;
	vector2 returnVector((this->x * alpha) + (change.x * alpha),(this->y * alpha) + (change.y * alpha));
	return returnVector;
}






vector3::vector3()
{
	x = y = z = 0;
}
vector3::vector3(float changeX,float changeY,float changeZ)
{
	x = changeX;
	y = changeY;
	z = changeZ;
}
vector3::~vector3(void)
{
}

void vector3::operator -= (vector3 change)
{
	x -= change.x;
	y -= change.y;
	z -= change.z;
}
void vector3::operator += (vector3 change)
{
	x += change.x;
	y += change.y;
	z += change.z;
}
void vector3::operator -= (float change)
{
	
	x -= change;
	y -= change;
	z -= change;
}
void vector3::operator += (float change)
{
	x += change;
	y += change;
	z += change;
}
void vector3::operator *= (float change)
{
	x *= change;
	y *= change;
	z *= change;
}
void vector3::operator << (vector3 change)
{
	x = change.x;
	y = change.y;
	z = change.z;
}

vector3 vector3::operator - (vector3 change)
{
	vector3 temp(x - change.x,y - change.y,z - change.z);
	return temp;
}
vector3 vector3::operator + (vector3 change)
{
	vector3 temp(x + change.x,y + change.y,z + change.z);
	return temp;
}
vector3 vector3::operator - (float change)
{
	vector3 temp(x - change,y - change,z - change);
	return temp;
}
vector3 vector3::operator + (float change)
{
	vector3 temp(x + change,y + change,z + change);
	return temp;
}
vector3 vector3::operator * (float change)
{
	vector3 temp(x * change,y * change,z * change);
	return temp;
}
vector3 vector3::empty(void) 
{
	vector3 change(0,0,0);
		return change;
}
//Maths
float vector3::magnitude()
{
	return (float)sqrt((pow((double)x,2) + pow((double)y,2)+ pow((double)z,2)));
}
float vector3::dotProduct(vector3 change)
{
	return ((x*change.x) + (y*change.y) + (z*change.z));
}
float vector3::eulerAngle(vector3 change)
{
	//A.B = |A| *|B| * Cos(theta)
	// theta =ArcCos( A.B/|AB|)
	vector3 temp(x,y,z);
	float theta = acos(dotProduct(change) / temp.magnitude());
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return (temp.magnitude() * change.magnitude() * cos(theta));
}
float vector3::magnitudeSqured() const 
{
	return x *x + y * y + z * z;
}
float vector3::dot(vector3 & other) const
{
	return x * other.x + y * other.y + z * other.z;
}
float vector3::getPart(int choice)
{
	switch (choice)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		return 0;
		break;
	}
}

vector3 vector3::getNormal()
{
	vector3 temp(x/magnitude(),y/magnitude(),z/magnitude());
	return temp;
}
vector3 vector3::crossProduct(vector3 change)
{
	vector3 temp(0,0,0);
	temp.x = ((y*change.z)-(z*change.y));
	temp.y = ((z*change.x)-(x*change.z));
	temp.z = ((x*change.y)-(y*change.x));
	return temp;
}
vector3 vector3::linearInterp(float alpha,vector3 change)
{
	//(1-alpha)Av + alphaBv
	alpha = 1- alpha;
	vector3 returnVector((this->x * alpha) + (change.x * alpha),(this->y * alpha) + (change.y * alpha),(this->z * alpha) + (change.z * alpha));
	return returnVector;
}

void vector3::normalise()
{
	x = x/magnitude();
	y = y/magnitude();
	z = z/magnitude();
}
void vector3::fill(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}








vector4::vector4(void)
{
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
vector4::vector4(float a,float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
vector4::vector4(char*r, char*b, char*g)
{
	for (int i = 0; i < 3; i++)
	{
		char * searchChar = "rb";
		float value = 0;

		if (i == 0)
			searchChar = r;
		else if (i == 1)
			searchChar = b;
		else if (i == 2)
			searchChar = g;

		switch(searchChar[0])
		{
		case 'a': case 'A':
			value += 160;
			break;
		case 'b': case 'B':
			value += 176;
			break;
		case 'c': case 'C':
			value += 192;
			break;
		case 'd': case 'D':
			value += 208;
			break;
		case 'e': case 'E':
			value += 224;
			break;
		case 'f': case 'F':
			value += 240;
			break;
		case '0':
			value += 0;
			break;
		case '1':
			value += 16;
			break;
		case '2':
			value += 32;
			break;
		case '3':
			value += 48;
			break;
		case '4':
			value += 64;
			break;
		case '5':
			value += 80;
			break;
		case '6':
			value += 96;
			break;
		case '7':
			value += 112;
			break;
		case '8':
			value += 128;
			break;
		case '9':
			value += 144;
			break;
		}switch(r[1])
		{
		case 'a': case 'A':
			value += 10;
			break;
		case 'b': case 'B':
			value += 11;
			break;
		case 'c': case 'C':
			value += 12;
			break;
		case 'd': case 'D':
			value += 13;
			break;
		case 'e': case 'E':
			value += 14;
			break;
		case 'f': case 'F':
			value += 15;
			break;
		case '0':
			value += 0;
			break;
		case '1':
			value += 1;
			break;
		case '2':
			value += 2;
			break;
		case '3':
			value += 3;
			break;
		case '4':
			value += 4;
			break;
		case '5':
			value += 5;
			break;
		case '6':
			value += 6;
			break;
		case '7':
			value += 7;
			break;
		case '8':
			value += 8;
			break;
		case '9':
			value += 9;
			break;
		}

		if (i == 0)
			this->a = value;
		else if (i == 1)
			this->b = value;
		else if (i == 2)
			this->c = value;
	}
}
void vector4::operator <<(vector4 change)
{
	a = change.a;
	b = change.b;
	c = change.c;
	d = change.d;
}
void vector4::set(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
void vector4::setPart(int i,float change)
{
	switch(i)
	{
	case 0:
		a = change;
		break;
	case 1:
		b = change;
		break;
	case 2:
		c = change;
		break;
	default:
		d = change;
		break;
	}
}
void vector4::normalise()
{
	a = a/magnitude();
	b = b/magnitude();
	c = c/magnitude();
	d = d/magnitude();
}
float vector4::getPart(int change)
{
	switch(change)
	{
	case 0:
		return a;
	case 1:
		return b;
	case 2:
		return c;
	case 3:
		return d;
	default:
		return d;
	}
}
float vector4::magnitude()
{
	return (float)sqrt((pow((double)a,2) + pow((double)b,2)+ pow((double)c,2)+ pow((double)d,2)));
}








//<summary>Matrix//</summary>

Matrix::Matrix(void)
{
	for (int i = 0; i < 4; i++)
	{
		line[i].a = 0;
		line[i].b = 0;
		line[i].c = 0;
		line[i].d = 0;
	}
}
Matrix::Matrix(vector4 change,int size)
{
this->size = size;
	for (int i = 0; i < 4; i++)
	{
		line[i] << change;
	}
}
Matrix::Matrix(vector4 changeOne,vector4 changeTwo,vector4 changeThree)
{
	size = 3;
	line[1] = changeOne;
	line[2] = changeTwo;
	line[3] = changeThree;
}
Matrix::Matrix(vector4 changeOne,vector4 changeTwo,vector4 changeThree,vector4 changeFour)
{
	size = 4;
	line[1] = changeOne;
	line[2] = changeTwo;
	line[3] = changeThree;
	line[4] = changeFour;
}

void Matrix::operator += (Matrix change)
{
	for(int i = 0; i < size; i++)
	{
		vector4 tempLine(line[i].a + change.line[i].a,line[i].b + change.line[i].b,line[i].c + change.line[i].c,line[i].d + change.line[i].d);
		line[i] << tempLine;
	}
}
void Matrix::operator -= (Matrix change)
{
	for(int i = 0; i < size; i++)
	{
		vector4 tempLine(line[i].a - change.line[i].a,line[i].b - change.line[i].b,line[i].c - change.line[i].c,line[i].d - change.line[i].d);
		line[i] << tempLine;
	}
}
void Matrix::operator *= (Matrix change)
{
	if (change.size != size)
	{
		Matrix tempMatrix;
		vector4 tempLine;
		if (size == 4)
		{
			for(int i = 0; i < 4; i++)
			{
			tempLine.a = (( line[i].a * change.line[0].a) + (line[i].b * change.line[1].a) + (line[i].c * change.line[2].a) + (line[i].d * change.line[3].a));
			tempLine.b = (( line[i].a * change.line[0].b) + (line[i].b * change.line[1].b) + (line[i].c * change.line[2].b) + (line[i].d * change.line[3].b));
			tempLine.c = (( line[i].a * change.line[0].c) + (line[i].b * change.line[1].c) + (line[i].c * change.line[2].c) + (line[i].d * change.line[3].c));
			tempLine.d = (( line[i].a * change.line[0].d) + (line[i].b * change.line[1].d) + (line[i].c * change.line[2].d) + (line[i].d * change.line[3].d));
			tempMatrix.line[i] << tempLine;
			}
		}
		else
		{
			for(int i = 0; i < 3; i++)
			{
			tempLine.a = (( line[i].a * change.line[0].a) + (line[i].b * change.line[1].a) + (line[i].c * change.line[2].a));
			tempLine.b = (( line[i].a * change.line[0].b) + (line[i].b * change.line[1].b) + (line[i].c * change.line[2].b));
			tempLine.c = (( line[i].a * change.line[0].c) + (line[i].b * change.line[1].c) + (line[i].c * change.line[2].c));
			tempMatrix.line[i] << tempLine;
			}
		}
	}
	else
	{
		//If sizes do not match
		this->setZero();
	}

}

void Matrix::setMatrix(Matrix change)
{
	line[0] << change.line[0];
	line[1] << change.line[1];
	line[2] << change.line[2];
	line[3] << change.line[3];
}
void Matrix::setIdentity()
{
	for (int i = 0; i < 4; i++)
	{
		line[i].a = 0;
		line[i].b = 0;
		line[i].c = 0;
		line[i].d = 0;
	}
	line[1].a = 1;
	line[2].b = 1;
	line[3].c = 1;
	line[4].d = 1;
}
void Matrix::setZero()
{
	for (int i = 0; i < 4; i++)
	{
		line[i].a = 0;
		line[i].b = 0;
		line[i].c = 0;
		line[i].d = 0;
	}
}
void Matrix::transpose()
{
	Matrix temp;
	vector4 tempLine;
	for (int i = 0; i < size; i++)
	{
		tempLine.a = line[1].getPart(i);
		tempLine.b = line[2].getPart(i);
		tempLine.c = line[3].getPart(i);
		tempLine.d = line[4].getPart(i);

		temp.line[i] << tempLine;
	}
	this->setMatrix(temp);
}
void Matrix::scaleThis(float scaler)
{
	for (int i = 0; i < size; i++)
	{
		vector4 tempLine(line[i].a * scaler,line[i].b * scaler,line[i].c * scaler,line[i].d * scaler);
		line[i] << tempLine;
	}
}
void Matrix::transformP(vector3 point)
{
	Matrix temp(line[0],line[1],line[2],line[3]);
	
	for (int i = 0; i < 3; i++)
	{
		temp.line[i].a *= point.x;
		temp.line[i].b *= point.y;
		temp.line[i].c *= point.z;
	}

}
void Matrix::transformP(vector4 point)
{
	Matrix temp(line[0],line[1],line[2],line[3]);
	
	for (int i = 0; i < 3; i++)
	{
		temp.line[i].a *= point.a;
		temp.line[i].b *= point.b;
		temp.line[i].c *= point.c;
		temp.line[i].d *= point.d;
	}
}
void Matrix::transformV(vector3 change)
{
	if (size == 3)
	{
		for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			line[ii].setPart(i,change.getPart(ii) * line[ii].getPart(i));
	}
}
void Matrix::transformV(vector4 change)
{
	if (size == 4)
	{
		for (int i = 0; i < 4; i++)
		for (int ii = 0; ii < 4; ii++)
			line[ii].setPart(i,change.getPart(ii) * line[ii].getPart(i));
	}
}

Matrix Matrix::rotate(char axis, float angle)
{
	Matrix temp(line[0],line[1],line[2],line[3]);
	switch(axis)
	{
	case 'x': case 'X':
		temp.line[0].set(1				,0				,0				,0);
		temp.line[1].set(0				,cos(angle)		,-sin(angle)	,0);
		temp.line[1].set(0				,sin(angle)		,cos(angle)		,0);
		temp.line[1].set(0				,0				,0				,1);
		break;
	case 'y': case 'Y':
		temp.line[0].set(cos(angle)		,0				,sin(angle)		,0);
		temp.line[1].set(0				,1				,0				,0);
		temp.line[1].set(-sin(angle)	,0				,cos(angle)		,0);
		temp.line[1].set(0				,0				,0				,1);
		break;
	case 'z': case 'Z':
		temp.line[0].set(cos(angle)		,-sin(angle)	,0		,0);
		temp.line[1].set(-sin(angle)	,cos(angle)		,0		,0);
		temp.line[1].set(0				,0				,1		,0);
		temp.line[1].set(0				,0				,0		,1);
		break;
	}
	Matrix returnM(line[0],line[1],line[2],line[3]);
	returnM *= temp;
	return returnM ;//*= temp);
}
Matrix Matrix::createScale(float scaler)
{
	Matrix tempMatrix;
	for (int i = 0; i < size; i++)
	{
		vector4 tempLine(line[i].a * scaler,line[i].b * scaler,line[i].c * scaler,line[i].d * scaler);
		tempMatrix.line[i] << tempLine;
	}
	return tempMatrix;
}
Matrix Matrix::createOrthographic(float left,float  right,float  bottom,float  top,float  near,float  far)
{
	vector4 emptyLine(0,0,0,0);
	Matrix orthographic(emptyLine,4);
	orthographic.line[0].a = 2/(right-left);
	orthographic.line[1].b = 2/(top-bottom);
	orthographic.line[2].c = -2/(far-near);
	
	orthographic.line[0].d = -(right + left)/(right-left);
	orthographic.line[1].d = -(top + bottom)/(top-bottom);
	orthographic.line[2].d = -(far + near)/(far-near);
	orthographic.line[3].d = 1;
	Matrix returnMatrix(line[0],line[1],line[2],line[3]);
	returnMatrix *= orthographic;

	return returnMatrix;
	

}












void convertRtD(float & change)
{
	change = ((change * 180)/3.14159f);
}
void convertDtR(float & change)
{
	change = ((change * 3.14159f)/180);
}

bool closestPowTwo(float & value)
{
	if (value <= 0)
		return 0;
	std::map<int,float> powOfTwo;
	std::map<int,float> powOfTwoDeduct;
	for(float i = 0; i < 15; i++)
	{
		if (value == powf(2,i))
			return true;
			//return powf(2,i);
		else
		{
			powOfTwo[(int)i] = powf(2,i);
		//cout << powf(2,i) << endl;
		}
	}
	typedef std::map<int,float>::iterator it_type;
	for(it_type iterator = powOfTwo.begin(); iterator != powOfTwo.end(); iterator++)
	{
		powOfTwoDeduct[iterator->first] = (value - iterator->second);
		if (powOfTwoDeduct[iterator->first] < 0)
			powOfTwoDeduct[iterator->first] *= -1;
	}
	int lowestPow = 0;
	float lowestValue = 1000;
	for(it_type iterator = powOfTwoDeduct.begin(); iterator != powOfTwoDeduct.end(); iterator++)
	{
		if (iterator->second < lowestValue)
		{
			lowestPow = iterator->first;
			lowestValue = iterator->second;
		}
	}
	value = lowestValue;
	return true;

}
#pragma once
#include "Characters.h"
#include "VectorLib.h"
#include <vector>
#include "glut.h"
#include <string>

using namespace std;

class Text
{
public:

	//Var
	vector2 position = vector2(0, 0);
	vector3 color = vector3(0, 0, 0);
	float deathTime = 0;
	int number;
	GLuint texture;
	Text();
	~Text();

	void display();
};

#pragma once

#include "VectorLib.h"
#include <iostream>
#include <map>
#include <vector>
#include "glut.h"
#include <gl/GL.h>
#include <gl\GLU.h>
#include "SOIL.h"
#include "Weapon.h"
#include <sstream>
#include <string>

using namespace std;


class Button
{
public:
	GLint texture;
	bool show;
	vector2 maxSize = vector2(0, 0);
	vector2 minSize = vector2(0, 0);
	vector2 position;
	vector2 drawSize;
	Button(void);
	~Button();
	virtual void updatePos(vector2 screen);
	virtual void draw();
	virtual bool load(char * file);
};
class Screens
{
public:
	GLint texture;
	bool show;
	vector<Button> buttons;
	Screens(void);
	~Screens();
	virtual void draw();
	virtual bool load(char * file);
};
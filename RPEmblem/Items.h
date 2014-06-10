#pragma once

#include "VectorLib.h"
#include <iostream>
#include <vector>
#include "glut.h"
#include <gl/GL.h>
#include <gl\GLU.h>
#include "SOIL.h"
#include <sstream>
#include <string>
#include "Characters.h"



class Items
{
public:
	bool alive;
	GLint texture;
	vector2 position;//The actual value between -2 and 2
	vector2 cord;//The cords on the grid
	Items();
	~Items();
	virtual void init(vector2 change);
	virtual void draw();
	virtual bool load();
	virtual bool load(char * file);
	virtual void effect(Characters*& character);
	virtual void update(vector2 playercord);
};
class HPickup :Items
{
public:
	virtual void init(vector2 change);
	virtual void draw();
	virtual bool load();
	virtual void effect(Characters*& character);
	virtual void update(vector2 playercord);
};
class HTrap :Items
{
public:
	virtual void init(vector2 change);
	virtual void draw();
	virtual bool load();
	virtual void effect(Characters*& character);
	virtual void update(vector2 playercord);
};
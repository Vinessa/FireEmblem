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

using namespace std;

class Land
{
public:
	GLuint	texture;
	float resistance;
	bool walkable;
	bool blueHighLight;
	bool redHighLight;
	bool normal; //Added by Vinessa for color blending.
	vector2 position;
	vector3 color = vector3(1,1,1);
	bool invertX = false;
	bool invertY = false;
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
	virtual bool load(int part);
	virtual Land * getBottom();
	virtual bool isBottom();
};
class Wall :Land
{
public:
	int health;
	Wall(void);
	~Wall();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
	virtual bool load(int part);
};
class House :Land
{
public:
	int health;
	House(void);
	~House();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
	virtual bool load(int part);
};
class Dirt :Land
{
public:
	Dirt(void);
	~Dirt();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
	virtual bool load(int part);
};

class Tree :Land
{
public:
	int health;
	Tree(void);
	~Tree();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
};

class Grass :Land
{
public:
	int health;
	Grass(void);
	~Grass();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
};

class Water :Land
{
public:
	int health;
	Water(void);
	~Water();
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
};

class Selection :Land
{
public:
	Land * belowContent;
	vector2 cord = vector2(0, 0);
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
	bool load(vector2 change,vector2 screen);
	virtual bool load(int part);
	virtual Land * getBottom();
	virtual bool isBottom();
};
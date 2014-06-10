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

class Land
{
public:
	GLuint	texture;
	float resistance;
	bool walkable;
	bool blueHighLight;
	bool redHighLight;
	vector2 position;
	void init();
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
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
};
class Selection :Land
{
public:
	Land * belowContent;
	virtual void draw();
	virtual void draw(bool triggerColors);
	virtual bool load();
};
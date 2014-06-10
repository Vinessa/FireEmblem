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
#include "Land.h"

using namespace std;

class Characters
{
public:
	int health;
	int maxHealth;
	float xp;
	float xp2NextLevel; // Added by Vinessa - xp to next level - scales xp requirements to characters progression
	int Level; //Added by Vinessa
	bool alive;
	bool waiting;
	bool isEnemy = false;
	GLint texture;
	vector2 position;//The actual value between -2 and 2
	vector2 cord;//The cords on the grid
	std::string name;
	Weapon * weapon;
	float mvmP = 100;
	int turnOrder;
	vector<Characters*> adjecentArray;
	Characters(void);
	Characters(Characters* newChar);
	virtual void init(vector2 change, string newName);
	virtual void draw();
	virtual bool load();
	virtual bool loadAsEnemy();
	virtual void updatePos(vector2 newCord);
	virtual bool calculateCost(Land* node, int /*5*/ dist, vector2 newCord);
	virtual vector<Characters*> getAdj(map<int, Characters*> characters);
	//Gets the land next to the land you are currently on
	virtual bool calculateAtLand(Land* node, int /*5*/ dist, vector2 newCord);
};
class HeavyMace : Characters
{
public:
	HeavyMace(void);
	//private:
	virtual void init(vector2 change, string newName);
	virtual bool load();
	virtual bool loadAsEnemy();
};
class Swordsman : Characters
{
public:
	Swordsman(void);
	virtual void init(vector2 change, string newName);
	virtual bool load();
	virtual bool loadAsEnemy();
};
class Axeman : Characters
{
public:
	Axeman(void);
	virtual void init(vector2 change, string newName);
	virtual bool load();
	virtual bool loadAsEnemy();
};
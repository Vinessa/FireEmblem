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
#include "Land.h"
#include "Characters.h"
#include "Items.h"
#include "Screens.h"
#include "Attacks.h"
#include "XmlLoader.h"

using namespace std;


class Grid
{
public:
	Grid();
	~Grid();
	vector2 screen;//Screen size
	vector2 selectedNode;//The cords for the selected node
	map<unsigned char, bool> keyState;//State of each key
	map<int, Characters*> playable;//List of all the character player
	map<int, Characters*> unplayable;//List of all the non-character players
	vector<vector<Land*>> nodes;//Each tile
	vector<Items*> items;
	PlayCard card;
	Selection sel;//The selected tile
	Characters * selCharacter;//The selected character
	XmlLoader xml;
	Screens scr;
	enum STATE { SPLASH, MENU, GAME, EXIT, OPTIONS };//Game states
	STATE curr;//The current state
	float updateHalt = 0;
	int maxTurns = 6;
	bool move;
	bool paused;
	bool filling;
	//bool click = false;
	int turn;//Controls who can act and who cannot
	//HPickup hPick;

	void init(int x/*18*/, int y/*18*/);
	void draw(vector2 screen);
	void update();
};
//#endif
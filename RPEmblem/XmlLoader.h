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
#include <tinyxml.h>
#include <tinystr.h>
#include <sstream>
#include <string>
#include "Land.h"
#include "Characters.h"

using namespace std;

class PlayCard
{
public:
	GLint texture;
	Characters * sel;
	Characters * opSel;
	Land * selLand;
	Land * opselLand;
	bool showOpSel;
	PlayCard(void);
	~PlayCard();
	virtual void draw();
	virtual bool load();
};

class XmlLoader
{
public:
	XmlLoader();
	~XmlLoader();
	// Loads from an XML file all of a lvls data
	void loadElement(vector<Land*> & landNodes, TiXmlElement * node, int i);
	void loadNodes(vector<vector<Land*>> & landNodes, int lvl);
};
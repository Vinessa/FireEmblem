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
#include <iostream>
#include <sstream>

using namespace std;

class Land
{
public:
	GLuint	texture;
	float resistance;
	bool walkable;
	bool blueHighLight;
	bool redHighLight;
	vector2 position;
	void init()
	{}
	virtual void draw()
	{}
	virtual void draw(bool triggerColors)
	{}
	virtual bool load()
	{
		return false;
	}
};
class Wall :Land
{
public:
	int health;
	Wall(void){}
	~Wall(){}
	void init()
	{
		resistance = 100000;
		health = 10;
		redHighLight = true;
		blueHighLight = false;
	}
	virtual void draw()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1,0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
		//glColor3f(0, 0, 1);
		glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
		//glColor3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
	}
	virtual void draw(bool triggerColors)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		vector3 color(1, 1, 1);
		//if (redHighLight)
		//	color = vector3(1, 0.2, 0.2);
		//if (blueHighLight)
		//	color = vector3(0.2, 0.2, 1);
		glColor3f(color.x, color.y, color.z);
		glTexCoord2f(0, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
		//glColor3f(0, 0, 1);
		glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
		//glColor3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"wall.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
}; 
class Dirt :Land
{
public:
	Dirt(void)
	{}
	~Dirt(){}
	void init()
	{
		resistance = 20;
		redHighLight = true;
		blueHighLight = false;
	}
	virtual void draw()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1,0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
		//glColor3f(0, 0, 1);
		glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
		//glColor3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
	}
	virtual void draw(bool triggerColors)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		vector3 color(1, 1, 1);
		if (redHighLight)
			color = vector3(1, 0.2, 0.2);
		if (blueHighLight)
			color = vector3(0.2, 0.2, 1);
		glColor3f(color.x,color.y,color.z);
		glTexCoord2f(0, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
		//glColor3f(0, 0, 1);
		glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
		//glColor3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"dirt.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			//throw std::bad_exception("Failure to load image");
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};
class Selection :Land
{
public:
	Land * belowContent;
	virtual void draw()
	{
		resistance = belowContent->resistance;
		belowContent->draw();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(belowContent->position.x - 1, belowContent->position.y + 0.11 - 1, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(0, 1); glVertex3f(belowContent->position.x - 1.11, belowContent->position.y + 0.11 - 1, 0);
		//glColor3f(0, 0, 1);
		glTexCoord2f(1, 1); glVertex3f(belowContent->position.x - 1.11, belowContent->position.y - 1, 0);
		//glColor3f(0, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(belowContent->position.x - 1, belowContent->position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
		//belowContent->draw();
	}
	virtual void draw(bool triggerColors)
	{
		resistance = belowContent->resistance;
		draw();
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"select.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};
class Characters
{
public:
	int health;
	int maxHealth;
	float xp;
	GLint texture;
	map<vector2,Land*> pathTaken;
	vector2 position;//The actual value between -2 and 2
	vector2 cord;//The cords on the grid
	std::string name;
	Weapon * weapon;
	float mvmP = 100;
	int turnOrder;
	int carryDistance = 100;//5 tiles of dirt

	virtual void init(vector2 change, string newName)
	{
		health = 1;
		cord = change;

		position.x = (0.11) * cord.x + (0.11);
		position.y = (0.11) * cord.y;

		name = newName;
		load();
		//weapon->type();
		//Initialize weapon here
	}
	virtual void draw()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		//glRotatef(90, 0, 0, 1);
		glBegin(GL_QUADS);
		glPushMatrix();

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
		glTexCoord2f(1,0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
		glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
		glTexCoord2f(0,1); glVertex3f(position.x - 1, position.y - 1, 0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnd();
		//glRotatef(-90, 0, 0, 1);
	}
	virtual bool load()
	{
		return false;
	}
	virtual void updatePos(vector2 newCord)
	{
		cord = newCord;

		position.x = (0.11) * cord.x + (0.11);
		position.y = (0.11) * cord.y;
	}
	virtual bool calculateCost(Land* node, int /*5*/ dist, vector2 newCord)
	{
		int x = cord.x;
		int y = cord.y;
		bool rtV = false;
		if ((x == newCord.x) || (y == newCord.y))
			if ((x - dist <= newCord.x && x + dist >= newCord.x) && (y - dist <= newCord.y && y + dist >= newCord.y))
			{
				if (mvmP - node->resistance >= 0)
					return true;
			}
			else return false;
			return false;
			//return rtV;
	}
	//Gets the land next to the land you are currently on
	virtual bool calculateAtLand(Land* node, int /*5*/ dist, vector2 newCord)
	{
		int x = cord.x;
		int y = cord.y;

		if ((y == newCord.y && (x - dist - 1 == newCord.x)) || (y == newCord.y && (x + dist + 1 == newCord.x)))// || (x == newCord.x && (y - dist == newCord.y)))
			return true;

		if ((x == newCord.x && (y - dist - 1 == newCord.y)) || (x == newCord.x && (y + dist + 1 == newCord.y)))// || (y == newCord.y && (x - dist == newCord.x)))
			return true;

		if ((x == newCord.x - 1 || x == newCord.x + 1) || (y == newCord.y - 1 || y == newCord.y + 1))
			if ((x - dist <= newCord.x && x + dist >= newCord.x) && (y - dist <= newCord.y && y + dist >= newCord.y))
			{
				if (mvmP - node->resistance >= 0)
					return true;
			}
			else return false;
			return false;
			//return rtV;
	}
};
class HeavyMace : Characters
{
	virtual void init(vector2 change, string newName)
	{
		turnOrder = 1;
		health = 10;
		cord = change;

		position.x = (0.11) * cord.x + (0.11);
		position.y = (0.11) * cord.y;
		name = newName;
		load();

		weapon = (Weapon*)new MACE(20);
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"rock.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};
class Swordsman : Characters
{
	virtual void init(vector2 change, string newName)
	{
		turnOrder = 2;
		health = 10;
		cord = change;

		position.x = (0.11) * cord.x + (0.11);
		position.y = (0.11) * cord.y;
		name = newName;
		load();

		weapon = (Weapon*)new SWORD(20);
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"Paper.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};
class Axeman : Characters
{
	virtual void init(vector2 change, string newName)
	{
		turnOrder = 3;
		health = 10;
		cord = change;

		position.x = (0.11) * cord.x + (0.11);
		position.y = (0.11) * cord.y;
		name = newName;
		load();

		weapon = (Weapon*)new AXE(20);
	}

	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"emblem.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};


class PlayCard
{
public:
	GLint texture;
	Characters * sel;
	Characters * opSel;
	bool showOpSel;
	PlayCard(void)
	{
		showOpSel = false;
	}
	~PlayCard(){}
	virtual void draw()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glPushMatrix();

		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(0.5f, 1, 0);
		glTexCoord2f(1, 0); glVertex3f(1, 1, 0);
		glTexCoord2f(1, 1); glVertex3f(1, 0.75f, 0);
		glTexCoord2f(0, 1); glVertex3f(0.5f, 0.75f, 0);
		glPopMatrix();
		glEnd();
		
		
		glBindTexture(GL_TEXTURE_2D, sel->texture);
		glBegin(GL_QUADS);
		glPushMatrix();
		//glRotatef(90, 1, 0, 0);

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(0.51f, 0.99, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1, 0); glVertex3f(0.76, 0.99, 0);
		glTexCoord2f(1, 1); glVertex3f(0.76, 0.76f, 0);
		glTexCoord2f(0, 1); glVertex3f(0.51f, 0.76f, 0);
		glPopMatrix();
		glEnd();
		
		if (showOpSel)
		{
			glBindTexture(GL_TEXTURE_2D, opSel->texture);
			glBegin(GL_QUADS);
			glPushMatrix();
			//glRotatef(90, 1, 0, 0);

			//glColor3f(1, 0, 0);
			glLoadIdentity();
			glColor3f(1, 1, 1);
			glTexCoord2f(0, 0); glVertex3f(0.76f, 0.99, 0);
			//glColor3f(0, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(0.99, 0.99, 0);
			glTexCoord2f(1, 1); glVertex3f(0.99, 0.76f, 0);
			glTexCoord2f(0, 1); glVertex3f(0.76f, 0.76f, 0);
			glPopMatrix();
			glEnd();
		}
		glDisable(GL_TEXTURE_2D);
	}
	virtual bool load()
	{
		texture = SOIL_load_OGL_texture
			(
			"card.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (texture == 0)
			//throw std::bad_exception("Failure to load image");
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;
	}
};

class XmlLoader
{
public:
	XmlLoader(){}
	~XmlLoader(){}
	// Loads from an XML file all of a lvls data
	void loadElement(vector<Land*> & landNodes,TiXmlElement * node,int i)
	{
		std::stringstream yTemp;
		std::stringstream typeTemp;
		string type;
		int y = 0;
		yTemp << node->Attribute("name");
		yTemp >> y;
		typeTemp << node->Attribute("type");
		typeTemp >> type;
		if (type == "Wall")
		{
			Wall * nWall = new Wall;
			nWall->init();
			landNodes.at(y) = (Land*)nWall;
		}
		else if (type == "Dirt")
		{

			Dirt * nDirt = new Dirt();
			nDirt->init();
			landNodes.at(y) = (Land*)nDirt;
		}
		int bob = 5;
		landNodes.at(y)->load();
		landNodes.at(y)->position.x = (0.11) * i + (0.11);

		landNodes.at(y)->position.y = (0.11) * y;
		landNodes.at(y);
	}
	void loadNodes(vector<vector<Land*>> & landNodes, int lvl)
	{
		TiXmlDocument doc("LevelData.xml");
		vector<vector<Land*>> newNode = vector<vector<Land*>>(18);

		if (doc.LoadFile()){
			//return 1;

			// aquires atlas node
			TiXmlNode * atlas = doc.FirstChild("game");

			//atlas = atlas->FirstChild("Row");
			// gets the child node Row
			TiXmlNode* tile = atlas->FirstChildElement();
			//atlas
			TiXmlElement * tileElement = tile->ToElement();

			for (int i = 0; i < 18; i++)
			{
				vector<Land*> newSubNode = vector<Land*>(18);
				TiXmlNode* subTile = tile->FirstChildElement();
				for (int ii = 0; ii < 18; ii++)
				{
					TiXmlElement * subTileElement = subTile->ToElement();
					loadElement(newSubNode, subTileElement, i);
					subTile = subTile->NextSiblingElement();
				}
				if (i != 17)
				{
					tile = tile->NextSiblingElement();
					tileElement = tile->ToElement();
				}
				newNode.at(i) = newSubNode;
			}
		}
		//Character character(Sprite2);
		//for (int 18)
		//Sprite1 = Sprite1->NextSiblingElement();
		//Sprite2 = Sprite1->ToElement();
		/*
		for (int i = 0; i < 18; i++)
		{
			vector<Land*> newSubNode = vector<Land*>(18);
			for (int ii = 0; ii < 18; ii++)
			{
				if (ii == 0 || ii == 18 - 1 || i == 0 || i == 18 - 1)
				{

					Wall * nWall = new Wall;
					nWall->init();
					//newDirt.object = nDirt;
					newSubNode.at(ii) = (Land*)nWall;
				}
				else
				{
					Dirt * nDirt = new Dirt();
					nDirt->init();
					//newDirt.object = nDirt;
					newSubNode.at(ii) = (Land*)nDirt;
				}
				newSubNode.at(ii)->load();
				newSubNode.at(ii)->position.x = (0.11) * i + (0.11);

				newSubNode.at(ii)->position.y = (0.11) * ii;

				//(((12.5 * breadth)) - ((ii + countx) * breadth)) + ((breadth * 5)*i);
				//0, (((12.5 * breadth)) - (countz * breadth)) + (breadth*i);
			}
			newNode.at(i) = newSubNode;
		}*/
		landNodes = newNode;
	}
};
class Grid
{
public:
	Grid();
	~Grid();
public:
	vector2 screen;//Screen size
	vector2 selectedNode;//The cords for the selected node
	map<unsigned char, bool> keyState;//State of each key
	map<int, Characters*> playable;//List of all the character player
	map<int, Characters*> unplayable;//List of all the non-character players
	vector<vector<Land*>> nodes;//Each tile
	PlayCard card;
	Selection sel;//The selected tile
	Characters * selCharacter;//The selected character
	enum STATE { SPLASH, MENU, GAME, EXIT, OPTIONS };//Game states
	STATE curr;//The current state
	bool move;
	int turn;//Controls who can act and who cannot
	XmlLoader xml;
	
	void init(int x/*18*/, int y/*18*/)
	{
		turn = 1;
		playable[1] = (Characters*)new HeavyMace;
		playable[2] = (Characters*)new Swordsman;
		playable[3] = (Characters*)new Axeman;
		playable[1]->init(vector2(9,9),"HeavyMace");
		playable[2]->init(vector2(9, 12), "Swordsman");
		playable[3]->init(vector2(12, 9), "Axeman");
		selectedNode = vector2(-1, -1);
		//sel.init();
		sel.load();
		card.load();
		card.sel = (Characters*)playable[1];
		/*vector<vector<Land*>> newNode = vector<vector<Land*>>(18);
		for (int i = 0; i < x; i++)
		{
			vector<Land*> newSubNode = vector<Land*>(18);
			for (int ii = 0; ii < y; ii++)
			{
				if (ii == 0 || ii == y-1 || i == 0 || i == x-1)
				{

					Wall * nWall = new Wall;
					nWall->init();
					//newDirt.object = nDirt;
					newSubNode.at(ii) = (Land*)nWall;
				}
				else
				{
					Dirt * nDirt = new Dirt();
					nDirt->init();
					//newDirt.object = nDirt;
					newSubNode.at(ii) = (Land*)nDirt;
				}
				newSubNode.at(ii)->load();
				newSubNode.at(ii)->position.x = (0.11) * i + (0.11);

				newSubNode.at(ii)->position.y = (0.11) * ii;

				//(((12.5 * breadth)) - ((ii + countx) * breadth)) + ((breadth * 5)*i);
				//0, (((12.5 * breadth)) - (countz * breadth)) + (breadth*i);
			}
			newNode.at(i) = newSubNode;
		}
		nodes = newNode;*/
		xml.loadNodes(nodes, 1);
	}
	void draw()
	{
		//drawSquare(vector2(0,0));
		//int x = 0,y = 0;
		//for (auto & i : nodes)

		//vector<vector<Land*>>::iterator i;
		//vector<Land*>::iterator ii;
		/*int testturn = 4 - turn;
		testturn--;
		if (testturn < 1)
			testturn = 3;*/
		for (int i = 0; i < 18; i++) {
			for (int ii = 0; ii < 18; ii++) {
				if (turn <= 3)
				{
					/*int checkturn = turn + 1;
					if (checkturn > 3)
						checkturn = 3;
					if (checkturn == 2)
						checkturn--;*/
					//if (playable[turn]->cord.checkSpace(vector2(i, ii), 5))
					if (playable[turn]->calculateCost(nodes[i][ii],4,vector2(i,ii)))
					{
						nodes[i][ii]->blueHighLight = true;
						nodes[i][ii]->redHighLight = false;
					}
					else if (playable[turn]->calculateAtLand(nodes[i][ii], 4, vector2(i,ii)))
					{
						nodes[i][ii]->blueHighLight = false;
						nodes[i][ii]->redHighLight = true;
					}
					else
					{
						nodes[i][ii]->blueHighLight = false;
						nodes[i][ii]->redHighLight = false;
					}
					nodes[i][ii]->draw(true);
				}
				else
					nodes[i][ii]->draw();
				
				/*if (Dirt * p = dynamic_cast<Dirt*>(ii))
				{

				}
				y++;
				if (ii->resistance > 100 || (y == selectedNode.y && x == selectedNode.x))
					drawWall(ii->position);
				else
				{
					drawSquare(ii->position);
				}*/
			}
		}

		playable[1]->draw();
		playable[2]->draw();
		playable[3]->draw();
		card.draw();
		
	}
	void drawSquare(vector2 pos)
	{
		
		glBegin(GL_QUADS);
		glPushMatrix();

		glColor3f(1, 0, 0);
		glVertex3f(pos.x - 1, pos.y + 0.11 - 1, 0);
		glColor3f(0, 1, 0);
		glVertex3f(pos.x - 1.11, pos.y + 0.11 - 1, 0);
		glColor3f(0, 0, 1);
		glVertex3f(pos.x - 1.11, pos.y - 1, 0);
		glColor3f(0, 0, 0);
		glVertex3f(pos.x - 1, pos.y - 1, 0);
		glPopMatrix();
		glEnd();

	}void drawWall(vector2 pos)
	{
		glBegin(GL_QUADS);
		glPushMatrix();

		glColor3f(0, 0, 0);
		glVertex3f(pos.x - 1, pos.y + 0.11 - 1, 0);
		glVertex3f(pos.x - 1.11, pos.y + 0.11 - 1, 0);
		glVertex3f(pos.x - 1.11, pos.y - 1, 0);
		glVertex3f(pos.x - 1, pos.y - 1, 0);
		glPopMatrix();
		glEnd();

	}
	void update()
	{
		//if (selectedNode != vector2(-1,-1))
		for (map<int, Characters*>::iterator it = playable.begin(); it != playable.end();it++)
		{
			if (turn == it->second->turnOrder)
			{
				card.sel = (Characters*)it->second;
				if (move && playable[turn]->calculateCost(nodes[selectedNode.x][selectedNode.y], 4, selectedNode))
				{
					for (map<int, Characters*>::iterator itt = playable.begin(); itt != playable.end();itt++)
					{
						if (itt->second->cord == selectedNode)
						{
							move = false;
						}
					}
					/*for (map<int, Characters*>::iterator itt = unplayable.begin(); itt != unplayable.end(); itt++)
					{
						if (itt->second->cord == selectedNode)
						{
							move = false;
						}
					}*/
					if (move)
					{
						it->second->updatePos(selectedNode);
						turn++;
						move = false;
					}
					selectedNode = vector2(-1, -1);
				}
				else if (move)
					move = false;
			}
			if (selectedNode == it->second->cord)
			{
				selCharacter = (Characters*)it->second;
				card.opSel = (Characters*)selCharacter;
				card.showOpSel = true;
			}
			else if (selectedNode == vector2(-1,-1))
			{
				card.showOpSel = false;
				selCharacter = (Characters*)new Characters;
			}
			else
			{
				//card.showOpSel = false;
				selCharacter = (Characters*)new Characters;
			}
		}
		if (turn > 3)
			turn = 1;
	}
};


#include "stdafx.h"
#include "XmlLoader.h"

PlayCard::PlayCard(void)
{
	showOpSel = false;
}
PlayCard::~PlayCard(){
}
void PlayCard::draw()
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

	glBindTexture(GL_TEXTURE_2D, selLand->texture);
	glBegin(GL_QUADS);
	glPushMatrix();
	//glRotatef(90, 1, 0, 0);

	//glColor3f(1, 0, 0);
	glLoadIdentity();
	glColor3f(selLand->color.x, selLand->color.y, selLand->color.z);
	glTexCoord2f(0, 0); glVertex3f(0.51f, 0.99, 0);
	//glColor3f(0, 1, 0);
	glTexCoord2f(1, 0); glVertex3f(0.76, 0.99, 0);
	glTexCoord2f(1, 1); glVertex3f(0.76, 0.76f, 0);
	glTexCoord2f(0, 1); glVertex3f(0.51f, 0.76f, 0);
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
		glBindTexture(GL_TEXTURE_2D, opselLand->getBottom()->texture);
		glBegin(GL_QUADS);
		glPushMatrix();
		//glRotatef(90, 1, 0, 0);

		//glColor3f(1, 0, 0);
		glLoadIdentity();
		glColor3f(opselLand->getBottom()->color.x, opselLand->getBottom()->color.y, opselLand->getBottom()->color.z);
		glTexCoord2f(0, 0); glVertex3f(0.76f, 0.99, 0);
		//glColor3f(0, 1, 0);
		glTexCoord2f(1, 0); glVertex3f(0.99, 0.99, 0);
		glTexCoord2f(1, 1); glVertex3f(0.99, 0.76f, 0);
		glTexCoord2f(0, 1); glVertex3f(0.76f, 0.76f, 0);
		glPopMatrix();
		glEnd();
	
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

	glBindTexture(GL_TEXTURE_2D, instTexture);
	glBegin(GL_QUADS);
	glPushMatrix();
	//glRotatef(90, 1, 0, 0);

	//glColor3f(1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0,0); glVertex3f(-1, -0.25, 0);
	glTexCoord2f(1, 0); glVertex3f(-0.25, -0.25, 0);
	glTexCoord2f(1,1); glVertex3f(-0.25, -1, 0);
	glTexCoord2f(0, 1); glVertex3f(-1, -1, 0);
	glPopMatrix();
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
bool PlayCard::load()
{
	texture = SOIL_load_OGL_texture
		(
		"card.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,0
		/*SOIL_FLAG_INVERT_Y*/
		);

	instTexture = SOIL_load_OGL_texture
		(
		"Instructions_Overlay.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
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

XmlLoader::XmlLoader(){}
XmlLoader::~XmlLoader(){}
// Loads from an XML file all of a lvls data
void XmlLoader::loadElement(vector<Land*> & landNodes, TiXmlElement * node, int i)
{
	std::stringstream yTemp;
	std::stringstream typeTemp;
	std::stringstream sideTemp;
	string type;
	string side;
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
		landNodes.at(y)->load();
	}
	else if (type == "Dirt")
	{
		Dirt * nDirt = new Dirt();
		nDirt->init();
		landNodes.at(y) = (Land*)nDirt;
		landNodes.at(y)->load();
	}
	else if (type == "House")
	{
		sideTemp << node->Attribute("side");
		sideTemp >> side;

		House * nDirt = new House();
		nDirt->init();
		landNodes.at(y) = (Land*)nDirt;
		landNodes.at(y)->load(std::stoi(side));
	}
	else if (type == "Water")
	{
		Water * nWater = new Water();
		nWater->init();
		landNodes.at(y) = (Land*)nWater;
		landNodes.at(y)->load();
	}
	else if (type == "Grass")
	{
		Grass * nGrass = new Grass();
		nGrass->init();
		landNodes.at(y) = (Land*)nGrass;
		landNodes.at(y)->load();
	}
	else if (type == "Tree")
	{
		Tree * nTree = new Tree();
		nTree->init();
		landNodes.at(y) = (Land*)nTree;
		landNodes.at(y)->load();
	}
	landNodes.at(y)->position.x = (0.11) * i + (0.11);

	landNodes.at(y)->position.y = (0.11) * y;
	landNodes.at(y);
}
void XmlLoader::loadNodes(vector<vector<Land*>> & landNodes, int lvl)
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
	landNodes = newNode;
}
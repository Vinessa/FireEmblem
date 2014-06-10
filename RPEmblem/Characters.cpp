#include "stdafx.h"
#include "Characters.h"

Characters::Characters(void){}
Characters::Characters(Characters* newChar)
{
	health = newChar->health;
	maxHealth = newChar->maxHealth;
	xp = newChar->xp;
	Level = newChar->Level; // added by Vinessa
	xp2NextLevel = newChar->xp2NextLevel;
	alive = newChar->alive;
	waiting = newChar->waiting;
	texture = newChar->texture;
	position = newChar->position;//The actual value between -2 and 2
	cord = newChar->cord;//The cords on the grid
	name = newChar->name;
	weapon = newChar->weapon;
	mvmP = newChar->mvmP;
	turnOrder = newChar->turnOrder;
}
void Characters::init(vector2 change, string newName)
{
	alive = health > 0;
	waiting = false;
	health = 1;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;

	name = newName;
	load();
	//weapon->type();
	//Initialize weapon here
}
void Characters::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glRotatef(90, 0, 0, 1);
	glBegin(GL_QUADS);
	glPushMatrix();

	//glColor3f(1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
	//glRotatef(-90, 0, 0, 1);
}
bool Characters::load()
{
	return false;
}
bool Characters::loadAsEnemy()
{
	isEnemy = true;
	return false;
}
void Characters::updatePos(vector2 newCord)
{
	cord = newCord;

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
}
bool Characters::calculateCost(Land* node, int /*5*/ dist, vector2 newCord)
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
vector<Characters*> Characters::getAdj(map<int, Characters*> characters)
{
	adjecentArray = vector<Characters*>();
	for (auto & element : characters)
		if ((element.second->cord.x == cord.x || element.second->cord.x == cord.x - 1 || element.second->cord.x == cord.x + 1) &&
			(element.second->cord.y == cord.y || element.second->cord.y == cord.y - 1 || element.second->cord.y == cord.y + 1))
			adjecentArray.push_back(element.second);

	return adjecentArray;
}
//Gets the land next to the land you are currently on
bool Characters::calculateAtLand(Land* node, int /*5*/ dist, vector2 newCord)
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

HeavyMace::HeavyMace(void){}
//private:
void HeavyMace::init(vector2 change, string newName)
{
	alive = health > 0;
	waiting = false;
	turnOrder = 1;
	health = 10;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	name = newName;
	load();

	weapon = (Weapon*)new MACE(20);
}
bool HeavyMace::load()
{
	texture = SOIL_load_OGL_texture
		(
		"maceA.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}
bool HeavyMace::loadAsEnemy()
{
	isEnemy = true;
	texture = SOIL_load_OGL_texture
		(
		"maceE.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

Swordsman::Swordsman(void){}
void Swordsman::init(vector2 change, string newName)
{
	alive = health > 0;
	waiting = false;
	turnOrder = 2;
	health = 10;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	name = newName;
	load();

	weapon = (Weapon*)new SWORD(20);
}
bool Swordsman::load()
{
	texture = SOIL_load_OGL_texture
		(
		"swordA.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}
bool Swordsman::loadAsEnemy()
{
	isEnemy = true;
	texture = SOIL_load_OGL_texture
		(
		"swordE.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

Axeman::Axeman(void){}
void Axeman::init(vector2 change, string newName)
{
	alive = health > 0;
	waiting = false;
	turnOrder = 3;
	health = 10;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	name = newName;
	load();

	weapon = (Weapon*)new AXE(20);
}
bool Axeman::load()
{
	texture = SOIL_load_OGL_texture
		(
		"axeA.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}
bool Axeman::loadAsEnemy()
{
	isEnemy = true;
	texture = SOIL_load_OGL_texture
		(
		"axeE.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	if (texture == 0)
		return false;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}
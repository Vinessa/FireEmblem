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

	glLineWidth(2.5);
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	float healthleft;
	healthleft = maxHealth - health;
	healthleft = 0.01*health;
	glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glVertex3f(position.x - 1.11 + healthleft, position.y + 0.11 - 1, 0);
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
Characters* Characters::closestEnemy(map<int, Characters*> thePlayable)
{
	int bestCost = 100;
	int bestCostValue = 1;
	for (auto & element : thePlayable)
	{
		int currentCostX = 0;
		currentCostX = this->cord.x - element.second->cord.x;
		if (currentCostX < 0)
			currentCostX *= -1;

		int currentCostY = 0;
		currentCostY = this->cord.y - element.second->cord.y;
		if (currentCostY < 0)
			currentCostY *= -1;

		if (currentCostX + currentCostY <= bestCost)
		{
			bestCost = currentCostX + currentCostY;
			bestCostValue = element.first;
		}
	}
	return thePlayable[bestCostValue];
}
vector2 Characters::calculateWorth(vector2 target)
{
	int currentCostX = 0;
	currentCostX = this->cord.x - target.x;
	//if (currentCostX < 0)
		//currentCostX *= -1;

	int currentCostY = 0;
	currentCostY = this->cord.y - target.y;
	//if (currentCostY < 0)
		//currentCostY *= -1;

	if (abs(currentCostX) < abs(currentCostY))
	{
		if (currentCostX > 0)
			return vector2(1, 0);
		else
			return vector2(-1, 0);
	}
	else
	{
		if (currentCostY > 0)
			return vector2(1, 0);
		else
			return vector2(-1, 0);
	}
}
vector2 Characters::calculateDist(vector2 target, vector2 enemy, vector<vector<Land*>> land)
{
	int x = cord.x;
	int y = cord.y;
	if (target.x == 1)
	{
		//for (auto & element : land)
		while (x <= cord.x + 5)
		{
			try{
				if (land.at(x + 1).at(y)->walkable && enemy != vector2(x + 1, y) && enemy.x != x + 1)
					x++;
				else
				{
					return vector2(x, y);
				}
			}
			catch (std::out_of_range oor)
			{
				return vector2(x- 1, y);
			}
		}
		//land.at(cord.x).at(cord.y);
	}
	else if (target.x == -1)
	{
		try{
			while (x >= cord.x - 5)
			{
				if (land.at(x - 1).at(y)->walkable && enemy != vector2(x - 1, y) && enemy.x != x - 1)
					x--;
				else
				{
					return vector2(x + 1, y);
				}
			}
		}
		catch (std::out_of_range oor)
		{
			return vector2(x, y);
		}
	}

	else if (target.y == -1)
	{
		try {
			while (y >= cord.y - 5)
			{
				if (land.at(x).at(y - 1)->walkable && enemy != vector2(x, y - 1) && enemy.y != y - 1)
					y--;
				else
				{
					return vector2(x, y + 1);
				}
			}
		}
		catch (std::out_of_range oor)
		{
			return vector2(x, y);
		}
	}
	else
	{
		try
		{
			while (y <= cord.y + 5)
			{
				if (land.at(x).at(y + 1)->walkable && enemy != vector2(x, y + 1) && enemy.y != y + 1)
					y++;
				else
				{
					return vector2(x, y - 1);
				}
			}
		}
		catch (std::out_of_range oor)
		{
			return vector2(x, y);
		}
	}
	return vector2(x, y);
}
vector2 Characters::update(vector2 enemy, vector<vector<Land*>> land)
{
	vector2 newCord = cord;
	if (enemy.x > cord.x)
	{
		while (enemy.x > newCord.x && (land.at(newCord.x+ 1).at(newCord.y)->walkable))
		{
			if (newCord.x >= cord.x + 4)
				return newCord;
			newCord.x++;
		}
	}

	else if (enemy.x < cord.x)
	{
		while (enemy.x < newCord.x && (land.at(newCord.x - 1).at(newCord.y)->walkable))
		{
			if (newCord.x <= cord.x - 4)
				return newCord;
			newCord.x--;
		}
	}

	else if (enemy.y > cord.y)
	{
		while (enemy.y > newCord.y && (land.at(newCord.x).at(newCord.y + 1)->walkable))
		{
			if (newCord.y >= cord.y + 4)
				return newCord;
			newCord.y++;
		}
	}

	else if (enemy.y < cord.y)
	{
		while (enemy.y < newCord.y && (land.at(newCord.x).at(newCord.y - 1)->walkable))
		{
			if (newCord.y <= cord.y - 4)
				return newCord;
			newCord.y--;
		}
	}

	return newCord;
}

HeavyMace::HeavyMace(void){}
void HeavyMace::init(vector2 change, string newName)
{
	waiting = false;
	turnOrder = 1;
	health = 10;
	alive = health > 0;
	cord = change;

	maxHealth = 10;

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
		"MaceKnight_W.png",
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
		"MaceKnight_B.png",
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
	waiting = false;
	turnOrder = 2;
	health = 10;
	alive = health > 0;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	maxHealth = 10;

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
		"SwordKnight_W.png",
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
		"SwordKnight_B.png",
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
	waiting = false;
	turnOrder = 3;
	health = 10;
	alive = health > 0;
	cord = change;

	xp = 50;
	xp2NextLevel = ((((Level + 1) * 100)) * 0.1);

	maxHealth = 10;

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
		"AxeKnight_W.png",
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
		"AxeKnight_B.png",
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
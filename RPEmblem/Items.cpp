#include "stdafx.h"
#include "Items.h"

Items::Items(){}
Items::~Items(){}
void Items::init(vector2 change)
{
	alive = true;
	cord = change;

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	load("item.png");
}
void Items::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glPushMatrix();

	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
bool Items::load()
{
	return true;
}
bool Items::load(char * file)
{
	texture = SOIL_load_OGL_texture
		(
		(const char*)file,
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
void Items::effect(Characters*& character)
{
	character->health += 10;
}
void Items::update(vector2 playercord){}

void HPickup::init(vector2 change)
{
	alive = true;
	cord = change;

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	load();
}
void HPickup::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glPushMatrix();

	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
bool HPickup::load()
{
	texture = SOIL_load_OGL_texture
		(
		"health.png",
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
void HPickup::effect(Characters*& character)
{
	character->health += 20;
}
void HPickup::update(vector2 playercord)
{
	alive = playercord == cord;
}

void HTrap::init(vector2 change)
{
	alive = true;
	cord = change;

	position.x = (0.11) * cord.x + (0.11);
	position.y = (0.11) * cord.y;
	load();
}
void HTrap::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glPushMatrix();

	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
bool HTrap::load()
{
	texture = SOIL_load_OGL_texture
		(
		"trap.png",
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
void HTrap::effect(Characters*& character)
{
	character->health -= 5;
}
void HTrap::update(vector2 playercord)
{
	alive = playercord == cord;
}
#include "stdafx.h"
#include "Land.h"


void Land::init()
{}
void Land::draw()
{}
void Land::draw(bool triggerColors)
{}
bool Land::load()
{
	return false;
}


Wall::Wall(void){}
Wall::~Wall(){}
void Wall::init()
{
	resistance = 100000;
	health = 10;
	redHighLight = true;
	blueHighLight = false;
}
void Wall::draw()
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
	glTexCoord2f(1, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	//glColor3f(0, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	//glColor3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
void Wall::draw(bool triggerColors)
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
bool Wall::load()
{
	texture = SOIL_load_OGL_texture
		(
		"wall.png",
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


Dirt::Dirt(void)
{}
Dirt::~Dirt(){}
void Dirt::init()
{
	resistance = 20;
	redHighLight = true;
	blueHighLight = false;
}
void Dirt::draw()
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
	glTexCoord2f(1, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	//glColor3f(0, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	//glColor3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
void Dirt::draw(bool triggerColors)
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
	if (!triggerColors)
		color = vector3(0.2, 1, 0.2);
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
bool Dirt::load()
{
	texture = SOIL_load_OGL_texture
		(
		"dirt.png",
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


void Selection::draw()
{
	resistance = belowContent->resistance;
	if (blueHighLight)
		belowContent->draw(false);
	else if (redHighLight)
		belowContent->draw(true);
	else
		belowContent->draw();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glPushMatrix();

	glColor3f(1, 0, 0);
	glLoadIdentity();

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
void Selection::draw(bool triggerColors)
{
	resistance = belowContent->resistance;
	draw();
}
bool Selection::load()
{
	texture = SOIL_load_OGL_texture
		(
		"select.png",
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
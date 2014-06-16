#include "stdafx.h"
#include "Screens.h"

Button::Button(void)
{
	show = true;
}
Button::~Button(){}
void Button::updatePos(vector2 screen)
{
	drawSize.x = ((minSize.x + 200) / (screen.x / 2)) - 1;
	drawSize.y = ((minSize.y + 100) / (screen.y / 2)) - 1;
	position.x = (minSize.x / (screen.x / 2)) - 1;
	position.y = (minSize.y / (screen.y / 2)) - 1;
}
void Button::draw()
{
	if (!show)
		return;
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glPushMatrix();
	//glRotatef(180, 1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(position.x, drawSize.y, 0);
	glTexCoord2f(1, 0); glVertex3f(drawSize.x, drawSize.y, 0);
	glTexCoord2f(1, 1); glVertex3f(drawSize.x, position.y, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x, position.y, 0);
	/*
	glTexCoord2f(0, 0); glVertex3f(position.x - 1.11, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 0); glVertex3f(position.x - 1, position.y + 0.11 - 1, 0);
	glTexCoord2f(1, 1); glVertex3f(position.x - 1, position.y - 1, 0);
	glTexCoord2f(0, 1); glVertex3f(position.x - 1.11, position.y - 1, 0);
	*/
	glPopMatrix();
	glEnd();
	//glRotatef(-180, 1, 0, 0);
	glDisable(GL_TEXTURE_2D);
}
bool Button::load(char * file)
{
	texture = SOIL_load_OGL_texture
		(
		file,
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

Screens::Screens(void)
{
	show = true;
}
Screens::~Screens(){}
void Screens::draw(bool splash)
{
	if (!show)
		return;
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glPushMatrix();
	//glRotatef(180, 1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-1, 1, 0);
	glTexCoord2f(1, 0); glVertex3f(1, 1, 0);
	glTexCoord2f(1, 1); glVertex3f(1, -1, 0);
	glTexCoord2f(0, 1); glVertex3f(-1, -1, 0);
	glPopMatrix();
	glEnd();
	if (!splash)
	{
		glBindTexture(GL_TEXTURE_2D, instTexture);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glBegin(GL_QUADS);
		glPushMatrix();
		//glRotatef(180, 1, 0, 0);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(0, 0.5, 0);
		glTexCoord2f(1, 0); glVertex3f(1, 0.5, 0);
		glTexCoord2f(1, 1); glVertex3f(1, -0.5, 0);
		glTexCoord2f(0, 1); glVertex3f(0, -0.5, 0);
		glPopMatrix();
		glEnd();
	}
	//glRotatef(-180, 1, 0, 0);
	glDisable(GL_TEXTURE_2D);
}
bool Screens::load(char * file)
{
	texture = SOIL_load_OGL_texture
		(
		file,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	instTexture = SOIL_load_OGL_texture
		(
		"IntroText.png",
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
#include "stdafx.h"
#include "Text.h"

Text::Text()
{
	texture = SOIL_load_OGL_texture
		(
		"numbers.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 0
		/*SOIL_FLAG_INVERT_Y*/
		);

	//if (texture == 0)
	//	return;

	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	deathTime = 1000;
}

Text::~Text()
{
}

void Text::display()
{
	deathTime--;
	position.y += 0.004;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glRotatef(90, 0, 0, 1);
	glBegin(GL_QUADS);
	glPushMatrix();
	float modifier = number * 0.1;

	//glColor3f(1, 0, 0);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTexCoord2f(modifier, 0);			glVertex3f(position.x - 1.11, position.y + 0.11 - 1.05, 0);
	glTexCoord2f(modifier + 0.1f, 0);	glVertex3f(position.x - 1.05, position.y + 0.11 - 1.05, 0);
	glTexCoord2f(modifier + 0.1f, 1);	glVertex3f(position.x - 1.05, position.y - 1, 0);
	glTexCoord2f(modifier, 1);			glVertex3f(position.x - 1.11, position.y - 1, 0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
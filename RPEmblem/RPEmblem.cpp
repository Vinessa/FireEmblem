// RPEmblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "glut.h"
#include <stdio.h>
#include <gl/GL.h>
#include <gl\GLU.h>
#include "SOIL.h"
#include <map>
#include <math.h>
#include "VectorLib.h"
#include "Grid.h"

vector2 mouse(0, 0);
vector2 screen(800, 600);
Grid grid;

void drawGui();
void drawMenu();
void mouseClick(int button, int state, int x, int y);
void update();

void init(void)
{
	glShadeModel(GL_SMOOTH);
	glViewport(0, 0, screen.x, screen.y);
	glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	grid.init(18, 18);
	grid.screen = screen;
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}
void resize(int width, int height)
{
	screen.x = width;
	screen.y = height;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screen.x, screen.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)screen.x / (GLfloat)screen.y, 1.0f, 1000.0f);
	glutPostRedisplay();
	grid.screen = screen;
}

void keyboard(unsigned char key, int x, int y)
{
	grid.keyState[key] = true;
}
void keyboard_up(unsigned char key, int x, int y)
{
	grid.keyState[key] = false;
	switch (key)
	{
	case ' ':
		if (grid.curr == grid.GAME)
		{
			if (grid.turn <= 3)
				grid.playable.at(grid.turn)->swapStance();
		}
		else if (grid.curr == grid.SPLASH)
		{
			grid.curr = grid.GAME;
		}
		break;
	case 27:
		exit(0);
		grid.paused = !grid.paused;
	case 'p': case 'P':
		glutFullScreen();
		break;
	case 'b': case 'B':
		std::cout << "Breaking the game :D";
		break;
	case 'f': case 'F':
		if (grid.filling == 0)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			grid.filling = 1;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			grid.filling = 0;
		}
		break;
	}
}
void keyCommands()
{
}
void keyboard_s(int key, int x, int y)
{
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);

	glLoadIdentity();
	glViewport(0, 0, screen.x, screen.y);
	grid.draw(screen);
	
	glFlush();
	glutSwapBuffers();

	///<summary>Update commands </summary>
	update();
	keyCommands();
}
void update()
{
	grid.update();
}
void mouseClick(int button, int state, int x, int y)
{
	
	if (grid.curr == grid.MENU && state == GLUT_UP)
	{
		if (x >= grid.scr.buttons[0].minSize.x && x <= grid.scr.buttons[0].maxSize.x &&
			y >= grid.scr.buttons[0].minSize.y && y <= grid.scr.buttons[0].maxSize.y)
		{
			grid.scr.show = false;
			grid.curr = grid.GAME;
			grid.updateHalt = 0;
		}
		else if (x >= grid.scr.buttons[1].minSize.x && x <= grid.scr.buttons[1].maxSize.x &&
			y >= grid.scr.buttons[1].minSize.y && y <= grid.scr.buttons[1].maxSize.y)
		{
			exit(1);
		}
		return;
	}if (grid.curr == grid.SPLASH && state == GLUT_UP)
	{
		grid.curr = grid.MENU;
		grid.scr = Screens();
		grid.scr.load("menu.png");
		Button newPlay;
		Button newExit;
		newPlay.load("play.png");
		newPlay.minSize = vector2(screen.x / 4, 400);
		newPlay.maxSize = vector2(screen.x - (screen.x / 4), 500);
		newPlay.updatePos(screen);
		newPlay.minSize = vector2(screen.x / 4, 100);
		newPlay.maxSize = vector2(screen.x - (screen.x / 4), 200);
		grid.scr.buttons.push_back(newPlay);
		newExit.load("exit.png");
		newExit.minSize = vector2(screen.x / 4, 100);
		newExit.maxSize = vector2(screen.x - (screen.x / 4), 200);
		newExit.updatePos(screen);
		newExit.minSize = vector2(screen.x / 4, 400);
		newExit.maxSize = vector2(screen.x - (screen.x / 4), 500);
		grid.scr.buttons.push_back(newExit);
		return;
	}
	float x_norm = x / (screen.x / 2);
	float y_norm = y / (screen.y / 2);

	int counterx = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		if (x_norm - 2 >= i && x_norm - 2 <= i + 0.11)
		{
			break;
		}
		counterx++;
	}
	int countery = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		if (y_norm - 2 >= i && y_norm - 2 <= i + 0.11)
		{
			break;
		}
		countery++;
	}
	countery = 17 - countery;//Inverts the y to select the right node(it counts upside down, shhhhhhh)
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		try{
			if (grid.selectedNode == vector2(counterx, countery))//Deselects node
			{
				grid.nodes.at(counterx).at(countery) = grid.sel.belowContent;
				grid.move = true;
				if (grid.selectedNode == grid.playable.at(grid.turn)->cord)
				{
					grid.playable.at(grid.turn)->waiting = true;
				}
			}
			else //Selects new node
			{
				if (grid.selectedNode != vector2(-1, -1))//Deselects Past Node
				{
					grid.nodes.at(grid.selectedNode.x).at(grid.selectedNode.y) = grid.sel.belowContent;
				}
				grid.sel.belowContent = grid.nodes.at(counterx).at(countery); // Failsafe will activate if its out of bounds here.
				Selection * changeup = new Selection(grid.sel);
				grid.nodes[counterx][countery] = (Land*)changeup;
				grid.selectedNode = vector2(counterx, countery);
			}
		}
		catch (const std::out_of_range & oor)
		{
			std::cerr << "Out of Range" << oor.what();
		}
	}
}
void mouseMotion(int x, int y)
{
	float x_norm = x / (screen.x / 2);
	float y_norm = y / (screen.y / 2);

	int counterx = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		if (x_norm - 2 >= i && x_norm - 2 <= i + 0.11)
		{
			break;
		}
		counterx++;
	}
	int countery = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		if (y_norm - 2 >= i && y_norm - 2 <= i + 0.11)
		{
			break;
		}
		countery++;
	}
	countery = 17 - countery;//Inverts the y to select the right node(it counts upside down, shhhhhhh)
	try{
		if (!grid.nodes.at(counterx).at(countery)->isBottom())
		{
			grid.selWhite.belowContent = grid.nodes.at(counterx).at(countery);
			Selection * changeup = new Selection(grid.selWhite);
			grid.nodes.at(counterx).at(countery) = (Land*)changeup;
			//grid.selWhite.cord = vector2(counterx, countery);
		}
		else
		{
			Land * changeup = grid.selWhite.belowContent;
			grid.nodes.at(grid.selWhite.cord.x).at(grid.selWhite.cord.y) = changeup;
			grid.selWhite.cord = vector2(counterx, countery);
		}
	}
	catch (const std::out_of_range & oor)
	{
		std::cerr << "Out of Range" << oor.what();
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen.x, screen.y);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Darths, Vanessa, and Louie 2d game, Fo Shizzle");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboard_up);
	glutSpecialFunc(keyboard_s);
	//glutPassiveMotionFunc(mouseMotion);
	glutMouseFunc(mouseClick);
	init();
	glutMainLoop();
	return(1);
}
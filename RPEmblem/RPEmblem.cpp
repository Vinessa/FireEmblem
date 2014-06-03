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
	glClearColor(0.0, 0.0, 0.2, 0.0);
	glShadeModel(GL_SMOOTH);
	glViewport(0, 0, screen.x, screen.y);
	//glMatrixMode(GL_2D);
	glLoadIdentity();
	//gluPerspective(45.0f, (GLfloat)screen.x / (GLfloat)screen.y, 1.0f, 1000.0f);
	//glEnable(GL_2D);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glutSetCursor(GLUT_CURSOR_NONE);
	//glfwDisable(GLFW_MOUSE_CURSOR);
	grid.init(18,18);
	grid.screen = screen;
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
	//maps.keyState[key] = true;
}
void keyboard_up(unsigned char key, int x, int y)
{
	/*maps.keyState[key] = false;
	switch (key)
	{
	case ' ':
		if (player.jump == 2 && maps.curr == maps.GAME)
		{
			player.jump = 1;
			player.jumpYPos = player.position.y;
			//position.y++;
		}
		else if (maps.curr == maps.MENU)
		{
			maps.curr = maps.GAME;
		}
		break;
	case 27:
		//glutDestroyWindow(Win.id);
		//exit(0);
		maps.paused = !maps.paused;
		if (!maps.paused)
			glutSetCursor(GLUT_CURSOR_NONE);
		else
			glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		break;
	case '/':
		player.position.x = 0;
		player.position.z = 0;
		break;
	case '5':
		player.health--;
		break;
	case '8': case 'w': case 'W':
		player.speed.x = 0;
		player.speed.z = 0;
		break;
	case '2': case 's': case 'S':
		player.speed.x = 0;
		player.speed.z = 0;
		break;
	case 'q': case 'Q':
		maps.fireBullet(player.position, 0, player.lx, player.ly, player.lz);
		break;
	case 'r': case 'R':
		maps.reload();
		break;
	case 'p': case 'P':
		glutFullScreen();
		break;
	case 'b': case 'B':
		std::cout << "Breaking the game :D";
		break;
	case 'f': case 'F':
		if (player.filling == 0)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			player.filling = 1;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			player.filling = 0;
		}
		break;
	}*/
}
void keyCommands()
{
	/*typedef std::map<unsigned char, bool>::iterator it_type;
	for (it_type iterator = maps.keyState.begin(); iterator != maps.keyState.end(); iterator++)
	{
		if (iterator->second)
		{
			switch (iterator->first)
			{
			case '4': case 'a': case 'A':
				//angle -= 0.005f;
				//lx = sin(angle);
				//lz = -cos(angle);
				//position.x -= lx * 0.1f;
				//position.z += lz * 0.1f;
				break;
			case '8': case 'w': case 'W':
				//position.x += lx * 0.1f;
				//position.z += lz * 0.1f;
				player.speed.x = player.lx * 0.1f;
				player.speed.z = player.lz * 0.1f;
				break;
			case '2': case 's': case 'S':
				//position.x -= lx * 0.1f;
				//position.z -= lz * 0.1f;
				player.speed.x = -(player.lx * 0.1f);
				player.speed.z = -(player.lz * 0.1f);
				break;
			case '6': case 'd': case 'D':
				//position.x += lx * 0.1f;
				//angle += 0.005f;
				//lx = sin(angle);
				//lz = -cos(angle);
				break;

			case 'q': case 'Q':
				//bulletpair.fireBullet();
				break;
			}
		}
	}*/
}
void keyboard_s(int key, int x, int y)
{
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);

	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, screen.x, screen.y);
	grid.draw();
	///<summary>Draw commands </summary>
	//glutStrokeCharacter(GLUT_STROKE_ROMAN,player.position.y);

	/*switch (maps.curr)
	{
	case maps.GAME:

		gluLookAt(player.position.x, player.position.y + 1.0f, player.position.z, player.position.x + player.lx, player.position.y + 1.0f + player.ly, player.position.z + player.lz, 0.0f, 1.0f, 0.0f);

		player.draw();
		maps.draw();

		drawGui();

		break;
	case maps.MENU:
		drawMenu();
		break;
	case maps.EXIT:
		break;
	case maps.SPLASH:
		break;
	case maps.OPTIONS:
		break;
	}*/
	glFlush();
	glutSwapBuffers();

	///<summary>Update commands </summary>
	update();
	keyCommands();
}
void update()
{
	grid.update();
	/*if (!maps.paused)
	{
		bool fall = maps.update(player.speed, player.position, player.size, player.jump, player.invTimer, player.health, player.lightInf);
		player.update(fall);
	}*/
}
void mouseClick(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !maps.paused) {
		maps.fireBullet(player.position, player.angle, player.lx, player.ly, player.lz);
	}
	else if (maps.paused && y > (screen.y / 2) - (screen.y / 5) && y < (screen.y / 2) + (screen.y / 5) && x > screen.x / 4 && x < (screen.x / 2) + (screen.x / 4))
		exit(0);*/

	//float x_tran = x - (screen.x / 2);
	//float y_tran = y - (screen.y / 2);
	float x_norm = x / (screen.x / 2);
	float y_norm = y / (screen.y / 2);

	int counterx = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		int bob = 0;
		if (x_norm - 2 >= i && x_norm - 2 <= i + 0.11)
		{
			bob = 5;
			break;
		}
		counterx++;
	}
	int countery = 0;
	for (float i = -2; i <= 2; i += 0.11)
	{
		int bob = 0;
		if (y_norm - 2 >= i && y_norm - 2 <= i + 0.11)
		{
			bob = 5;
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
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of Range";
		}
	}
}
void mouseMotion(int x, int y)
{
	/*if (!maps.paused)
	{
		static bool warped = false;
		bool capture = false;
		if (warped)
		{
			warped = false;
			return;
		}

		mouse.x = x;
		mouse.y = y;
		if (x != screen.x || y != screen.y)
			capture = true;
		if (capture)
		{
			warped = true;
			if (x > screen.x / 2)
			{
				player.angle -= 0.05f;
				player.lx = sin(player.angle);
				player.lz = -cos(player.angle);
				glutWarpPointer(screen.x / 2, screen.y / 2);
			}
			else if (x < screen.x / 2)
			{
				player.angle += 0.05f;
				//if (player.vertAngle < 0)
				//player.vertAngle = 0;
				player.lx = sin(player.angle);
				player.lz = -cos(player.angle);
				glutWarpPointer(screen.x / 2, screen.y / 2);
			}
			if (y < screen.y / 2 && player.vertAngle < 0.8)
			{
				player.vertAngle += 0.05f;
				player.ly = sin(player.vertAngle);
				glutWarpPointer(screen.x / 2, screen.y / 2);
			}
			else if (y > screen.y / 2 && player.vertAngle > -0.8)
			{
				player.vertAngle -= 0.05f;
				//if (player.vertAngle > 360)
				//player.vertAngle = 360;
				player.ly = sin(player.vertAngle);
				glutWarpPointer(screen.x / 2, screen.y / 2);
			}
		}
	}
	//glutWarpPointer(screen.x/2,screen.y/2);*/
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
	glutPassiveMotionFunc(mouseMotion);
	glutMouseFunc(mouseClick);
	init();
	glutMainLoop();
	return(1);
}


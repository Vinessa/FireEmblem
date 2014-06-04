#ifndef _ChoiceMenu_H
#define _ChoiecMenu_H

struct MousePositon{
	int x, y;
};

struct Vector2{
	int x = 0;
	int y = 0;
};
struct Sprite{
	int texture = 0;
	int iWidth = 50;
	int iHeight = 50;
	Vector2 Position;

};
class ChoiceMenu
{
public:
	/*
	regular choice
	A
	B
	C
	
	highlighted A = HA
	Change texture to highlighted means that A is Selected
	HA
	B
	C
	/*
	/*Texture needs to change to */

	Sprite Options[3];

	/*highlightedChoice is just a place holder when chaning text*/
	Sprite HiOptions[3];


	void ChangeSelection(MousePositon &Position);
	ChoiceMenu(void);
	~ChoiceMenu(void);
};
#endif


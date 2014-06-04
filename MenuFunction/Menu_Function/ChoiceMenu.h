#ifndef _ChoiceMenu_H
#define _ChoiecMenu_H
struct Mouse{
	bool click;
	int x, y;
};

struct Vector2{
	int x;
	int y;
};
struct Sprite{
	int texture;
	int iWidth;
	int iHeight;
	Vector2 Position;
	int HoldTexture;

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
	enum state{MENU,GAME};
	state curr;
	Sprite Options;

	/*highlightedChoice is just a place holder when chaning text*/
	Sprite HiOptions;
	bool bHighlited;

	void ChangeSelection(Mouse &Position);
	void Select(Mouse Click);
	ChoiceMenu(void);
	~ChoiceMenu(void);
};
#endif


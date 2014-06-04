#ifndef _ChoiceMenu_H
#define _ChoiecMenu_H


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
	unsigned int texture;
	int iCurrentSelection;
	enum Choice{A,B,C};
	/*highlightedChoice is just a place holder when chaning text*/
	enum HighlightedChoice{HA,HB,HC}; 


	void ChangeSelection();
	ChoiceMenu(void);
	~ChoiceMenu(void);
};
#endif


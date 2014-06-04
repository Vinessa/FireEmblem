
#include <iostream>
#include "ChoiceMenu.h"
int main(){
	ChoiceMenu Choice;
	Mouse MOUSE;

	MOUSE.x = 25;
	MOUSE.y = 25;
	MOUSE.click = true;
	Choice.ChangeSelection(MOUSE);
	Choice.Select(MOUSE);
	return 0;

};
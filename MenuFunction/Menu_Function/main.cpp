
#include <iostream>
#include "ChoiceMenu.h"
int main(){
	ChoiceMenu Choice;
	MousePositon Mouse;
	Mouse.x = 25;
	Mouse.y = 25;

	Choice.ChangeSelection(Mouse);
	return 0;

};
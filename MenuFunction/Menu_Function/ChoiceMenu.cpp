#include "ChoiceMenu.h"


ChoiceMenu::ChoiceMenu(void)
{
	curr = MENU;
	Options.iHeight = 50;
	Options.iWidth = 50;
	Options.texture = 3;
	Options.HoldTexture = Options.texture;
	HiOptions.texture = 1;
	Options.Position.x = 0;
	Options.Position.y = 0;


}
ChoiceMenu::~ChoiceMenu(void)
{

}

void ChoiceMenu::ChangeSelection(Mouse &Position)
{
	int fullX;
	int fullY;

		fullX = Options.iWidth;
		fullY = Options.iHeight;
		if (fullX > Position.x && Options.Position.x < Position.x &&
			fullY > Position.y && Options.Position.y < Position.y)
		{
			Options.texture = HiOptions.texture;
			
			bHighlited = true;

		}
		else{
			bHighlited = false;
			Options.texture = Options.HoldTexture; 
		}

}

void ChoiceMenu::Select(Mouse Click){

	if (Click.click == true && bHighlited == true){
		curr = GAME;
	}
}

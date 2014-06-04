#include "ChoiceMenu.h"


ChoiceMenu::ChoiceMenu(void)
{
	for (int i = 0; i < (sizeof(Options) / sizeof(*Options)); i++)
	{
		Options[i].texture = 1;
	}
	for (int i = 0; i < (sizeof(Options) / sizeof(*Options)); i++)
	{
		HiOptions[i].texture = 5;
	}
	
}
ChoiceMenu::~ChoiceMenu(void)
{

}

void ChoiceMenu::ChangeSelection(MousePositon &Position)
{
	int fullX;
	int fullY;
	int size = (sizeof(Options) / sizeof(*Options));
	for ( int i = 0; i < size ; i++)
	{
		fullX = Options[i].iWidth;
		fullY = Options[i].iHeight;
		if (fullX > Position.x && Options[i].Position.x < Position.x &&
			fullY > Position.y && Options[i].Position.y < Position.y)
		{
			Options[i].texture = HiOptions[i].texture;
		}

	}
}


#include "stdafx.h"
#include "Weapon.h"


SWORD::SWORD(int newDurability)
{
	durability = newDurability;
}AXE::AXE(int newDurability)
{
	durability = newDurability;
}MACE::MACE(int newDurability)
{
	durability = newDurability;
}


int SWORD::Compare(Weapon* Weapon2){
		// sword take mace
		// axe takes sword
		// mace takes axe
	if (Weapon2->type() == "Sword"){
		return 0;
	}
	else if (Weapon2->type() == "Axe"){
		return 1;
	}
	else if (Weapon2->type() == "Mace"){
		return 2;
	}
	else 
		return 0;
}

int MACE::Compare(Weapon* Weapon2){
	if  (Weapon2->type() == "Sword"){
		return 1;
	}
	else if (Weapon2->type() == "Axe"){
		return 2;
	}
	else if (Weapon2->type() == "Mace"){
		return 3;
	}
	else
		return 0;
}
int AXE::Compare(Weapon* Weapon2){
	if (Weapon2->type() == "Sword"){
		return 1;
	}
	else if (Weapon2->type() == "Axe"){
		return 2;
	}
	else if (Weapon2->type() == "Mace"){
		return 3;
	}
	else
		return 0;
}
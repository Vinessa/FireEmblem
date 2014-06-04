#include "Tile.h"


void DoorHouse::MenuOptions(Jobs &jobs){
	int Choice = 0;
	switch(Choice)
	{
	case Sleep:
		jobs.HP = 100;
		break;
	default:
		break;
	}
}


TileHouse::TileHouse(){
	walkable = false;
	resistance = 100000;
}

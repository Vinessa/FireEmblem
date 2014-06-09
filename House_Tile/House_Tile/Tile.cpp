#include "Tile.h"

House::House(){
	resistance = 100000;
	health = 10;
	//Left is going to be a regular right house is going to be flip
	HouseLeft.Rotation = 270;
	HouseLeft2.Rotation = 270;
	HouseRight.Rotation = 90;
	HouseRight2.Rotation = 90;
	DoorFrame.Rotation = 0;
	HouseTile.Rotation = 0;

	//////////Position seperation
	position = vector2(0,0);
	HouseLeft.position = vector2(position.x,position.y);
	HouseLeft2.position = vector2(position.x,position.y + .11);

	DoorFrame.position = vector2( (.11 + HouseLeft.position.x),HouseLeft.position.y);
	HouseTile.position = vector2( (.11 + HouseLeft.position.x),HouseLeft2.position.y);

	HouseRight.position = vector2( (.11 + DoorFrame.position.x),DoorFrame.position.y);
	HouseRight2.position = vector2( (.11 + HouseTile.position.x),HouseTile.position.y);

}

House::House(float fx,float fy){
	resistance = 100000;
	health = 10;
	//Left is going to be a regular right house is going to be flip
	HouseLeft.Rotation = 270;
	HouseLeft2.Rotation = 270;
	HouseRight.Rotation = 90;
	HouseRight2.Rotation = 90;
	DoorFrame.Rotation = 0;
	HouseTile.Rotation = 0;

	//////////Position seperation
	position = vector2(fx,fy);
	HouseLeft.position = vector2(position.x,position.y);
	HouseLeft2.position = vector2(position.x,position.y + .11);

	DoorFrame.position = vector2( (.11 + HouseLeft.position.x),HouseLeft.position.y);
	HouseTile.position = vector2( (.11 + HouseLeft.position.x),HouseLeft2.position.y);

	HouseRight.position = vector2( (.11 + DoorFrame.position.x),DoorFrame.position.y);
	HouseRight2.position = vector2( (.11 + HouseTile.position.x),HouseTile.position.y);
}


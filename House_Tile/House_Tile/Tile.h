
#ifndef _Tile_H
#define _Tile_H

struct vector2{

	vector2(){}
	vector2(float Px,float Py){
		x = Px;
		y = Py;
	}
	float x,y;
};
struct gluint{};
class Land{
public:
	int resistance;
	int health;
	vector2 position;
};
class Tile: public Land
{
public:
	int Rotation;

};
class House : Land
{
public:


	House();
	House(float fx,float fy);
	Tile HouseRight;
	Tile HouseRight2;

	Tile HouseLeft;
	Tile HouseLeft2;
	
	Tile DoorFrame;
	Tile HouseTile;
};

#endif



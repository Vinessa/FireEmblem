
#ifndef _Tile_H
#define _Tile_H

class Jobs
{
public:
	Jobs(){}
	~Jobs(){}
	int HP;
private:

};
class Land{
public:
	//gluint texture;
	bool walkable;
	float resistance;
};

class TileHouse : Land
{
public:
	TileHouse();
private:
};

class  DoorHouse : Land
{
public:
	enum  Menu
	{
		Sleep,
		Eat
	};
	DoorHouse();
	void MenuOptions(Jobs &jobs);
};

#endif



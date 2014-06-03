#ifndef _Weapon_H
#define _Weapon_H


#include <string>
class Weapon
{
protected:
	
	
public:
	Weapon(){}
	Weapon(int newDurability){}
	~Weapon(void){
	}
	//has to use itself 
	int durability;
	virtual int Compare(Weapon* Weapon2) = 0;
	virtual std::string type() = 0;
};


class SWORD : public Weapon{
public:

	SWORD(){}
	SWORD(int newDurability);
	~SWORD(void){}
	std::string type() {return "Sword";}
	int Compare(Weapon* Weapon2);
};
class MACE : public Weapon{
public:
	MACE(){}
	MACE(int newDurability);
	~MACE(void){}
	std::string type(){return "Mace";}
	int Compare(Weapon * Weapon2);
};

class AXE : public Weapon{
public:
	AXE(){}
	AXE(int newDurability);
	~AXE(void){}
	std::string type(){return "Axe";}
	int Compare(Weapon *Weapon2);
};





#endif


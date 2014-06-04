#ifndef _ATTACKS_H_
#define _ATTACKS_H_
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"

class Attacks
{
public:
	Attacks(void);
	~Attacks(void);

	Weapon* MyWeapon;
	Weapon* TheirWeapon;

	int BuffDebuff;
	int Equalizer;
	float GrossDamageActive;
	float GrossDamageTarget;
	int WeaponTypeInt;
	int FirstStrike;


	float DetermineDamage(Characters* ActiveCharacter, Characters* TargetCharacter);
	int ShakeItUp();
	int ConvertWeaponStringToInt(Weapon* a_Weapon); // The Weapon class returns a string, but string can't be used in a switch statement so I'm converting to an int. 1 = Sword, 2 = Axe and 3 = Mace
	void ResolveAttacks(Characters* ActiveCharacter, Characters* TargetCharacter);
	void ResolveAllAttacks(Characters* ActiveCharacter); //goes through the array of adjacent characters and resolves battles

	
};

#endif //_ATTACKS_H_
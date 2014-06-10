/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Attacks.cpp 
// Created by Vinessa Mayer - June 2014
// Vinessa.Mayer@gmail.com

// This Attack Class was created for RPEmblem - a class assignment for first year programming.
// It calls on the Grid class by Jacob "Darth" Miller as well as a Weapons class by louie Escalera
//
// This class handles the battle step of the game. It determines the bettle outcome of all enemy 
// characters within' an array of active characters within' range of the character.
// To use, you'll need to call ExecuteBattle() with the active Character as an argument, this will
// check each opponent's fighting style to determine the rock paper sissors effect, as well as if the attack
// was executed well enough to either not be effected, be normally effected or be very effected by that advantage
// Characters take damage from each other except in the case of where the damage would kill them. In this case
// the character that would survive would be granted first strike and would not take damage from the 
// opposing character. In the case that both Character's would perish one of them is randomly selected for first strike.
// This class also handles exp gains and leveling up and health scaling with level.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*#ifndef _ATTACKS_H_
#define _ATTACKS_H_

#include <string>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"
class Characters;
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
	float ShakeItUp();
	int ConvertWeaponStringToInt(Weapon* a_Weapon); // The Weapon class returns a string, but string can't be used in a switch statement so I'm converting to an int. 1 = Sword, 2 = Axe and 3 = Mace
	void ResolveAttacks(Characters* ActiveCharacter, Characters* TargetCharacter);
	void ExecuteBattle(Characters* ActiveCharacter); //goes through the array of adjacent characters and resolves battles
	void CheckforLevelup(Characters* aCharacter);
	float FindNextLevelXP(Characters* aCharacter);
	void CalculateNextLevelStats(Characters* aCharacter);

};

#endif //_ATTACKS_H_*/
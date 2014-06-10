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

#include "StdAfx.h"/*
#include "Attacks.h"
#include "Grid.h"




Attacks::Attacks(void)
{
}


Attacks::~Attacks(void)
{
}

void Attacks::ExecuteBattle(Characters* ActiveCharacter) // goes through the array of adjacent characters and resolves battles
{
	vector<Characters*> Opponents(ActiveCharacter->adjecentArray); //copies the vector containing the possible opponents
	for (int i = 0; i < (int)Opponents.size(); i++)
	{
		Characters* Opponent = Opponents[i];
		ResolveAttacks(ActiveCharacter, Opponent);
	}
}

int Attacks::ConvertWeaponStringToInt(Weapon* a_Weapon)
{
	//Weapon* WeaponType = a_Weapon->type;
	if (a_Weapon->type() == "Sword")
	{

		return 1;
	}
	else
		if (a_Weapon->type() == "Axe")
		{
		return 2;
		}
		else
			if (a_Weapon->type() == "Mace")
			{
		return 3;
			}
}

//feeds in the type to determine rock paper sissors
float Attacks::DetermineDamage(Characters* ActiveCharacter, Characters* TargetCharacter)
{
	int ActiveCharacterWeaponType = (ConvertWeaponStringToInt(ActiveCharacter->weapon));
	int TargetCharacterWeaponType = (ConvertWeaponStringToInt(TargetCharacter->weapon));

	if (ActiveCharacterWeaponType = 1) //1 = Sword - Sword is weak against Axe and strong against Mace
	{
		{
			ShakeItUp();
			switch (TargetCharacterWeaponType)
			{
			case 1:
				BuffDebuff = (0 * Equalizer);
				return BuffDebuff;
				break;

			case 2:
				BuffDebuff = (-2 * Equalizer); // Will have a function that adds an interger to their damage regardless of being a buff or debuff. This is why debuff is listed as a negative number.
				return BuffDebuff;
				break;

			case 3:
				BuffDebuff = (2 * Equalizer);
				return BuffDebuff;
				break;
			}
		}
	}
	else
		if (ActiveCharacterWeaponType = 2) //2 = Axe. Axe is strong against Sword but weak against Mace

		{
		switch (TargetCharacterWeaponType)
		{
		case 1:
			BuffDebuff = (2 * Equalizer);
			return BuffDebuff;

		case 2:
			BuffDebuff = (0 * Equalizer);
			return BuffDebuff;

		case 3:
			BuffDebuff = (-2 * Equalizer);
			return BuffDebuff;

		default:
			break;

		}
		}
		else
			if (ActiveCharacterWeaponType = 3) // 3 = Mace. Mace is weak against Sword but strong against Axe
			{
		switch (TargetCharacterWeaponType)
		{
		case 0:
			BuffDebuff = (-2 * Equalizer);
			return BuffDebuff;
			break;

		case 2:
			BuffDebuff = (0 * Equalizer);
			return BuffDebuff;
			break;

		case 1:
			BuffDebuff = (2 * Equalizer);
			return BuffDebuff;
			break;
		}
			}
	return BuffDebuff;
}




float Attacks::ShakeItUp() // adds an element of randomness to the battle and prevents stalemates. Chooses a random int: 0, 1 or 2 and stores it. This number will be used as a scaler for the BuffDebuff bonus stat. 
{
	//Seeding Random
	srand(time(NULL));
	//Creating an Equalizer to return a random number of 0,1 or 2
	Equalizer = rand() % 2;
	return Equalizer;
}

float Attacks::FindNextLevelXP(Characters* aCharacter)
{
	aCharacter->xp2NextLevel = ((((aCharacter->Level + 1) * 100)) * 0.1);
	return aCharacter->xp2NextLevel;
}

void Attacks::CheckforLevelup(Characters* aCharacter)
{
	FindNextLevelXP(aCharacter);
	if (aCharacter->xp >= aCharacter->xp2NextLevel)
	{
		aCharacter->Level = aCharacter->Level + 1;
		CalculateNextLevelStats(aCharacter);

	}
}

void Attacks::CalculateNextLevelStats(Characters* aCharacter)
{
	float HealthBonus = (((ceil(aCharacter->maxHealth + 1) / 100)) * 20);
	float HealthDifference = ((aCharacter->maxHealth + HealthBonus) - aCharacter->maxHealth);
	aCharacter->maxHealth = (aCharacter->maxHealth + HealthBonus);
	aCharacter->health = (aCharacter->health + HealthDifference);

}



void Attacks::ResolveAttacks(Characters* ActiveCharacter, Characters* TargetCharacter)
{
	//Checking for FirstStrike
	GrossDamageActive = (ActiveCharacter->weapon->damage + (DetermineDamage(ActiveCharacter, TargetCharacter)));
	GrossDamageTarget = (TargetCharacter->weapon->damage + (DetermineDamage(ActiveCharacter, TargetCharacter)));
	// in the event of a tie
	if ((GrossDamageTarget > ActiveCharacter->health) && (GrossDamageActive > TargetCharacter->health))
	{
		//Seeding random for random choice
		srand(time(NULL));
		FirstStrike = rand() % 1;

		if (FirstStrike = 0)
		{
			ActiveCharacter->health = 0; //Active character dies
			ActiveCharacter->alive = false;
			TargetCharacter->xp = (TargetCharacter->xp + ActiveCharacter->xp);
			CheckforLevelup(TargetCharacter);
			//Possibly put the part about moving onto next adjasent target here, or leaving the battle state
		}
		else
			if (FirstStrike = 1)
			{
			TargetCharacter->health = 0;
			TargetCharacter->alive = false;
			ActiveCharacter->xp = (ActiveCharacter->xp + TargetCharacter->xp);
			CheckforLevelup(ActiveCharacter);
			}

	}
	else //in the event that the active character will die and the target character will not
		if ((GrossDamageTarget > ActiveCharacter->health) && (GrossDamageActive < TargetCharacter->health))
		{
		ActiveCharacter->health = 0;
		ActiveCharacter->alive = false;
		TargetCharacter->xp = (TargetCharacter->xp + ActiveCharacter->xp);
		CheckforLevelup(TargetCharacter);
		//move on?
		}
		else // in the event that the target character will die and the active character will not
			if ((GrossDamageTarget < ActiveCharacter->health) && (GrossDamageActive > TargetCharacter->health))
			{
		TargetCharacter->health = 0;
		TargetCharacter->alive = false;
		ActiveCharacter->xp = (ActiveCharacter->xp + TargetCharacter->xp);
		CheckforLevelup(ActiveCharacter);
			}

			else // in the event they both survive, both take damage equal to the other's weapon
			{
				TargetCharacter->health = TargetCharacter->health - GrossDamageActive;
				ActiveCharacter->health = ActiveCharacter->health - GrossDamageTarget;
			}
}
*/
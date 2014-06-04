#include "StdAfx.h"
#include "Attacks.h"




Attacks::Attacks(void)
{
}


Attacks::~Attacks(void)
{
}

void Attacks::ResolveAllAttacks(Characters* ActiveCharacter) // goes through the array of adjacent characters and resolves battles
{
	std::vector<Characters*> Opponents(ActiveCharacter-> AdjacentCharacters) //copies the vector containing the possible opponents
}

int Attacks::ConvertWeaponStringToInt(Weapon* a_Weapon)
{
	//Weapon* WeaponType = a_Weapon->type;
	if (*a_Weapon->type == "Sword")
	{

		return 1;
	}
	else
		if (a_Weapon->type == "Axe")
		{
		return 2;
		}
		else
			if (a_Weapon->type == "Mace")
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
	else
		if (ActiveCharacterWeaponType = 2) //2 = Axe. Axe is strong against Sword but weak against Mace
		{
		switch (TargetCharacterWeaponType)
			case 1:
				BuffDebuff = (2 * Equalizer);
				return BuffDebuff;
				break;

			case 2:
				BuffDebuff = (0 * Equalizer);
				return BuffDebuff;
				break;
			case 3:
				BuffDebuff = (-2 * Equalizer);
				return BuffDebuff;
				break;
		}
		else
			if (ActiveCharacterWeaponType = 3) // 3 = Mace. Mace is weak against Sword but strong against Axe
			{
		switch (TargetCharacterWeaponType)
			case "Sword":
				BuffDebuff = (-2 * Equalizer);
				return BuffDebuff;
				break;

			case "Mace":
				BuffDebuff = (0 * Equalizer);
				return BuffDebuff;
				break;

			case "Axe":
				BuffDebuff = (2 * Equalizer);
				return BuffDebuff;
				break;
			}
		}

	}
}


int Attacks::ShakeItUp() // adds an element of randomness to the battle and prevents stalemates. Chooses a random int: 0, 1 or 2 and stores it. This number will be used as a scaler for the BuffDebuff bonus stat. 
{
	//Seeding Random
	srand(time(NULL));
	//Creating an Equalizer to return a random number of 0,1 or 2
	Equalizer = rand() % 2;
}

void Attacks::ResolveAttacks(Characters* ActiveCharacter, Characters* TargetCharacter)
{
	//Checking for FirstStrike
	GrossDamageActive = (ActiveCharacter ->weapon ->damage + (DetermineDamage(ActiveCharacter, TargetCharacter)));
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
			ActiveCharacter->IsDead = True;
			//Possibly put the part about moving onto next adjasent target here, or leaving the battle state
		}
		else
			if (FirstStrike = 1)
			{
			TargetCharacter->health = 0;
			TargetCharacter->IsDead = True;
			}
	
	}
	else //in the event that the active character will die and the target character will not
		if ((GrossDamageTarget > ActiveCharacter->health) && (GrossDamageActive < TargetCharacter->health))
		{
		ActiveCharacter->health = 0;
		ActiveCharacter->IsDead = True;
		//move on?
		}
		else // in the event that the target character will die and the active character will not
			if ((GrossDamageTarget < ActiveCharacter->health) && (GrossDamageActive > TargetCharacter->health))
			{
			TargetCharacter->health = 0;
			TargetCharacter->IsDead = True;
			}

			else // in the event they both survive, both take damage equal to the other's weapon
			{
				TargetCharacter->health = TargetCharacter-> health - GrossDamageActive;
				ActiveCharacter->health = ActiveCharacter-> health - GrossDamageTarget;
			}

}



#pragma once
#include <iostream>

using namespace std;

class Character 
{
public:
	virtual void Attack(int*) {};
	virtual void Spell(int*) {};
	virtual void setBlock() {};

	//virtual int* getHealth() { return 0; }
	virtual bool getBlock() { return false; }

	virtual void showHealth() {};

	virtual bool getAlive() { return true; }

	virtual int* getHealth() { return &health; }

	virtual int setHealth() { health = 1500; return health; }
	virtual void setHeal(int t_heal) { health = health + t_heal; }
	

private:
	int health;
};

class Orc : public Character		//Orc subclass
{
	
	int strength = 2;
	int intellect = 2;
	int magicPoints = 700;
	bool block = false;

	
	bool alive = true;

public:
	
	Orc() { setHealth(); };

	void Attack(int *t_tHealth) //Passing troll health by pointer
	{
		int damage = 100 * strength;

		cout << "Take THIS!" << endl;
		cout << "Troll takes " << damage << " damage" << endl;

		*t_tHealth = *t_tHealth - damage;	//Deal damage to health
		
	}

	void Spell(int *t_tHealth)
	{
		int spellChoice = 0;
		int spellPower = 50 * intellect;
		

		cout << "What spell would you like to cast?" << endl;
		cout << endl << "You have " << magicPoints << " MP" << endl;
		cout << "1. Fireball X1 MP" << endl;
		cout << "2. Heal X2 MP" << endl;

		cin >> spellChoice;

		if (spellChoice == 1)
		{
			if (magicPoints < 100)
			{
				cout << "You do not have enough MP to cast this spell" << endl;
				cout << "The spell fails" << endl;
			}
			else
			{
				cout << "Orc casts Fireball" << endl;
				cout << "Troll takes " << spellPower << " damage" << endl;

				*t_tHealth = *t_tHealth - spellPower;	//Deal damage to health

				magicPoints = magicPoints - 100;
			}
			
		}

		else if (spellChoice == 2)
		{
			if (magicPoints < 200)
			{
				cout << "You do not have enough MP to cast this spell" << endl;
				cout << "The spell fails" << endl;
			}

			else
			{
				cout << "Orc casts Heal on himself" << endl;
				cout << "Orc heals for " << spellPower << " HP" << endl;

				setHeal(spellPower);	//heal caster

				magicPoints = magicPoints - 200;

				showHealth();
			}
			
		}

	}

	void setBlock()		
	{
		if (block == false)
		{
			block = true;
		}
		

		else if (block == true)	//if already blocking remove block
		{
			block = false;
		}
	}
	void showHealth()
	{
		cout << "Orc current health is "<< *getHealth() << endl;
	}

	bool getAlive() 
	{
		if (*getHealth() <= 0)
		{
			alive = false;
		}
	
		return alive; 
	}

	bool getBlock() { return block; }
};

												


class Troll : public Character		//Troll subclass
{

	int strength = 3;
	int intellect = 1;
	

	bool block = false;

	bool alive = true;

public:
	
	Troll() { setHealth(); };
	
	void Attack(int *t_oHealth)	//passing orc health by pointer
	{
		int damage = 100 * strength;
		cout << "Take THIS!" << endl;
		cout << "Orc takes " << damage << " damage" << endl;

		*t_oHealth = *t_oHealth - damage;

		
	}

	void Spell(int *t_oHealth)
	{
		int spellChoice = 0;
		int spellPower = 50 * intellect;
		int magicPoints = 700;

		cout << "What spell would you like to cast?" << endl;
		cout << endl << "You have " << magicPoints << " MP" << endl;
		cout << "1. Fireball X1 MP" << endl;
		cout << "2. Heal X2 MP" << endl;

		cin >> spellChoice;

		if (spellChoice == 1)
		{
			if (magicPoints < 100)
			{
				cout << "You do not have enough MP to cast this spell" << endl;
				cout << "The spell fails" << endl;
			}

			else
			{
				cout << "Orc casts Fireball" << endl;
				cout << "Troll takes " << spellPower << " damage" << endl;

				*t_oHealth = *t_oHealth - spellPower;	//Deal damage to health

				magicPoints = magicPoints - 100;
			}
			
		}

		else if (spellChoice == 2)
		{

			if (magicPoints < 200)
			{
				cout << "You do not have enough MP to cast this spell" << endl;
				cout << "The spell fails" << endl;
			}
			else
			{
				cout << "Troll casts Heal on himself" << endl;
				cout << "Troll heals for " << spellPower << " HP" << endl;

				setHeal(spellPower);	//heal caster

				magicPoints = magicPoints - 200;
				showHealth();
			}
			
			
		}

	}

	void setBlock()
	{
		if (block == false)
		{
			block = true;
		}


		else if (block == true)	//if already blocking remove block
		{
			block = false;
		}
	}

	void showHealth()
	{
		cout << "Troll current health is " << *getHealth() << endl;
	}

	bool getAlive()
	{
		if (*getHealth() <= 0)
		{
			alive = false;
		}

		return alive;
	}

	bool getBlock() { return block; }
};


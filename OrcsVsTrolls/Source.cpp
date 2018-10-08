
#include <iostream>
#include "Character.h"

using namespace std;

int main(void)
{
	Character* characters[2];
	characters[0] = new Orc();
	characters[1] = new Troll();

	int turn = 0;

	while (characters[0]->getAlive() == true || characters[0]->getAlive() == true)	//Game loop
	{
		if (turn == 0)		
		{

			int input = 0;

			cout << "Orcs turn" << endl;

			cout << "1.Melee" << endl;
			cout << "2.Spell" << endl;
			cout << "3.Block" << endl;

			cin >> input;
			cout << endl;
			
			if (input == 1)		//Melee attack
			{
				if (characters[1]->getBlock() == false)
				{
					characters[0]->Attack(characters[1]->getHealth());	//passes the pointer to the function
					
				}

				else if (characters[1]->getBlock() == true)
				{
					cout << "Troll blocked your attack!" << endl;
					
				}

				characters[1]->showHealth();
			}

			else if (input == 2)		//Spells
			{
				characters[0]->Spell(characters[1]->getHealth());
			}

			else if (input == 3)		//Block
			{
				characters[0]->setBlock();
			}

			
			else
			{
				cout << "Please enter a valid input (1, 2, 3)" << endl;
			}
			

			turn = 1;
		} //Orc Turn
		
	else if (turn == 1)	//Troll turn
	{
		int input = 0;

		cout << "Troll turn" << endl;

		cout << "1.Melee" << endl;
		cout << "2.Spell" << endl;
		cout << "3.Block" << endl;

		cin >> input;
		cout << endl;

		if (input == 1)		//Melee attack
		{

			if (characters[0]->getBlock() == false)
			{
				characters[1]->Attack(characters[0]->getHealth());	//passes the pointer to the function
				characters[0]->showHealth();
			}

			else if (characters[0]->getBlock() == true)
			{
				cout << "Orc blocked your attack!" << endl;
			}
			
		}

		else if (input == 2)		//Spells
		{
			characters[1]->Spell(characters[0]->getHealth());
		}

		else if (input == 3)		//Block
		{
			characters[1]->setBlock();
		}
		
		else
		{
			cout << "Please enter a valid input (1, 2, 3)" << endl;
		}

			turn = 0;
		}

			
	}

	if (characters[0]->getHealth() <= 0)
	{
		cout << "Orc has been slain!";
	}

	else if (characters[1]->getHealth() <= 0)
	{
		cout << "Troll has been slain!";
	}
	

	system("PAUSE");


}





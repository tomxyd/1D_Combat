#include <iostream>


int main()
{
	srand(time(NULL));
	//Adeptus stats and attributes
	int numAdepti = 0;
	int ad_Health{10};
	int ad_Attack{5};
	int ad_Defense{2};
	//Humans stats and attributes
	int numHumans = 0;
	int h_Health{7};
	int h_Attack{4};
	int h_Defense{2};

	std::cout << "\t***BATTLE SIMULATOR***\n";
	std::cout << "Please enter a number of Adeptus:\n";
	std::cin >> numAdepti;
	std::cout << "Please enter a number of Humans:\n";
	std::cin >> numHumans;
	std::cout << "\t***BEGIN BATTLE***\n";

	char turn = 'H';
	float hitChance{};
	int damage{};
	int ad_health = ad_Health;
	int h_health = h_Health;


	while (numHumans != 0 && numAdepti != 0)
	{
		turn = 'H';
		if (turn == 'H')
		{
			hitChance = (rand() % 10) + 1;
			hitChance = hitChance / 10;
			if (hitChance >= 0.5f)
			{
				damage = h_Attack - ad_Defense;
				ad_health -= damage;
				if (ad_health <= 0)
				{
					ad_health = 0;
					numAdepti -= 1;
					//reset Health
					ad_health = ad_Health;
				}
			}
		}

		turn = 'A';

		if (turn == 'A')
		{
			hitChance = (rand() % 10) + 1;
			hitChance = hitChance / 10;
			if (hitChance >= 0.5f)
			{
				damage = ad_Attack - h_Defense;
				h_health -= damage;
				if (h_health <= 0)
				{
					h_health = 0;
					numHumans -= 1;
					h_health = h_Health;
				}
			}
		}
	}


	if (numAdepti == 0)
	{
		std::cout << "Winner is Humans, humans left: " << numHumans << std::endl;
	}
	else if (numHumans == 0)
	{
		std::cout << "Winner is Adeptis, adeptis left: " << numAdepti;
	}

	
}
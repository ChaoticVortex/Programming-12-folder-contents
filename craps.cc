#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int dice_roll()
{
	
	usleep(((rand()%90 + 10) /10) * 200000);
	int generated = 1 + int(6.0 * rand()/(RAND_MAX +1.0));
	return generated;
}

int main()
{
	long bet;
	char turn = 0;
	char d1;
	char d2;
	char sum;
	char point = 0;
	bool win;
	
	srand(time(NULL));
	cout << "Enter a bet amount: " << endl; cin >> bet;
	while (true)
	{
		turn++;
		cout << "Rolling the dice..." << endl;
		d1 = dice_roll();
		d2 = dice_roll();
		sum = d1 + d2;
		printf("The first dice was a %i and the second dice was a %i, for a sum of %i\n\n", (int)d1, (int)d2, (int)sum);
		if (turn != 1)
		{
			if (sum == point)
			{
				win = true;
				break;
			}
			else if (sum == 7)
			{
				win = false;
				break;
			}
			else
			{
				cout << "Your point is: " << (int)point << endl << endl;
			}
		}

		else
		{
			if (sum == 7)
			{
				win = true;
				break;
			}
			else if ((sum == 2) || (sum == 3) || (sum == 12))
			{
				win = false;
				break;
			}
			else
				point = sum;
		}
	}
	if (win == true)
		cout << "Congratulations, you won $" << bet * 2 << "!\nCome again soon!" << endl; 
	else if (win == false)
		cout << "You lost. \nTry again to get your $"<< bet <<" back!" << endl;
	else
		cout << "something fuk up gg" << endl;
}

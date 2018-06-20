#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

using namespace std;

// POINT DOESNT CHANGE FROM 0
class Craps
{
	double bet;

	public:
		bool play();
		void set_bet(double);
		double get_bet();
	private:
		int dice_roll();

};

void Craps::set_bet(double num)
{
	Craps::bet = num;
}

double Craps::get_bet()
{
	return bet;
}

bool Craps::play()
{
	int turn = 0;
	int d1;
	int d2;
	int sum;
	int point;
	bool win;
	srand(time(NULL));
	
	while (true)
	{
		turn++;
		d1 = dice_roll();
		d2 = dice_roll();
		sum = d1 + d2;
		printf("The first dice was a %i and the second dice was a %i, for a sum of %i\n\n", d1, d2, sum);
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
				cout << "Your point is: " << point << endl << endl;
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
			{
				point = sum;
			}
		}
	}
	if (win == true)
		cout << "Congratulations, you won $" << Craps::bet * 2 << "!\nCome again soon!" << endl; 
	else if (win == false)
		cout << "You lost. \nTry again to get your $"<< Craps::bet <<" back!" << endl;
	cout << endl<< endl;
	return win;
}
	
	

int Craps::dice_roll()
{
	usleep(1000);
	int generated = rand() % 6 + 1;
	return generated;
}

int main(){
	double betamt = 1;
	Craps crap;
	bool won = false;
	
	while (won != true)
	{
		cout << "\nTime to play!\nOur bet is going to be: " << betamt << endl << endl;
		crap.set_bet(betamt);
		won = crap.play();
		betamt *= 2;
	}
	cout << "We finally won! We won $" << betamt << endl;

}


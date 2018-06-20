#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long num = 1;
	long sum = 0;
	long amount = 0;
	long avg;
	
	while (num != 0)
	{
		cout << "Please enter an integer: ";
		cin >> num;
		if (cin.fail())
		{
			cout << "Please enter an integer: ";
			// clear error state
			cin.clear();
			// discard 'bad' character(s)
			cin.ignore(100, '\n');
			continue;
		}
		amount ++;
		sum += num;
		avg = sum/amount;
		cout << "Your average is: " << avg << endl;
		printf("With a sum of %li and %li number(s).", sum, amount);
	}
	return (0);
}

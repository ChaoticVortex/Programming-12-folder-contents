#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int amount, t, l, q, d, n , p;
	cout << "How many pennies do you have? ";cin >> amount;
	printf("You have %i pennies.", amount);
	t = amount / 200; amount = amount % 200;
	l = amount / 100; amount = amount % 100;
	q = amount / 25; amount = amount % 25;
	d = amount / 10; amount = amount % 10;
	n = amount / 5; amount = amount % 5;
	p = amount;
	printf("\nYour change is %i toonies, %i loonies, %i quarters, %i dimes, %i nickels and %i pennies.", t, l, q, d, n, p);
	return 0;
}

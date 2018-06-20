#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//passing by reference
void quad(double a, double b, double c, double &r1, double &r2)
{
	double discrim = b * b - 4 * a  * c;
	if (discrim < 0)
	{
		cout << "This quadratic has no real roots.";
	}
	else if (discrim == 0)
	{
		r1 = -1 * b / (2 * a);
		cout << "This quadratic has a root at " << r1 << endl;
	}
	else
	{
		discrim = sqrt(discrim);
		r1 = ((-1 * b + discrim) / (2 * a));
		r2 = ((-1 * b - discrim) / (2 * a));
		printf("This quadratic has roots at %f and %f.", r1, r2);
	}
	return;
}


int main()
{
	double a, b, c, r1, r2;
	cout << "Enter your x-squared coefficient: "; cin >> a;
	cout << "Enter your x coefficient: "; cin >> b;
	cout << "Enter your constant term: "; cin >> c;
	printf("\n\nYour quadratic is %dx^2 + %dx + %d\n", (int) a, (int) b, (int) c);
	quad(a,b,c,r1,r2);
}


/*
//original code
int main()
{
	float a, b, c;
	float discrim;
	float x1, x2;
	
	cout << "Enter your x-squared coefficient: "; cin >> a;
	cout << "Enter your x coefficient: "; cin >> b;
	cout << "Enter your constant term: "; cin >> c;
	printf("\n\nYour quadratic is %dx^2 + %dx + %d\n", (int) a, (int) b, (int) c);
	discrim = b * b - 4 * a  * c;
	if (discrim < 0)
	{
		cout << "This quadratic has no real roots.";
	}
	else if (discrim == 0)
	{
		x1 = -1 * b / (2 * a);
		cout << "This quadratic has a root at " << x1 << endl;
	}
	else
	{
		discrim = sqrt(discrim);
		x1 = ((-1 * b + discrim) / (2 * a));
		x2 = ((-1 * b - discrim) / (2 * a));
		printf("This quadratic has roots at %f and %f.", x1, x2);
	}
	return 0;
}
*/

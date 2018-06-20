#include <iostream>
using namespace std;

int main()
{
	int inp;
	int c;
	int f;
	int k;
	char cel_or_f;

	cout << "Please enter a temperature." << endl;
	cin >> inp;
	
	cout << "Please enter whether this is in C, F or K." << endl;
	cin >> cel_or_f;
	
	if (cel_or_f == 'c' or cel_or_f == 'C')
	{
		c = inp;
		f = c * 9 / 5 + 32;
		k = c + 273;
	}
	else if (cel_or_f == 'f' or cel_or_f == 'F')
	{
		f = inp;
		c = (f - 32) * 5 / 9 ;
		k = c + 273;
	}
	else if (cel_or_f == 'k' or cel_or_f == 'K')
	{
		k = inp;
		c = k - 273;
		f = c * 9 / 5 + 32;
	}
	else
	{
		cout << "This is an invalid input" << endl;
		return 1;
	}
	cout << "The temperature in Kelvin is: " << k << endl;
	cout << "The temperature in Celsius is: " << c << endl;
	cout << "The temperature in Fahrenheit is: " << f << endl;
	return 0;
}

#include <iostream>

using namespace std;

int fib(int n) 
{
	if (n == 0)
			return 0;
	if (n == 1 or n == 2)
		return 1;
	return fib(n-1) + fib(n-2);
}

int main()
{
	
	int num1 = 0;
	
	/*
	int num2 = 1;
	
	for (int i = 0; i < 20; i++)
	{
		cout << num1 << endl;
		num2 = num1 + num2;
		num1 = num2 - num1;
	}
	*/
	cout << "Enter the Fibonacci number you want "; cin >> num1;
	cout << fib(num1);
		
	return 0;
}

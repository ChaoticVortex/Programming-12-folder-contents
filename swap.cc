#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
	return;
}

int main()
{
	int x, y;
	cout << "Please enter an integer: "; cin >> x;
	cout << "Please enter another integer: "; cin >> y;
	cout << x << "  " <<  y << endl;
	swap(x,y);
	cout << x << "  " <<  y << endl;
	
}

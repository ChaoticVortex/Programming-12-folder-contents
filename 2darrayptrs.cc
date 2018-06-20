
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	char map[3][3];
	int x,y;
	cout << "Give me 3 names" << endl;
	cin.get(map[0], 4);
	cin.ignore(80, '\n');
	cin.get(map[1], 4);
	cin.ignore(80, '\n');
	cin.get(map[2], 4);
	cin.ignore(80, '\n');
	cout << "Give me the coordinates of what letter you want to see" << endl;
	cin >> x >> y;
	cout << *(*(map+x)+y) << endl;
	return 0;
	
}

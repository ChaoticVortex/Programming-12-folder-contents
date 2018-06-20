#include <iostream>
using namespace std;

string hi()
{
	string x;
	cout << "Please enter a word." << endl;
	cin >> x;
	
	return x;
}

int main()
{
	string l;
	
	cout << "hello world" << endl;
	l = hi();
	cout << l << endl;
	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	int age;
	string name;
	
	cout << "What is your name?" << endl; 
	getline(cin, name); cout << endl;
	cout << "Hi " << name << ", what is your age?" << endl;
	cin >> age; cout << endl;
	cout << name << "'s age is: " << age << endl;
	return 0;
}

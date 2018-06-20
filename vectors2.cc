#include <vector>
#include <iostream>
using namespace std;

void f(vector <int> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return;
}


int main()
{
	vector <int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	/*
	for (unsigned int i = v.size() -1 ; i >= 0; i--)
	{
		if (v[i] < 5)
		{
			v.erase(v.begin() + i);
		}
		f(v);
	}
	*/
	for (unsigned int i = 0; i < v.size();i++)
	{
		if (v[i] < 5)
		{
			v.erase(v.begin() + i);
		}
		f(v);
	}
	return 0;
}

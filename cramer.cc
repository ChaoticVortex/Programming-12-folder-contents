#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef vector <vector <int> > matrix;


void print(vector <int> v)
{
	cout << endl << '[' << ' ';
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << ']' << ' ';
	
}

void print(matrix m)
{
	cout << endl;
	for (unsigned int i = 0; i < m.size(); i++)
	{
		print(m[i]);
		cout << endl;
	}
	
}

int det2by2(matrix mat)
{
	return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

int main()
{
	matrix m;
	vector <int> v(2);
	v[0] = -1;
	v[1] = 2;
	m.push_back(v);
	v[0] = 4;
	v[1] = 1;
	m.push_back(v);
	cout << det2by2(m);
	print(m);
}


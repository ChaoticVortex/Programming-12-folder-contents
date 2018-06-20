#include <vector>
#include <iostream>
using namespace std;
typedef vector <vector <int> > matrix;

void print(matrix m)
{
	cout << endl;
	for (unsigned int i = 0; i < m.size(); i++)
	{
		for (unsigned int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << ' ';
		cout << endl;
	}
	
}

matrix sum(matrix x, matrix y)
{
	for (unsigned int i = 0; i < x.size(); i++)
		for (unsigned int j = 0; j < x[i].size(); j++)
			x[i][j] = x[i][j] + y[i][j];
	return x;
}

matrix subtract(matrix x, matrix y)
{
	for (unsigned int i = 0; i < x.size(); i++)
		for (unsigned int j = 0; j < x[i].size(); j++)
			x[i][j] = x[i][j] - y[i][j];
	return x;
}

matrix cmult(matrix x, int c)
{
	for (unsigned int i = 0; i < x.size(); i++)
		for (unsigned int j = 0; j < x[i].size(); j++)
			x[i][j] = x[i][j] * c;
	return x;
}


int main()
{
	matrix v;
	vector <int> row(5);
	for (int i = 0; i < 7; i++)
	{
		for (int x = 0; x < 6; x++)
			row[x] = i * 5 + x;
		v.push_back(row);
	}
	print (v);
	print (sum(v,v)); 
	return 0;
}

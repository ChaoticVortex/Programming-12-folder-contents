#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>
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

//defines a random matrix
matrix randmatrix(int rows, int cols, int min, int max)
{
	matrix v;
	vector <int> row(rows);
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
			row[x] = rand() % (max - min + 1) + min;
		v.push_back(row);
	}
	return v;
}


//the following are matrix operations
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

//row operations
int rowsum(const vector <int> &v)
{
	int sum = 0;
	for (unsigned int i = 0; i < v.size(); i++)
		sum += v[i];
	return sum;
}

//includes rowsum at the end
void printall(matrix m)
{
	cout << endl;
	for (unsigned int i = 0; i < m.size(); i++)
	{
		print(m[i]);
		cout << rowsum(m[i]) << endl;
	}
	
}

int findmin(const matrix &m)
{
	int lowest, index = 0;
	lowest = rowsum(m[0]);
	for (unsigned int i = 1; i < m.size(); i++)
	{
		if (lowest > rowsum(m[i]))
		{
			lowest = rowsum(m[i]);
			index = i;
		}
	}
	return index;
}

matrix sel_sort(matrix old)
{
	matrix sorted;
	int index;
	while (old.size() > 0)
	{
		index = findmin(old);
		//cout << rowsum(old[index]) << " " <<  index << endl;
		cout << "The next smallest rowsum is " << rowsum(old[index]) << endl;
		sorted.push_back(old[index]);
		old.erase(old.begin() + index);
	}
	
	return sorted;
}


int main()
{
	srand(time(NULL));
	matrix x;
	matrix v;
	matrix g;
	
	/*
	//Makes v a 7 * 5 matrix from 0-34
	vector <int> row(5);
	for (int i = 0; i < 7; i++)
	{
		for (int x = 0; x < 6; x++)
			row[x] = i * 5 + x;
		v.push_back(row);
	}
	print(v);
	
	*/
	
	//Makes a random matrix with (rows, columns, minimum value, max value)
	x = randmatrix(6,6,0,99);
	printall(x);
	cout << endl << endl << findmin(x);
	cout << endl << endl;
	
	g = sel_sort(x);
	printall(g);
	
	return 0;
}

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector <int> rand_vector(int min, int max, unsigned int size)
{
	vector <int> v(size);
	for (unsigned int x =0; x < size; x++)
	{
		v[x] = rand() % (max - min + 1) + min;
		cout << v[x] << " ";
	}
	cout << endl << endl;
	return v;
}

vector <int> sel_sort(vector <int> old)
{
	vector <int> sorted;
	int min;
	int index;
	while (old.size() > 0)
	{
		min = old[0];
		index = 0;
		for (unsigned int x =0; x < old.size(); x++)
		{
			if (min > old[x])
			{
				min = old[x];
				index = x;
			}
		}
		cout << min << " " <<  index << endl;
		
		sorted.push_back(min);
		old.erase(old.begin() + index);

	}
	
	return sorted;
}

vector <int> mergesort(vector <int> vec, vector <int> temp, int n)
{
	if (vec.size() == 1)
		return vec;
	
	
	return vec;
}

int main(){
	vector<int> nums;
	vector<int> sorted;
	const int MIN = 0;
	const int MAX = 99;
	const int AMOUNT = 20;
	
	
	srand (time(NULL));
	
	nums = rand_vector(MIN, MAX, AMOUNT);
	sorted = sel_sort(nums);
	
	cout << endl;
	for (unsigned int x =0; x < sorted.size(); x++)
	{
		cout << sorted[x] << " ";
	}

}

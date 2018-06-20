#include <vector>
#include <iostream>
using namespace std;

int main()
{
	/* // ONLY WORKS IN C++11 
	vector <int> x = {1,2,3};
	vector <int> y ({1,2,3});
	vector <int> z {1,2,3};

	for (auto i : x)
		cout << i << endl;
		*/
		


	vector <int> v;
	vector <int> k(10,1); //makes 10 slots and fills all with ones
	v.push_back(1);
	v.push_back(2);
	for (int i = 0; i < 5; i++)
		v.push_back(i);
		
		
		
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << endl;//prints out contents
	
	cout << endl<< endl;
	
	for (unsigned int i = 0; i < k.size(); i++)
		cout << k[i] << endl;

	
}

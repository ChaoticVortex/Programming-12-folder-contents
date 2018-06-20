#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector <int> v){
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return;
}


int main(){
	int arr[4] = {2,3,5,7};
	vector<int> circprimes;
	circprimes.insert(circprimes.end(), arr, arr+4);
	print(circprimes);
	
	for (int i = 10; i < 100; i++){
		//can try iterating through 1379 as digits and seeing how many and primes for all combinations of that number
		//not sure the difficulty of that but seems easier than taking 
		//all the numbers and keeping (.4)^digits 
		
		
		
		
		
	
	
	}
}

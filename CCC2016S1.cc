#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

/*
//attempt 1
int main(){
	map < char, int> values;
	string inp1,inp2;
	bool anagram = true;
	
	cin >> inp1 >> inp2;
	for (int i = 0; i < inp1.size(); i++){
		values[inp1[i]] += 1;
	}
	for (int i = 0; i < inp2.size(); i++)
		values[inp2[i]] -= 1;
	
	for (int i = 0; i < values.size(); i++){
		if (values[inp1[i]] < 0){
			anagram = false;
		}
		else if (values[inp2[i]] < 0){
			if (inp2[i] != '*')
				anagram = false;
			
		}
	}
	if (anagram == true)
		cout << "A";
	else
		cout << "N";
	
	cout << endl;

}
*/

//attempt 2
int main(){
	map <char, int> values;
	string inp1,inp2;
	bool anagram = true;
	
	cin >> inp1 >> inp2;
	
	set<char> s1(inp1.begin(), inp1.end());
	set<char> s2(inp2.begin(), inp2.end());
	
	for (int i = 0; i < s1.size(); i++){
		cout << s1;
	}
	
	
}

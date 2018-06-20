#include <iostream>
#include <string>
using namespace std;

/*
.size() returns int
.at() or [] returns char 
.append()
.insert()
.replace()
.c_str()
.find()
.substr()
*/

int main()
{	
	string st ("Hello world!");
	string str;
	string f;
	int pos;
	string rphrase;
	string nphrase;
	
	cout << "The string is: " << st << endl
	<< "The size is: " << st.size() << endl
	<< "The second letter is: " << st.at(1) << endl;
	cout << "Please insert a line here: "; getline(cin, str);
	cout << "Please insert the word or phrase to replace: "; getline(cin, rphrase);
	cout << "What would you like to replace it with? "; getline(cin, nphrase);
	
	/*
	//fails if the replaced word contains the deleted one
	while (str.find(rphrase) != string::npos)
	{
		pos = str.find(rphrase);
		str.replace(pos, rphrase.size(), nphrase);
	}
	*/
	
	int newsize(nphrase.size());
	pos = 0 - newsize;
	while (str.find(rphrase, pos+newsize) != string::npos)
	{
		pos = str.find(rphrase, pos+newsize);
		str.replace(pos, rphrase.size(), nphrase);
	}
	
	cout << "Your new line is: " << str << endl;
	return 0;
}

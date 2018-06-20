#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string word;
	string temp;
	int index1 = 0;
	int index2 = 0;
	vector <string> file1;
	vector <string> file2;
	vector <string> answer;
	ifstream f;
	
	//initialize the vectors
	f.open("f1.txt", ios::in);
	while ( getline(f, word)){
		file1.push_back(word);
	}
	f.close();
	
	f.open("f2.txt", ios::in);
	while ( getline(f, word)){
		file2.push_back(word);
	}
	f.close();
	

	while (file1.size() > 0 && file2.size() > 0){
		index1 = 0;
		index2 = 0;
		for (int i = 1; i < file1.size(); i++)
			if (file1[i].size() < file1[index1].size())
				index1 = i;
				
		for (int i = 1; i < file2.size(); i++)
			if (file2[i].size() < file2[index2].size())
				index2 = i;
		
		if (file2[index2].size() < file1[index1].size()){
			answer.push_back(file2[index2]);
			file2.erase(file2.begin() + index2);
		}
		else{
			answer.push_back(file1[index1]);
			file1.erase(file1.begin() + index1);
		}
	}

	while (file1.size() > 0){
		cout << index1;
		for (int i = 1; i < file1.size(); i++)
			if (file1[i].size() < file1[index1].size())
				index1 = i;
		answer.push_back(file1[index1]);
		file1.erase(file1.begin() + index1);
	}
	
	while (file2.size() > 0){
		index2 = 0;
		for (int i = 1; i < file2.size(); i++)
			if (file2[i].size() < file2[index2].size())
				index2 = i;
		answer.push_back(file2[index2]);
		file2.erase(file2.begin() + index2);
	}
	
	ofstream outf;
	outf.open("output.txt", ios::out);
	for (unsigned int x=0; x < answer.size(); x++)
		outf << answer[x] << endl;
	outf.close();
	
	
	return 0;
}

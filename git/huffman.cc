#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

map <char, int> m;
map <char, string> pathymcpathface;

struct node{
	int c; //represents the value
	string text;
	node* left;
	node* right;
	string path;
	
	//bool operator<(conc node &rhs) conc{
	//	return ( c < rhs.c );
	//}
};

void prewalk(node* nd){
	if (nd == 0)
		return;
	cout << nd -> c << ' ';
	prewalk(nd -> left);
	prewalk(nd -> right);
}
void postwalk(node* nd){
	if (nd == 0)
		return;
	postwalk(nd -> left);
	postwalk(nd -> right);
	cout << nd -> c << ' ';
}

void bfirstwalk(node* root){
	queue <node*> q;
	node* n;
	q.push(root);
	while (!q.empty() ){
		n = q.front();
		cout << n -> c << " " << n->text << " " << n-> path << ", " ;
		if (n -> left != 0)
			q.push(n -> left);
		if (n -> right != 0)
			q.push(n -> right);
			
		q.pop();	
	}
	cout << endl;
	
}

void inwalk(node* nd){
	if (nd == 0)
		return;
	inwalk(nd -> left);
	cout << nd -> c << ' ';
	inwalk(nd -> right);
}

node* NewNode(int c, string text = ""){
	node* np = new node;
	np->c = c;
	np->text = text;
	np->left = 0;
	np->right = 0;
	return np;
}

/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, int c){  // inserts with order
	if (nd == 0){
		nd = NewNode(c);
		return;
	}
	if (c < nd -> c)
		insert(nd -> left, c);
	else
		insert(nd -> right, c);
}

	
void lfree(node* root){ //which order should deleting be: (pre, in, post ) only one of them will work
	if (root == 0)
		return;
	lfree(root -> left);
	lfree(root -> right);
	delete (root);
}

void printMap(map<char,int> mapp){
	for (auto p:mapp)
		cout << p.first << " -> " << p.second << endl;
	return;
}


void countCharacters(string s){
	for (unsigned int i = 0; i < s.size(); i++){
		if (m.find(s[i]) == m.end()){
			m.insert(pair<char,int>(s[i],1));
		}
		else{
			m.find(s[i]) -> second++;
		}
	}
}

int findSmallest( vector <node*> nodes){
	int smallest = 0;
	for (unsigned int i = 0; i < nodes.size(); i++){
		if (nodes[i] -> c < nodes[smallest] -> c)
			smallest = i;
	}
	return smallest;
}

void printPaths(vector <node*> nodes){
	for (unsigned int i = 0; i < nodes.size(); i++)
		cout << nodes[i] -> text << ' ' << nodes[i] -> path << endl;
}

string encode(string str){
	string result = "";
	vector <node*> nodes;
	vector <node*> leafnodes;
	int left;
	int right;
	node* temp;
	node* leftnode;
	node* rightnode;
	node* parent;
	node* root;
	
	countCharacters(str);
	
	//checking to make sure countCharacters works
	/*
	for (auto p: m){
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	*/
	
	//emptying the map into node in the vector tree
	map <char, int>::iterator it;
	while (!m.empty()){
		it = m.begin();
		temp = NewNode(it -> second, string(1, it -> first));
		nodes.push_back(temp);
		leafnodes.push_back(temp);
		m.erase(it);
	}
	
	// checking to see it was done correctly
	/*
	for (unsigned int i = 0; i < nodes.size(); i++){
		cout << nodes[i] -> text << ' ' << nodes[i] -> c << endl;
	}
	*/

	//turning the vector of nodes into a binary tree
	while (nodes.size() > 1){
		//find the left and right nodes and remove them from the vector
		left = findSmallest(nodes);
		leftnode = nodes[left];
		nodes.erase(nodes.begin() + left);
		right = findSmallest(nodes);
		rightnode = nodes[right];
		nodes.erase(nodes.begin() + right);
		
		//make a parent and add this parent back to the vector
		parent = NewNode( leftnode->c + rightnode->c, leftnode-> text + rightnode->text);
		parent->left = leftnode;
		parent->right = rightnode;
		nodes.push_back(parent);
	}
	
	//making sure it was done correctly
	root = nodes[0];
	root -> path = "";
	
	//bfirstwalk(root);
	//assign each a path using breadth-first algorithm
	queue <node*> pathing;
	node* n;
	pathing.push(root);
	while (!pathing.empty() ){
		n = pathing.front();
		if (n -> left != 0){
			n-> left -> path = n-> path + "0";
			pathing.push(n -> left);
		}
		if (n -> right != 0){
			n-> right -> path = n-> path + "1";
			pathing.push(n -> right);
		}	
		pathing.pop();	
	}
	
	/*
	cout << endl;
	printPaths(leafnodes);
	*/
	
	//turn the leaf nodes into a map for faster lookups
	for (unsigned int i = 0; i < leafnodes.size(); i++){
		temp = leafnodes[i];
		pathymcpathface.insert(pair<char,string>(leafnodes[i] -> text[0] , leafnodes[i] -> path));
	}
	
	lfree(root);
	//cout << endl;

	//checking to make sure this new map works
	
	for (auto p: pathymcpathface){
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	
	
	for (unsigned int i = 0; i < str.size(); i++){
		result += pathymcpathface.find(str[i]) -> second;
	}
	
	cout << result << endl;	
	
	return result;
}

string decode(string str){
	unsigned int i = 0;
	string result = "", temp = "";
	
	while (i < str.size()){
		temp += str[i];
		for (auto p: pathymcpathface){
			if (temp == p.second){
				result += p.first;
				temp = "";
			}
		}
		i++;
	}
	return result;
}

int main(){
	string str = "mississippi river";
	clock_t begin = clock();
	string encoded = encode(str);
	string decoded = decode(encoded);
	clock_t end = clock();
	cout << str << endl << encoded << endl << decoded << endl << "Time used: " << double(end - begin) / CLOCKS_PER_SEC << endl;
	return (0);
}


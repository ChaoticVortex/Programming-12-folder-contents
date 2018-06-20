#include <iostream>
#include <string>

using namespace std;

struct node{
	string st;
	node* next;
};

int main(){
	node a,b,c; //initializes nodes and then set them to values
	a.st = "one";
	b.st = "two";
	c.st = "three";
	
	a.next = &b; //link the nodes such that a.next points to b and b.next points to c
	b.next = &c;
	c.next = 0;// in a linked list the last pointer should ALWAYS point to 0.
	
	node* root;// make a pointer to the first thing in the list
	root = &a; 

	cout << (*root).st << endl;
	cout << root -> st << endl; // this is equivalent but better 
	cout << root -> next -> st << endl; //gets to the second number
	cout << root -> next -> next -> st << endl;
}

#include <iostream>
#include <string>

using namespace std;

struct node{
	string st;
	node* next;
};


void walk(node* n){
	if (n != 0){
		cout << n -> st << endl;
		walk( n-> next);
	}
	else
		return;
}


void moonwalk(node* n){
	if (n != 0){
		moonwalk(n-> next);
		cout << n -> st << endl;
	}
	else
		return;
}

void release(node*n){
	if (n!=0){
		release(n -> next);
		delete n;
	}
}


int main(){
	node* root;
	root = new node;
	root -> st = "zero";  //assigns zero to st: real counting this time none of that fake zero shit
	root -> next = new node; //makes a new node and assigns it to next
	root -> next -> st = "one";
	root -> next -> next = new node;
	root -> next -> next -> st = "two";
	root -> next -> next -> next = 0; //linked list should always end with 0 as a pointer
	
	cout << root -> st << endl;
	cout << root -> next -> st << endl;
	cout << root -> next -> next -> st << endl;
	
	cout << endl << endl;
	
	walk(root);
	cout << endl << endl;
	moonwalk(root);
	
	/*
	delete root -> next -> next; // FREE THE MEMORY
	delete root -> next; // LET IT GO FREEEEEEEE FREEEEEEEEEEEEEEEEEED
	delete root; //goodbye memory my old friend ;_;
	*/
	release(root); //yenno what recursion is so much better anyway fuck that shit
}

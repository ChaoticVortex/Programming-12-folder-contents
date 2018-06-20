
#include <iostream>
using namespace std;

struct node{
	// node(st, next) //ctor 
	string st;
	node* next;
};

void walk(node* nd){
	if (nd==0) return;
	cout<< nd->st <<" ";
	if (nd->next  !=0 )
		walk(nd->next);
}

int length(node* nd){
	if (nd == 0) return 0;
	return 1 + length(nd -> next);
}

node* NewNode(string s){
	node* np = new node;
	np->st = s;
	np->next = 0;
	return np;
}
	
//better to set ctor
/*
node::node(string s, node* np = 0){
	st = s;
	next= np;
}
*/

//Must pass nd by ref or seg fault. We must change root node address in main.
void pushfront(node* &nd, string s){ 
	node* n = NewNode(s);
	n -> next = nd;	
	nd = n;
	return;
}


void popfront(node* &nd){
	node* newroot = nd->next;
	delete(nd);
	nd = newroot;
	return;

}


/*can't pushback on root=0 since no node exists yet. So must check for it.
copy ctor called for nd pointer so root in main not changed. This is 
okay if one node already exists since we just add to the end of it.
But if no node exists yet (root=0) then we must change root addr so we
have to pass by ref also.*/

void pushback(node* &nd, string s){ 
	if (nd == 0){
		nd = NewNode(s);
		return;
	}
	pushback(nd -> next, s);


}


void popback(node* &nd){
	if (nd -> next == 0){
		delete(nd);
		nd = 0;
		return;
	}
	popback(nd -> next);
}


/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, string s){ 
	node* p = nd;
	nd = NewNode(s);
	nd -> next = p;
}

	
void lfree(node* nd){
	if (nd != 0){
		lfree(nd -> next);
		delete(nd);
	}
}
	


int main(){
	
	const char* sarray[6] = {"b","d","a","e","f","c"};
	node* root=0;
	int x;
	for (x=0; x<6 ; x++)
	{
		pushback(root, sarray[x]);
		pushfront(root, sarray[x]);
		insert(root, sarray[x]);
		walk(root);
		cout<<endl;
	}
	for (x=0; x<3 ; x++)
	{
		cout<<"popfront"<<endl;
		popfront(root);
		walk(root);
		cout<<endl;
	}
	insert(root, "zoo");
	walk(root);
	cout<<endl;	
	for (x=0; x<3 ; x++)
	{
		cout<<"popback"<<endl;
		popback(root);
		walk(root);
		cout<<endl;
	}
	pushback(root, "zzz");
	walk(root);
	cout<<endl;
	
	lfree(root);
	return 0;
}

	

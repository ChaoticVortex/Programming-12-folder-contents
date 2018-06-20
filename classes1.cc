#include <iostream>
using namespace std;

class Animal{
public:
	void growl();
	int age;
};

void Animal::growl(){ //:: is scope resolution operator
	cout << "grr" << endl;
}

class Dog: public Animal {
public:
	void bark();
};

void Dog::bark(){
	cout << "ruf ruf ruf" << endl;
}

int main(){
	Animal a;
	a.age = 4;
	a.growl();
	cout << "a is "<< a.age << endl;
	Dog d;
	d.bark();
	d.growl();
	
	return 0;
}

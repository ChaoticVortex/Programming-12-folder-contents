#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
	virtual void noise();
	int age;
};

void Animal::noise(){ //:: is scope resolution operator
	cout << "grr" << endl;
}



class Dog: public Animal {
public:
	virtual void noise();
	void bark();
};
//noise method is virtual if we declare it as virtual or not because the base class noise is virtual
inline void Dog::noise(){
	cout << "ruf ruf ruf" << endl;
}
void Dog::bark(){
	cout << "BARK BARK BARK" << endl;
}


class Cat: public Animal{
public:
	virtual void noise(){
		cout << "meow" << endl; //inline since implementation in header
	}
};

void speak(Animal*ap){
	ap -> noise();
}


int main(){
	Animal a;
	a.age = 4;
	cout << "a is "<< a.age << endl;
	a.noise();
	Dog d;
	d.bark();
	d.noise();
	Cat c;
	c.noise();
	
	Animal* ap = &d;
	Dog* dp = &d;
	Cat* cp = new Cat;
	ap -> noise();
	dp -> noise();
	cp -> noise();
	cout << endl << endl;
	
	speak(ap);
	speak(dp); //polymorphism but ONLY occurs with virtual keyword
	speak(cp);
	
	cout << endl << endl;
	
	vector < Animal* > aptrs;
	aptrs.push_back(dp);
	aptrs.push_back(cp);
	
	for (size_t x = 0; x < aptrs.size(); ++x){
		speak(aptrs[x]);
		//aptrs[x]->noise();
	}
	delete cp;
	cp = 0;
	
	return 0;
}

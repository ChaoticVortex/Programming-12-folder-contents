#include <iostream>
#include <cstring>
using namespace std;

class Person {
public:
	Person();
	Person(const Person&);
	Person& operator=(const Person& rhs); // assignment op
	virtual ~Person();
	virtual void noise(){
		cout << "Hello World!" <<endl;
	}
	virtual void story(){
		cout << "Story? What story?" << endl;
	}
	int* age;
	bool* sex;
	string* location;
};
Person::Person(){
	cout << "default person constructor" << endl;
	age = new int; // call new from ctor and delete later
	sex = new bool;
	location = new string;
};
Person::Person(const Person& original){
	cout << "cloning, please wait." << endl;
	age = new int;
	sex = new bool;
	location = new string;
	
	*age = *(original.age);
	*sex = *(original.sex);
	*location = *(original.location);

};
Person::~Person(){
	delete age;
	delete sex;
	delete location;
};
Person& Person::operator=(const Person& rhs){
	
	if (this == &rhs) return *this;
	*age = *(rhs.age);
	*sex = *(rhs.sex);
	*location = *(rhs.location);
	return *this;
};



class Elder : public Person{
public:
	virtual void noise(){
		cout << "Now listen here, sonny." << endl;
	}
	virtual void story(){
		cout << "Back in my day, we used to walk uphill to school, BOTH WAYS!" << endl;
	}
	
};



int main(){
	Person* me = new Person();
	me -> noise();
	me -> story();
	
	cout << endl;
	
	Person* clone = me;
	clone -> noise();
	
	cout << endl;
	
	Person* grandpa = new Elder();
	grandpa -> noise();
	grandpa -> story();
	
	

	
}

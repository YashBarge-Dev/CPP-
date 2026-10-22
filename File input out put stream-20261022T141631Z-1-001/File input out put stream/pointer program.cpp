#include<iostream>
using namespace std;
class Person
{
	private : int age,count;char name[50];
	public : //parameterized constructor
			 Person(int age,char name[])
			 {
			 	strcpy(this->name,name);
			 	this->age=age;
			 	this->count=count;
			 }
			 void show()
			 {
			 	cout<<"\nName="<<name<<"\nAge:"<<age;
			 }
			 //Destructor
			 ~Person()
			 {
			 	cout<<"\n"<<count<<"Object Destroyed";
			 }
};
int main()
{
	Person p1(24,"Stuart",1);
	p1.show();
	Person p2(22,"Broad",2);
	p2.show();
	Person *ptr;// pointer object created
	ptr = new Person(28,"Manhatten",3);
	ptr->show();
	delete ptr;//deallocate the memory for ptr object
	cout<<endl<<ptr;
	ptr=nullptr;
	cout<<endl<<ptr;
	
}
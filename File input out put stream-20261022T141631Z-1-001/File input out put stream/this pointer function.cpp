/*use of *this object*/
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
			 	
			 }
			 void show()
			 {
			 	cout<<"\nName="<<name<<"\nAge:"<<age;
			 }
			 //Destructor
			 Person maxAge(Person obj)
			 {
			 	if(age>obj.age)
			 		return *this;
			 	else
			 		return(obj);
			 }
			 ~Person()
			 {
			 	cout<<"\n"<<count<<"Object Destroyed";
			 }
};
int main()
{
	Person p1(24,"Stuart");
	
	Person p2(22,"Broad");
	Person p(0,"/0");
	p = p1.maxAge(p2);
	p.show();
	
	
}
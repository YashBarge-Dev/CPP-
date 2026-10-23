#include<iostream>
 class Person
{
	protected : string name;
				int age;
	public : 
				void set()
				{
					cout<<"\nEnter Name : ";
					cin>>name;
					cout<<"\nEnter Age : ";
					cin>>age;
				}
				 void display()
				{
					cout<<"\nName : "<<name<<"\nAge : "<<age;
				}
}
class student : virtual public Person
{
	protected : int rollNo;
	public : 	
				void setStudent()
				{
					cout<<"\nEnter Roll no : ";
					cin>>rollNo;
				}
				void display()
				{
					cout<<"\nRoll no : "<<rollNo;
				}
};
class Employee : virtual public Person 
{
	protected : empID;
	public : 	void setEmp()
				{
					cout<<"\nEnter EMployee ID : ";
					cin>>empID;
				}
				void display()
				{
					cout<<"\nEmployee ID : "<<empID;
				}
}
class Teaching_Assistant : public student,public Employee
{
	public : void display()
				{
					setStudent();
					setEmp();
					
				}
				
}
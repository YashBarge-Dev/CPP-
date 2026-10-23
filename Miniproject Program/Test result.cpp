#include<iostream>
 class Student
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
class Sports : virtual public Student 
{
	protected : string sName;
	public : 	
				void setSports()
				{
					cout<<"\nEnter Sports : ";
					cin>>sName;
				}
				void display()
				{
					cout<<"\nRoll no : "<<sName;
				}
};
class Test : virtual public Student 
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
class Result  : public Test ,public Sports
{
	public : void display()
				{
					setStudent();
					setEmp();
					
				}
				
}
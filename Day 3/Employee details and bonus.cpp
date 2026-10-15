#include<iostream>
using namespace std;

class Employee
{
	private : int empID;
			  string name;
			  
	protected :	double salary;
			  
	public : 
				void EmpDetails(int id,string name,double salary)
				{
					this->empID=id;
					this->name=name;
					this->salary=salary;
				}
				
				void displayEmp()
				{
					cout<<"\n EMPLOYEE DETAILS";
					cout<<"\n EMP ID :"<<empID<<"\n Name :"<<name<<"\n Salary :"<<salary;	
				}	
};
class Bonus : public Employee
{
	private : int att_days;
			 double bonus,netSalary;
	
	public : 
				void isPresent()
				{
					cout<<"\n ENter no of attended days"<<endl;
					cin>>att_days;
				    addBonus();
				}
				void addBonus()
				{
					
					if(att_days>200)
					{
						bonus = 0.10 * salary;
						netSalary = salary + bonus;
						cout<<"\n Net Salary : "<<netSalary;
					}
					else
					{
						bonus = 0.065 * salary;
						netSalary = salary + bonus;
						cout<<"\n Net Salary : "<<netSalary;
					}
					
				}
};

int main()
{
	Bonus Emp1;
	Emp1.EmpDetails(101,"Yash",50000);
	Emp1.displayEmp();
	Emp1.isPresent();
	
}
/*problem :
Write a c++ program to store employee id,name, and badic salary.
Calculate an display salary assuming an allowance of 20% of basic salary.*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Employee
{
	public : int EmpID;string name;double salary,allowance,netSalary;
	
			void setDetails()
			{
				cout<<"\nEnter Name:";
				cin>>name;
				cout<<"\nEnter Emp ID : ";
				cin>>EmpID;
				cout<<"\nEnter Salary : ";
				cin>>salary;
				allowance = salary * 0.2;
				netSalary = salary -allowance;
				
			}
			void getDetails()
			{
				cout<<"\nName : "<<name <<"\nEMP ID : "<<EmpID <<"\nSalary : " <<salary<<"\nNet Salary : "<<netSalary;
			}
};

int main()
{
	Employee emp;
	int choice;
	do{
		cout<<"\n1.Enter Employee Details\n2.DisplayEmployee Details\n3.Exit";
		cout<<"\nEnter Choice : ";
		cin>>choice;
		
		if(choice==1)
		{
			ofstream file("Employee.txt",ios::app);
			emp.setDetails();
			file<<emp.name<<"\t"<<emp.EmpID<<"\t"<<emp.salary<<"\t"<<emp.netSalary<<endl;
			
			file.close();
			cout<<"\nRecord added successfully";
			
		}
		 else if (choice == 2) 
		{
            ifstream file("Employee.txt");

            while (file >> emp.name >> emp.EmpID >> emp.salary >> emp.netSalary) 
			{
                emp.getDetails();
            }

            file.close();
        }

    } while (choice != 3);

}
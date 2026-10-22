#include<iostream>
#include<fstream>
using namespace std;
class student
{
	public : int rollNo;string name;float marks;
				void input()
				{
					cout<<"\nEnter your Name :";
					cin>>name;
					cout<<"\nRoll No :";
					cin>>rollNo;
					cout<<"\nMarks : ";
					cin>>marks;
				}
				void output()
				{
					cout<<"\nName : "<<name<<"\tRoll no : "<<rollNo<<"\tMarks : "<<marks;
				}
};
int main()
{
	student s;
	int choice =0;
	do{
		cout<<"\n1.Enter Student Details\n2.Display Student Details\n3.Exit";
		if(choice==1)
		{
			ofstream file("students.txt",ios::app);
			s.input();
			
			file<<s.name<<" "<<s.rollNo<<" "<<s.marks<<endl;
			
			file.close();
			cout<<"\nRecord added successfully";
			
		}
		else if(choice==2)
		{
			ifstream file("students.txt");
			s.output();
			
			file>> s.name >> s.rollNo >> s.marks;
			
			file.close();
		}
		else
		{
			cout<<"\nExited";
		}
	}while(choice!=3);
}
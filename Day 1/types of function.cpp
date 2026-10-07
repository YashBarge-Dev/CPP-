#include<iostream>
using namespace std;

//after include and before main is the global area
void my_function()//type 1: not accepting parameters, not returning a value. 
{
	cout<<"\n\t\t hi i am my function: called by you";
}
void my_function2(string n)//type 2 : accepting parameters, not returning a value
{
	cout<<"\n\t\thi, "<<n;
}
string copyright()//type 3 : not accepting a value but returning a value
{
	return "Code created by Amar Panchal. ";
}
string initials(string first_name,string last_name)//type 4 :accepting parameters and returning a calculated value 
{
	string init="";
	init+=first_name[0];
	init+=last_name[0];
	return init;
}

//Global area ends

int main()
{
	cout<<"\nStart in the main part. ";
	cout<<"\nSome code, some logic. ";
	my_function();
	my_function2("amar");
	cout<<"\n\t\tInfo:"<<copyright();
	cout<<"\n\t\tAmar Panchal initials:"<<initials("apoorva","borude");
	cout<<"\nEnd in main part";
   return 0;
}

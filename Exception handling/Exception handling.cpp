/*exception handling*/
#include<iostream>
using namespace std;
int main()
{
	try{
		int age=25;
		if(age<18)
		throw age;
		cout<<"\nYou are eligible to vote";
	}
	catch(int x)
	{
		cout<<"\nException : Age is less than 18";	
	
	}
	int marks; 
	cout<<endl<<"Enter Number to check whether it is in the defined measure\n";
	cin>>marks;
	try{
		if(marks<50 || marks>90)
		throw marks;
		cout<<"\n These are the students who are passed and eligible for exam";
	}
	catch(int m)
	{
		cout<<"\n The students have not met the eligibilty criteria";
	}
}
/*int float char  exception */
#include<iostream>
using namespace std;
int main()
{
	int choice;
	cout<<"\nEnter Choice : ";
	cin>>choice;
	try{
		if(choice==1)
		throw 100;//int data is declrared so it is valid and throws the exception that was defined 
		if(choice==2)
		throw 42.5; //char datatype is declared so it throws system exception of char
		if(choice==3)
		throw " Words and sentences included";//string data is declared do it throws system char const* exception
	}
	catch(int ch)
	{
		cout<<"\nInteger Exception : "<< ch;
	}
	catch(double f)
	{
		cout<<"\nFloat Exception : "<< f;
	}
	catch(const char *message)
	{
		cout<<"\nString  Exception : "<< message;
	}
}
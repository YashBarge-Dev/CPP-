/*Withdrawal exception */
#include<iostream>
using namespace std;
int main()
{
	int amount,balance = 25000;
	cout<<"\nEnter amount to withdraw : ";
	cin>>amount;
	try{
		if(amount<=0)
		throw "Balance is Negative or 0";//int data is declrared so it is valid and throws the exception that was defined 
		if(amount>balance)
		throw "The amount Exceeds the limit of the balance remaining"; //char datatype is declared so it throws system exception of char
		if(amount<=balance || amount>0)
		balance = balance - amount;
		cout<<"\nWithdrawal successfull";
		cout<<"\nRemaining Balance : "<<balance;
		throw "Available for Withdrawal";//string data is declared do it throws system char const* exception
		
	}
	catch(const char *message)
	{
		cout<<"\n Exception : "<< message;
	}
}
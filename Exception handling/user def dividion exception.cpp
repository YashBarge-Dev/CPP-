/*Division exception */
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"\nEnter a : ";
	cin>>a;
	cout<<"\nEnter b : ";
	cin>>b;
	try{
		if(b==0)
		throw "Divison By 0 is not allowed\n Result is Infinity";
		cout<<"\nResult ="<<a/b;
	}
	catch(const char *message)
	{
		cout<<"\nException : "<< message;
	}
}
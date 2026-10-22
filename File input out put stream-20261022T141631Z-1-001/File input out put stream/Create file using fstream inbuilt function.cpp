/*Create a file and fill the details using fstream functions */

#include<iostream>
#include<fstream>
using namespace std;
main()
{
	char str[100];
	ofstream obj;
	obj.open("Personal.txt");
	obj<<"\n Name :  Barge Yash Uday";
	obj<<"\nQualification : BE COMP";
	obj<<"\nSalary : 50000";
	obj<<"\nExperience : 4 years";
	obj.close();
	cout<<"\nFile Created";
	ifstream in;
	in.open("Personal.txt");
	while(in)
	{
		in.getline(str,50);
		cout<<"\nFile Data : "<<str;
	}
}
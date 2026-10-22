/*Create a product file stpre 5 product info name cost */

#include<iostream>
#include<fstream>
using namespace std;
main()
{
	char str[100];
	ofstream obj;
	obj.open("Product.txt");
	obj<<"\n Product (1) :  Steering";
	obj<<"\nCost : 5000 Rs";
	obj<<"\n Product (2) :  Handbrake";
	obj<<"\nCost : 2500 Rs";
	obj<<"\n Product (3) :  Rear Wheels";
	obj<<"\nCost : 8000 Rs";
	obj<<"\n Product (4) :  Fog Lamp";
	obj<<"\nCost : 12000 Rs";
	obj<<"\n Product (5) :  Backlight";
	obj<<"\nCost : 15000 Rs";
	obj.close();
	cout<<"\nFile Created";
	ifstream in;
	in.open("Product.txt");
	while(in)
	{
		in.getline(str,250);
		cout<<"\nFile Data : "<<str;
	}
}
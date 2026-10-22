
#include<iostream>
using namespace std;
main()
{
	cout.fill('-');
	/*fill() : It fills the vacant space with specified character
	  syntax : cout.fill("") */
	cout.width(10);
	/* width() : it is used to set width and store the given value or character
   syntax: cout.width(n); */ 
	cout<<"NAME";
	cout.fill('-');
	cout.width(20);
	cout<<"CONTACT NO";
	/*Precision : It is used to set floating precision places
	synrax : cout.precision(n) */
	float a = 7548.5454f;
	cout.precision(6); 
	cout<<a;
	
	
	
}
/*1. Dynamic Array and Average
	Write a C++ program that:
? Asks the user for the number of elements.
? Dynamically allocates an integer array using new.
? Accepts the elements using a pointer.
? Calculates and displays the sum and average of the elements.
? Releases the allocated memory using delete[].
	Concepts: Dynamic memory allocation, pointers, arrays.*/
	
#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter no of elements :\n";
	cin>>n;
	int *arr = new int[n];
	cout<<"Enter the "<< n <<"NUMBER TO BE STORED\n";
	for(int i =0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	
	
	//Calculating sum
	int sum = 0;
	for(int i =0;i<=n;i++)
	{
		sum+=*(arr+i);
	}
	
	//calculate avg
	double avg = static_cast<double> (sum)/n;
	
	//output
	cout<<" Sum :"<<sum<<endl;
	cout<<" Average :"<<avg<<endl;
	
	delete[] arr; 
	return 0;
}
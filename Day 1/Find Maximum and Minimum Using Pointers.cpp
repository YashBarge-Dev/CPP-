/*2. Find Maximum and Minimum Using Pointers
Write a C++ program that dynamically creates an array of n integers. Use only pointer arithmetic to:
? Read the elements.
? Find the largest element.
? Find the smallest element.
? Display both values.
? Properly deallocate the memory.
Restriction: Do not use array indexing such as arr[i].
Concepts: Pointers, pointer arithmetic, dynamic arrays.*/

#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter No of elements"<<endl;
	cin>>n;
	int *arr = new int(n);
	for(int i =0;i<n;i++)
	{
		cin>>*(arr + i)
	}
}
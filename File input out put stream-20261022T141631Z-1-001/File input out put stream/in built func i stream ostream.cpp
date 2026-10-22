#include<iostream>
using namespace std;
main()
{
	char ch;
	int count=0;
	cout<<"\n Enter Data :";
	cin.get(ch);
	while(ch!='\n')
	{
		cout.put(ch);
		cin.get(ch);
		count++;
	}
	cout<<"\n Total CHaracteres : "<<count;
}
#include<iostream>
using namespace std;
main()
{
	char str[50];
	cout<<"\n Enter string: ";
	cin>>str;
	cout<<"\n String :" <<str;
	cout<<"\n Enter string: ";
	cin.getline(str,20);
	cout<<"\n String "<<str;
	cout<<"\n Print :";
	cout.write(str,5);
	
	for(int i=0;i<strlen(str);i++)
	{
		for (int j=0;j<=i;j++)
		{
			cout.write(str,j);
		}
		cout<<"\n";
	}
}
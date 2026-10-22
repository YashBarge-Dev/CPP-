/*  store numbers in file  and apply file functions
ios::ate
ios::beg
seekg()
tellg() */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout("Number.txt");
	for(int i =1;i<=10;i++)
	{
		fout<<i<<endl;
	}
	fout.close();
	
	ifstream file("Number.txt",ios::in | ios::ate);
	cout<<"File Operator position : "
		<< file.tellg() <<endl;
	file.seekg(0,ios::beg);
	int number;
	cout<<"\nFile Contents:\n";
	while(file>>number)
	{
		cout << number << " ";
	}
	
	file.close();
	return 0;
}
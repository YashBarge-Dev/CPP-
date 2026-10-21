/*Write a program to scan string and and and copy the string ny using call by reference */
#include<iostream>
using namespace std;
void copystr(char *str1,char *str)
{
	while(*str!='0')
	{
		*str1 = *ptr;
		str++;
		str1++;
	}
	*str1 = '0';
}
 int main()
 {
 	char str[100];
	int copy;
	cout<<"Enter String = ";
	gets(str);
	cout<<"\nString ="<<str;
	cout<<"\nLength of String ="<<strlen(str);//std function
 }
  
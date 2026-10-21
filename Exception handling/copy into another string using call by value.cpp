/*
write a program scan string and copy into another string using call by value
*/
#include<iostream>

using namespace std;

int length(char str[]){
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}
int mylength(char *str){
	int i = 0;
	while(*str != '\0')
	{
		i++;
		str++;
	}
	return i;
}
main(){
	char str[100];
	int mylen;
	cout<<"Enter String = ";
	gets(str);
	cout<<"\nString ="<<str;
	cout<<"\nLength of String ="<<strlen(str);//std function
	
	mylen = length(str);
	cout<<"\nCall by value = "<<mylen;

	mylen = mylength(str);
	cout<<"\nCall by refernce = "<<mylen;
}
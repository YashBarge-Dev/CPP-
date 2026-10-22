/* create two files where country details are stored on file 1 and capital in file 2 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Country
{
	public : string cName,capital;
			 void addCountry()
			 {
			 	cout<<"\nEnter the country :";
			 	getline(cin,cName);
			 }
			 void addCapital()
			 {
			 	cout<<"\nEnter Captial of the country :";
			 	getline(cin,capital);
			 }
			 
};
int main()
{
	ofstream countryFile("countryFile1.txt");
	ofstream capitalFile("capitalFile2.txt");
	
	
	
}
/*problem :
Write a c++ program to store Book ID title and author and availability status
Program should allow adding and displaying books*/

#include<iostream>
#include<fstream>

using namespace std;
class Test
{
	public : int counter=1;string line;
	
			void setDetails()
			{
			cout<<"\n Enter Your information :"
			getline(cin>>ws,line);
			counter++;
			
			}
			void getDetails()
			{
				cout<<line;
			}
};

int main()
{
	Test t;
	

			ofstream file("Test.txt",ios::app);
			t.setDetails();
			file<<counter<<line<<endl;
			
			file.close();
			
			ifstream file("Test.txt");
				ofstream file("File1.txt",ios::app);
				if(counter<=5)
				{
					getline(cin>>ws,line);
				}
				else
				{
					getline(cin>>ws,line);
				}
				
				file.close();

}
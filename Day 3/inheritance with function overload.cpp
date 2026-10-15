#include<iostream>
using namespace std;
class Base
{
	public :
			void show()
			{
				cout<<"\nBase class";
			}
};
class sub : public Base
{
	public : 
			void show()
			{
				
				cout<<"\n child class";
			}
};
int main()
{
	sub myobj;
	myobj.show();
	
}
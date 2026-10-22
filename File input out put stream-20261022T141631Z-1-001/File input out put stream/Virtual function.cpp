/*use of virtual function*/
#include<iostream>
using namespace std;
class Base
{
	public : virtual  void show()
				{
					cout<<"\nshow base class";
				}
				void display()
				{
					cout<<"\nDisplay base Class";				
				}
};
class derived : public Base
{
	public : void show()
				{
					cout<<"\nshow child class";
				}
				void display()
				{
					cout<<"\nDisplay child Class";		
				}
};
int main()
{
	Base b_obj,*bptr;
	derived d_obj;
	bptr= &b_obj;//bptr is pointing the object of base class b_obj
	bptr->show();
	bptr->display();
	bptr=&d_obj;//bptr is pointing the object of base class d_obj
	bptr->show();
	bptr->display();
	
}
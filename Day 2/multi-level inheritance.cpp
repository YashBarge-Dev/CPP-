
//In C++ if the constructor of a derived class is called, it by default activates the constructor of the superclass, as seen in the following example. 
#include <iostream>
using namespace std;

// Base Class
class A
{
	public:
	A()
	{
		cout<<"\nA here";
	}
};
class B:public A
{
	public:
	B()
	{
		cout<<"\nB : i am here";
	}
};

class C:public B
{
	public:
	C()
	{
		cout<<"\nC : yes i m done";
	}
};

int main()
{
    C obj;
    return 0;
}

#include<iostream>
using namespace std;

class Father
{
public:
    void life()
    {
        cout << "Father teaches life." << endl;
    }

    void eat()
    {
        cout << "Father eats non-veg." << endl;
    }
};

class Mother
{
public:
    void love()
    {
        cout << "Mother teaches love." << endl;
    }

    void eat()
    {
        cout << "Mother eats veg only." << endl;
    }
};

class Child : public Father, public Mother
{
	public:
		void eat()
		{
			Father::eat();//Resolving ambiguity by deciding to take property only from the father 
		    Mother::eat();
			cout<<"Child: eats chines.......everything";
		}
};

int main()
{
    Child c;

    c.life();   // No ambiguity
    c.love();   // No ambiguity

    c.eat();    // AMBIGUITY!--resolved by your call

    return 0;
}

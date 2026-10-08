#include <iostream>
using namespace std;

class Father
{
public:
    void life()
    {
        cout << "Father teaches life." << endl;
    }
};

class Mother
{
public:
    void love()
    {
        cout << "Mother teaches love." << endl;
    }
};

class Child : public Father, public Mother
{
};

int main()
{
    Child c;

    c.life();   // Father
    c.love();   // Mother

    return 0;
}

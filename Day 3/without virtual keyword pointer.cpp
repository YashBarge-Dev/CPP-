#include <iostream>
using namespace std;

class Animal
{
public:

    void sound()
    {
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal
{
public:

    void sound()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:

    void sound()
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal *ptr;
	Animal a;
	ptr=&a;
	ptr->sound();//Ideally refers to the sound of an animal. 
	
    Dog d;
    ptr = &d;
    ptr->sound();//Ideally should refer to the sound of a dog. 

    Cat c;
    ptr = &c;
    ptr->sound();//Ideally should refer to the sound of a cat. 

    return 0;
}

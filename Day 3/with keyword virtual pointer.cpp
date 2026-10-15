//solution
#include <iostream>
using namespace std;

class Animal
{
public:

    virtual void sound()
    {
        //cout << "Animal makes sound" << endl;
        //with no code using virtual class will make the class abstract
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
	ptr->sound();//it refers to the sound of an animal. 
	
    Dog d;
    ptr = &d;
    ptr->sound();//it refer to the sound of a dog. 

    Cat c;
    ptr = &c;
    ptr->sound();//it should refer to the sound of a cat. 

    return 0;
}

#include <iostream>
using namespace std;

class Human
{
private:
    string name;
    int age;
public:
	void setHuman(string name,int age)
	{
		this->name=name;
		this->age=age;
	}
    void displayHuman()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Human
{
private:
    int rollNo;
public:
void setStudent(string name,int age,int rollNo)
	{
		setHuman(name,age);
		this->rollNo=rollNo;
	}
    void displayStudent()
    {
    	displayHuman();
        cout << "Roll No: " << rollNo << endl;
    }
};

int main()
{
    Student s;
/*Setting of private data is not allowed because private is not inherited. 
    s.name = "Rahul";
    s.age = 20;
    */
	//One can still inherit a public method which has access to private data. 
    s.setStudent("rahul",20,101);
    s.displayStudent();

    return 0;
}


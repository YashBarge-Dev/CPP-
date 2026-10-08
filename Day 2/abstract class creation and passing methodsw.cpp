#include<iostream>
using namespace std;

class Human {
	
	private :
		int age;
		string gender;
		string name;
		
	public :
		
		void set_human(string name,string gender,int age)
		{
			this->name=name;
			this->gender=gender;
			this->age=age;
		}
		
		void display_human()
		{
			cout<<"\n Hi, I am "<<name<<", a "<<gender<<",age "<<age;	
		}
};

int main()
{
	Human h;
	h.set_human("Superman","Male",32);
	h.display_human();
	return 0;
}
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
			can_vote(); //nested Function usually for security purposes.
		}
		
		void can_vote()
		{
			if(age>=18)
				cout<<"\n Yes, You can vote";
			else
				cout<<"\n You are not eligible";
		}
};

int main()
{
	Human h;
	h.set_human("Superman","Male",12);
	h.display_human();
	return 0;
}
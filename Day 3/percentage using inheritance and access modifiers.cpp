#include<iostream>
using namespace std;
class FE
{
	private : int roll;
			  string name;
	protected : int m1,m2,m3;
				float feMarks;
	public : 
				void studentInfo()
				{
					cout<<"Roll no and Name\n";
					cin>>roll;
					cin>>name;
					cout<<"\n ENter the marks of 3 subjects";
					cin>>m1;
					cin>>m2;
					cin>>m3;
					feMarks = m1+m2+m3;
				}
				void display()
				{
					cout<<"\n ROll no :"<<roll<<"\nName:"<<name<<"\n M1:"<<m1<<
									"\n M2:"<<m2<<"\n M3:"<<m3;
					cout<<"\n FE Marks"<<feMarks;
				}
};
class SE:public FE
{
	private : float seMarks, total;
			  float perc;
	
	public :
				void Percentage()
				{
					cout<<"\n ENter marks for three subjects for SE";
					cin>>m1>>m2>>m3;
					seMarks = m1+m2+m3;
					cout<<"\n Total marks SE :"<<seMarks;
					total = feMarks + seMarks;
					perc = total / 6;
					cout<<"\n Grand Total "<<total;
					cout<<"\n Percentage :"<<perc;
				}
};
int main()
{
	SE student1;
	student1.studentInfo();
	student1.display();
	student1.Percentage();
}
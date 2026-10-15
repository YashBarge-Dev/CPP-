#include<iostream>
using namespace std;

class base
{
	private : int a,b;
	protected : int c;
	public :
				void set()
				{
					cout<<"\n Enter Value of a and b ";
					cin>>a>>b;
					c = a + b;
				}
				
				void get()
				{
					cout<<"\n The value of c is"<<c;
					cout<<"\n The value of a is "<<a<<"and b is "<<b;
				}
};
class sub:public base
{
	private : int p ,q,ans;
	public :
				void set()
				{
					base::set();
					cout<<"\n ENter values of p and q";
					cin>>p>>q;
					ans = (p * q) + c;
				}
				
				void get()
				{
					base::get();
					cout<<"\n The ans is "<<ans<<" \nThe value of P : "<<p<<"\n The value of Q :"<<q; 
				}
};
int main()
{
	sub obj;
	obj.set();
	obj.get();
	
}
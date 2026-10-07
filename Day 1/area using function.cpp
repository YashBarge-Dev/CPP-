#include <iostream>
using namespace std;
void area(int r)
{
	int area = 3.14 * r * r;
	cout<<"\nArea of circle :"<<area;
	//return 3.14 * r * r;
}
void area(int l, int b)
{
	int rect = l * b ;
	cout<<"\nArea of rectangle "<<rect;
	//return l * b;
}

void area(int l , int b , int h)
{
	return l * b * h;
}

int main()
{
   area(5);
   area(7,8);
    return 0;
}

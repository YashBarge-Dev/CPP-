#include <iostream>
using namespace std;

class Inches;  // Forward declaration It simply informs the compiler that there is a class ahead in compilation which is weak. 

class Feet
{
 private:   
	double feet;

public:
    Feet(int f)
    {
        feet=f;
    }

    friend void addDistance(Feet f, Inches in);
};

class Inches
{
  private:
    double inches;

public:
    Inches(int i)
    {
    	inches = i;
           
    }

    friend void addDistance(Feet f, Inches in);
};

	 void addDistance(Feet f, Inches in)
{
    int totalFeet = f.Feet();
	int totalInches = in.Inches();
	
	totalFeet = totalFeet + (totalInches/12);
	totalInches = 
	
	 
}

int main()
{
    Feet f;
    Inches in;

    addDistance(f,in);

    return 0;
}

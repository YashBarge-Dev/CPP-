#include <iostream>
using namespace std;



class city1
{
private:
    string name;
    double temp;

public:

    void setDetails()
    {
        cout << "Enter City 1 name: ";
        cin >> name;

        cout << "Enter City 1 temperature: ";
        cin >> temp;
    }

    void getDetails()
    {
        cout << "\nCity 1 Name: " << name;
        cout << "\nCity 1 Temperature: " << temp;
    }

    friend class city2;
};


class city2
{
private:
    string name;
    double temp;

public:

    void setDetails()
    {
        cout << "\nEnter City 2 name: ";
        cin >> name;

        cout << "Enter City 2 temperature: ";
        cin >> temp;
    }

    void getDetails()
    {
        cout << "\nCity 2 Name: " << name;
        cout << "\nCity 2 Temperature: " << temp;
    }

    void compare(city1 c1)
    {
        if (c1.temp > temp)
        {
            cout << "\n\nCity 1 temperature is HIGHER.";
        }
        else if (temp > c1.temp)
        {
            cout << "\n\nCity 2 temperature is HIGHER.";
        }
        else
        {
            cout << "\n\nBoth cities have the SAME temperature.";
        }
    }
};


int main()
{
    city1 myCity1;
    city2 myCity2;

    // Input details
    myCity1.setDetails();
    myCity2.setDetails();

    // Display details
    cout << "\n\n--- City Details ---";

    myCity1.getDetails();
    myCity2.getDetails();

    // Compare temperatures
    myCity2.compare(myCity1);

    return 0;
}
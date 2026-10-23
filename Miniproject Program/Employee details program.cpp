#include <iostream>
using namespace std;

class Employee
{
private:
    int empID, ID;
    string empName, Dept;
    double salary, grossSal, PF, profTax, deduction, Exp;

public:
    Employee()
    {
        empID = 0;
        empName = "";
        Dept = "";
        salary = 0;
        grossSal = 0;
        Exp = 0;
    }

    ~Employee()
    {
        cout << "\nThe Employee Object is Successfully destroyed";
    }

    void setEmp()
    {
        cout << "\nEnter Name of the Employee: ";
        cin >> empName;

        cout << "Enter ID: ";
        cin >> empID;

        cout << "Enter the Department: ";
        cin >> Dept;

        cout << "Enter the basic salary: ";
        cin >> salary;

        cout << "Enter the years of experience: ";
        cin >> Exp;
    }

    void displayEmp()
    {
        cout << "\nEmp ID: " << empID
             << "\nEmployee Name: " << empName
             << "\nDepartment: " << Dept
             << "\nBasic Salary: " << salary
             << "\nYears of Experience: " << Exp << endl;
    }

    void grossSalary()
    {
        PF = 0.2 * salary;
        profTax = 200;
        deduction = PF + profTax;
        grossSal = salary - deduction;

        cout << "\nGross Salary of EMP ID: " << empID
             << " Name: " << empName
             << " is: " << grossSal << endl;
    }

    bool searchEmployee(int searchID)
    {
        if (searchID == empID)
        {
            displayEmp();
            return true;
        }
        return false;
    }

    bool isExperienced()
    {
        return Exp >= 5;
    }
};

int main()
{
    Employee emp[100];
    int choice;
    int count = 0;

    do
    {
        cout << "\n\nAMANORA CO";
        cout << "\n1. Add Employee";
        cout << "\n2. Display All Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Calculate Gross Salary";
        cout << "\n5. Display Experienced Employees";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            emp[count].setEmp();
            count++;
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                emp[i].displayEmp();
            }
            break;

        case 3:
        {
            int searchID;
            bool found = false;

            cout << "\nEnter Employee ID to search: ";
            cin >> searchID;

            for (int i = 0; i < count; i++)
            {
                if (emp[i].searchEmployee(searchID))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nEmployee Not Found";

            break;
        }

        case 4:
            for (int i = 0; i < count; i++)
            {
                emp[i].grossSalary();
            }
            break;

        case 5:
            for (int i = 0; i < count; i++)
            {
                if (emp[i].isExperienced())
                {
                    emp[i].displayEmp();
                }
            }
            break;

        case 6:
            cout << "\nExit";
            break;

        default:
            cout << "\nEnter Valid Choice";
        }

    } while (choice != 6);

    return 0;
}




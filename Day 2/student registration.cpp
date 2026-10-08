#include <iostream>
using namespace std;

class Student
{
private:
	static int count;
	int roll_no;
	string name,gender;
public:
	//Create a `register_student` method 
	//which will accept name and gender from the user 
	//print on screen: "Student successfully registered with a roll number auto-generated." 
    void register_student(string name,string gender)
    {
        count++;
        this->name=name;
        this->gender=gender;
        this->roll_no=count;
        cout<<"\nSuccessfully registered. Remember your roll number is "<<roll_no;
    }
	void display_student()
		{
			cout<<"\nRollno:"<<roll_no<<"\tName:"<<name<<"\tGender:"<<gender;
		}
//get_count():Will return total number of students created so far 
 static int get_count()
    {
		return(count);
    }
//get_roll():Return private data, that is, roll number, to outside the main method. 
 int get_roll()
    {
		return(roll_no);
    }
};


int Student::count;

int main()
{
	Student s[100];
	int index=0;
    int ch;
        do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";

        cout << "\n1. Register new student";
        cout << "\n2. Search a student by roll number";
        cout << "\n3. List all the students";
        cout << "\n0. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) // For switch cases use {} after case starting and ending.
        {
            case 1:
            {
                string name;
                string gender;

                cin.ignore();

                cout << "\nYour name: ";
                getline(cin, name);

                cout << "Your gender: ";
                cin >> gender;

                s[index].register_student(name, gender);

                index++;

                break;
            }

            case 2:
            {
                int r_number;

                cout << "\nEnter roll number to search: ";
                cin >> r_number;

                bool found = false;

                for (int i = 0; i < Student::get_count(); i++)
                {
                    if (r_number == s[i].get_roll())
                    {
                        cout << "\nRecord found:\n";
                        s[i].display_student();

                        found = true;
                        break;
                    }
                }

                if (found == false)
                {
                    cout << "\nStudent not found.";
                }

                break;
            }

            case 3:
            {
                cout << "\nTotal Students Registered: "
                     << Student::get_count();

                cout << "\n\nList of Students:";

                for (int i = 0; i < Student::get_count(); i++)
                {
                    s[i].display_student();
                }

                break;
            }

            case 0:
            {
                cout << "\nExiting the system...";
                break;
            }

            default:
            {
                cout << "\nInvalid option selected.";
                break;
            }
        }

    } while (ch != 0);

    return 0;
}

	
	

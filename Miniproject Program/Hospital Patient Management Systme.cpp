#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Patient
{
private:
    int patientId;
    string patientName;
    int age;
    string disease;
    string doctorName;
    float hospitalCharges;

public:

    void addPatient()
    {
        cout << "\nEnter Patient ID: ";
        cin >> patientId;

        cout << "Enter Patient Name: ";
        cin >> patientName;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Disease: ";
        cin >> disease;

        cout << "Enter Doctor Name: ";
        cin >> doctorName;

        cout << "Enter Hospital Charges: ";
        cin >> hospitalCharges;

        ofstream fout("patient.txt", ios::app);

        fout << patientId << " "
             << patientName << " "
             << age << " "
             << disease << " "
             << doctorName << " "
             << hospitalCharges << endl;

        fout.close();

        cout << "\nPatient added successfully.";
    }

    void displayPatient()
    {
        cout << "\nPatient ID       : " << patientId;
        cout << "\nPatient Name     : " << patientName;
        cout << "\nAge              : " << age;
        cout << "\nDisease          : " << disease;
        cout << "\nDoctor Name      : " << doctorName;
        cout << "\nHospital Charges : " << hospitalCharges;
        cout << "\n-----------------------------";
    }

    void displayAll()
    {
        ifstream fin("patient.txt");

        while(fin >> patientId
                  >> patientName
                  >> age
                  >> disease
                  >> doctorName
                  >> hospitalCharges)
        {
            displayPatient();
        }

        fin.close();
    }

    void searchPatient()
    {
        int id;
        bool found = false;

        cout << "\nEnter Patient ID: ";
        cin >> id;

        ifstream fin("patient.txt");

        while(fin >> patientId
                  >> patientName
                  >> age
                  >> disease
                  >> doctorName
                  >> hospitalCharges)
        {
            if(patientId == id)
            {
                cout << "\nPatient Found";
                displayPatient();
                found = true;
                break;
            }
        }

        fin.close();

        if(!found)
            cout << "\nPatient not found.";
    }

    void updatePatient()
    {
        int id;
        bool found = false;

        cout << "\nEnter Patient ID to update: ";
        cin >> id;

        ifstream fin("patient.txt");
        ofstream fout("temp.txt");

        while(fin >> patientId
                  >> patientName
                  >> age
                  >> disease
                  >> doctorName
                  >> hospitalCharges)
        {
            if(patientId == id)
            {
                found = true;

                cout << "\nEnter New Name: ";
                cin >> patientName;

                cout << "Enter New Age: ";
                cin >> age;

                cout << "Enter New Disease: ";
                cin >> disease;

                cout << "Enter New Doctor: ";
                cin >> doctorName;

                cout << "Enter New Charges: ";
                cin >> hospitalCharges;
            }

            fout << patientId << " "
                 << patientName << " "
                 << age << " "
                 << disease << " "
                 << doctorName << " "
                 << hospitalCharges << endl;
        }

        fin.close();
        fout.close();

        remove("patient.txt");
        rename("temp.txt", "patient.txt");

        if(found)
            cout << "\nPatient updated successfully.";
        else
            cout << "\nPatient not found.";
    }

    void deletePatient()
    {
        int id;
        bool found = false;

        cout << "\nEnter Patient ID to delete: ";
        cin >> id;

        ifstream fin("patient.txt");
        ofstream fout("temp.txt");

        while(fin >> patientId
                  >> patientName
                  >> age
                  >> disease
                  >> doctorName
                  >> hospitalCharges)
        {
            if(patientId == id)
            {
                found = true;
                continue;
            }

            fout << patientId << " "
                 << patientName << " "
                 << age << " "
                 << disease << " "
                 << doctorName << " "
                 << hospitalCharges << endl;
        }

        fin.close();
        fout.close();

        remove("patient.txt");
        rename("temp.txt", "patient.txt");

        if(found)
            cout << "\nPatient deleted successfully.";
        else
            cout << "\nPatient not found.";
    }
};

int main()
{
    Patient p;
    int choice;

    do
    {
        cout << "\n\n===== HOSPITAL PATIENT MANAGEMENT =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Display All Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Update Patient";
        cout << "\n5. Delete Patient";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                p.addPatient();
                break;

            case 2:
                p.displayAll();
                break;

            case 3:
                p.searchPatient();
                break;

            case 4:
                p.updatePatient();
                break;

            case 5:
                p.deletePatient();
                break;

            case 6:
                cout << "\nProgram exited.";
                break;

            default:
                cout << "\nInvalid choice.";
        }

    } while(choice != 6);

    return 0;
}
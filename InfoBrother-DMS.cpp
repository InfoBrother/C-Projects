/* Introducing InfoBrother DMS.
   This program can write any data to a file, read data from a file, search data in a file, modify existing records, and delete records from a file.
   By Sardar Omar.
*/

//////////////////////////////////////////////////////////////////////////////
// Header Files

#include <conio.h>    // for getch()
#include <iostream>   // for input and output streams
#include <string.h>   // for some string functions
#include <iomanip>    // for manipulation
#include <fstream>    // for file operations
#include <windows.h>  // for sleep(), clear screen, and adding color
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS EMPLOYEE: This class will store, display, and modify employee data.
// Data will be displayed in the console, not stored in a file.
///////////////////////////////////////////////////////////////////////////////

class Employee
{
private: // Private members of the class
    char name[30];
    char employee_ID[20];
    char joining_DATE[20];
    char position[20];
    char marital_status[10];
    char age[10];
    char salary[20];
    char comment[80];
    
public: // Public members of the class

    ///////////////////////////////////////////////////////////////////////////
    // This function will get data from the user
    
    void getEmp_data()
    {
        cout << "\n\n\n Enter Employee Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << " Enter Employee ID: ";
        cin.getline(employee_ID, 20);
        cout << " Joining Date Of Employee: (DD/MM/YYYY) ";
        cin.getline(joining_DATE, 20);
        cout << " Enter Job Description: ";
        cin.getline(position, 20);
        cout << " Marital Status: ";
        cin.getline(marital_status, 10);
        cout << " Enter Employee Age: ";
        cin.getline(age, 10);
        cout << " Enter Employee Salary: $ ";
        cin.getline(salary, 20);
        cout << " Any Comment Regarding Employee: ";
        cin.getline(comment, 80);
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // This function will display all user data
    
    void showemp_data()
    {
        cout << " Name: " << name << endl;
        cout << " Employee ID: " << employee_ID << endl;
        cout << " Position: " << position << endl;
        cout << " Date of Joining: " << joining_DATE << endl;
        cout << " Age of Employee: " << age << endl;
        cout << " Total Salary in $: " << salary << endl;
        cout << " Marital Status: " << marital_status << endl;
        cout << " Comment: " << comment << endl;
    }
    
    ///////////////////////////////////////////////////////////////////////////
    // This function will help to modify entered data
    
    void modifyEmp_data()
    {
        cout << "\t\n Employee ID: " << employee_ID << endl;
        cout << "\n\n Modify Name Of Employee: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << " Modify Joining Date Of Employee: (DD/MM/YYYY) ";
        cin.getline(joining_DATE, 20);
        cout << " Modify Position Of Employee: ";
        cin.getline(position, 20);
        cout << " Modify Marital Status Of Employee: ";
        cin.getline(marital_status, 10);
        cout << " Modify Age Of Employee: ";
        cin.getline(age, 10);
        cout << " Modify Salary Of Employee: $ ";
        cin.getline(salary, 20);
        cout << " Modify Comment About Employee: ";
        cin.getline(comment, 50);     
    }
    
    ///////////////////////////////////////////////////////////////////////////
    // This function will store the ID number of the employee
    
    char* getEmp_ID()
    {
        return employee_ID; // Return employee ID
    }

    ///////////////////////////////////////////////////////////////////////////
    // This function will display some information about an employee
    
    void empReport()
    {
        cout << "\t" << employee_ID << "\t\t" << name << "\t\t" << salary << endl;
    }
};

///////////////////////////////////////////////////////////////////////////////
// CLASS LIBRARY: This class will be used to write data into a file.
///////////////////////////////////////////////////////////////////////////////

class Library
{
public:
    Employee Emp; // Employee class object
    fstream fp;   // File pointer
    
    ///////////////////////////////////////////////////////////////////////////
    // This function will write employee data into files
    
    void WriteEmployee()
    {
        int more; // For loop
        fp.open("Employee.DAT", ios::out | ios::app);
        if (!fp) // Error checker
        {
            cout << "\n\a Error...!! Employee file could not open";
            getch(); // Get character
            return;
        }	 
        do // Loop to repeat data entry until 2 is pressed
        {
            Emp.getEmp_data(); // Function call
            fp.write((char*)&Emp, sizeof(Emp));
            cout << "\n\n\a Press 1 to Enter More Data: " << endl;
            cout << " Press 2 to Return to Main Menu: " << endl;
            cout << " Option: ";
            cin >> more;
        }
        while (more == 1); // Enter data again while input number is 1
        fp.close();
    } 
    
    ///////////////////////////////////////////////////////////////////////////
    // This function will modify employee data
    
    void W_ModifyEmp()
    {
        int found = 0; // If data is found, return 1, else 0
        char n[20];    // For getting user ID
        
        cout << "\n\n\a Enter User ID" << endl;
        cout << " \nUser ID: ";
        cin >> n;
        
        fp.open("Employee.DAT", ios::in | ios::out);
        if (!fp) // Error checker
        {
            cout << "\n\a Error...!! Employee file could not open";
            getch(); // Get character
            return;
        }
        
        while (fp.read((char*)&Emp, sizeof(Emp)))
        {
            if (strcmpi(Emp.getEmp_ID(), n) == 0) // If entered ID matches any data
            {
                Emp.showemp_data(); // Show the record
                cout << "\n Enter New Data To Modify: " << endl;
                Emp.modifyEmp_data();
                int position = -1 * sizeof(Emp); // Start from current position to backward
                fp.seekp(position, ios::cur); // Set writing pointer to current position
                fp.write((char*)&Emp, sizeof(Emp));
                found = 1; // Data found, set found to 1
            }
        }
        fp.close();
        if (found == 0)
        {
            cout << "\n\n\a Record Not Found: " << endl;
        }
        else
        {
            cout << "\n\t\a Employee Data Modified Successfully:" << endl;
        }
        getch();
    }
    
    ///////////////////////////////////////////////////////////////////////////
    // This function can be used to search any data from all stored data
    
    void W_SearchEmp()
    {
        int found = 0; // If record is found, return 1, else 0
        char n[20];    // To get employee ID from user
        
        cout << "\n\n\a Enter Employee ID: " << endl;
        cout << " Employee ID: ";
        cin >> n;
        
        fp.open("Employee.DAT", ios::in);
        if (!fp) // Error checker
        {
            cout << "\n\a Error...!! Employee file could not open";
            getch();
            return;
        }
     
        while (fp.read((char*)&Emp, sizeof(Emp)))
        {
            if (strcmpi(Emp.getEmp_ID(), n) == 0) // If entered ID matches any data
            {
                Emp.showemp_data(); // Function call
                found = 1; // Data found, set found to 1
            }
        }
        fp.close();
        if (found == 0) // If record is not found, found will be 0
        {
            cout << "\n\n\a Record Not Found: " << endl;
        }
        getch();
    }

    ///////////////////////////////////////////////////////////////////////////
    // This function will be used to delete any record
    
    void deleteEmp()    
    {
        int found = 0; // If data is found, return 1, else 0
        char n[20];    // For getting user ID from user
        
        cout << "\n\n\a Enter User ID: " << endl;
        cout << " User ID: ";
        cin >> n;
        
        fp.open("Employee.DAT", ios::out | ios::in);
        if (!fp) // Error checker
        {
            cout << "\n\a Error...!! Employee file could not open";
            getch();
            return;
        }
        fstream fp2; // Temporary file pointer
        fp2.open("temp.DAT", ios::out);
        if (!fp2) // Error checker
        {
            cout << "\n\a Error...!! Temporary file could not open";
            getch();
            return;
        }
        fp.seekg(0, ios::beg); // Set reading pointer at the beginning
        while (fp.read((char*)&Emp, sizeof(Emp)))
        {
            if (strcmpi(Emp.getEmp_ID(), n) != 0) // If entered ID matches any stored ID, leave it and get all other data
            {
                fp2.write((char*)&Emp, sizeof(Emp)); // Copy all data to temp file except the matched one
            }
            else // Now we have the temp file without the selected record
            {
                found = 1; // Data found, set found to 1
            }
        }
        
        fp.close();
        fp2.close();
        
        remove("Employee.DAT"); // Delete the Employee file
        rename("temp.DAT", "Employee.DAT"); // Rename the temp file to Employee file
        if (found == 0) // If found = 0, then the record was not found
        {
            cout << "\n\n\a Record Not Found: " << endl;
        }
        else
        {
            cout << "\n\t\a Employee Data Deleted Successfully:" << endl;
        }
        getch();
    }

    ///////////////////////////////////////////////////////////////////////////
    // This function is used to display all stored data
    
    void W_displayEmp()
    {
        fp.open("Employee.DAT", ios::in);
        if (!fp) // Error checker
        {
            cout << "\n\a Error...!! Employee file could not open";
            getch();
            return;
        }
     
        cout << " \n\n\t\t EMPLOYEE LIST ";
        cout << "\n\n**********************************************************************" << endl;
        cout << "\t ID Number:" << "\t\t" << "Name " << "\t\t" << "Total Salary: " << endl;
        cout << "**********************************************************************" << endl;
        
        while (fp.read((char*)&Emp, sizeof(Emp)))
        {
            Emp.empReport(); // Function call
        }
        fp.close();
        getch();
    }

    ///////////////////////////////////////////////////////////////////////////
    // This is the front page of the display screen
    
    void intro()
    {
        system("color B3");
        cout << "\n\n\n\n\t\t\t|***********************************|" << endl;
        cout << "\n\t\t\t *INFOBROTHER DATA MANAGEMENT SYSTEM*" << endl;
        cout << "\n\t\t\t|***********************************|" << endl;
        Sleep(600);
        cout << "\n\n\n";
        Sleep(400);
    }

    ///////////////////////////////////////////////////////////////////////////
    // This is the list of employee options
    
    void EmployMenu()
    {
        char ch;
        int option;
        cout << endl;
        cout << "\n\t\t===========================================";
        cout << "\n\n\t\tPress 1 to CREATE NEW EMPLOYEE RECORD: ";
        cout << "\n\n\t\tPress 2 to DISPLAY ALL EMPLOYEE RECORD: ";
        cout << "\n\n\t\tPress 3 to MODIFY EMPLOYEE RECORD: ";
        cout << "\n\n\t\tPress 4 to DELETE EMPLOYEE RECORD: ";
        cout << "\n\n\t\tPress 5 to SEARCH EMPLOYEE RECORD: ";
        cout << "\n\n\t\tPress 6 to BACK TO MAIN MENU: " << endl;
        cout << "\t\t===========================================" << endl;
        
        cout << "\n\t\t Option: ";
        cin >> option;
        
        switch (option)
        {
            case 1:
                system("cls");
                system("color 2A");
                cout << "\n\n\n\t\t\t\a |==========================|" << endl;
                cout << "\t\t\t\t\aWRITE EMPLOYEE DATA " << endl;
                cout << "\t\t\t |==========================|" << endl;
                WriteEmployee();
                break;
                
            case 2:
                system("cls");
                system("color 0D");
                cout << "\n\n\n\t\t\t\a |============================|" << endl;
                cout << "\t\t\t\t\aDISPLAY EMPLOYEE DATA " << endl;
                cout << "\t\t\t |============================|" << endl;
                W_displayEmp();
                break;
            case 3:
                system("cls");
                system("color 30");
                cout << "\n\n\n\t\t\t\a |============================|" << endl;
                cout << "\t\t\t\t\aMODIFY EMPLOYEE DATA " << endl;
                cout << "\t\t\t |============================|" << endl;
                W_ModifyEmp();
                break;
            case 4:
                system("cls");
                system("color 80");
                cout << "\n\n\n\t\t\t\a |============================|" << endl;
                cout << "\t\t\t\t\aDELETE EMPLOYEE DATA " << endl;
                cout << "\t\t\t |============================|" << endl;
                deleteEmp();
                break;
            case 5:
                system("cls");
                system("color 50");
                cout << "\n\n\n\t\t\t\a |============================|" << endl;
                cout << "\t\t\t\t\aSEARCH EMPLOYEE DATA " << endl;
                cout << "\t\t\t |============================|" << endl;
                W_SearchEmp();
                break;
            case 6:
                system("cls");
            default:
                cout << "\a";
        }
    }
};

///////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTION
/////////////////////////////////////////////////////////////////////////////

int main()
{
    Library obj;
    int option = 0;
    obj.intro();
    cout << endl << endl;
    for (;;)
    {
        cout << "\n\n\t\t==================================================" << endl;
        cout << "\n\t\t\t Press 1 to Enter \"EMPLOYEE\" Menu" << endl;
        cout << "\n\t\t==================================================" << endl;
        cout << "\t\t Option: ";
        cin >> option;
        
        switch (option)
        {
            case 1:
                system("cls");
                system("color 72");
                cout << "\n\n\n\t\t\t\a|=============================|" << endl;
                cout << "\t\t\t\a E M P L O Y E E D A T A " << endl;
                cout << "\t\t\t|=============================|" << endl;
                obj.EmployMenu();
                break;
            default:
                cout << "\a NO Option Selected: ";
                exit(0);
        }
    }
    return 0;
}

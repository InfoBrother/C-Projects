/*Introducing InfoBrother DMS. this program can write any data to file, read data from
file, search data from file, Modify existing record and delete any record from file:
By Sardar Omar.*/

//////////////////////////////////////////////////////////////////////////////
// Header Files. 

#include<conio.h> //for getch(),
#include<iostream> //for input and output streams.
#include<string.h> //for some string function
#include<iomanip> //for Manupulation
#include<fstream> //for file 
#include<windows.h> //for sleep(). and clear screen and adding color.
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS EMPLOYEE, this class will store, Display and Modify Employee data //
// Not in file , just in console. //
//////////////////////////////////////////////////////////////////////////////

class Employee
{
     private: //private Members of class
        char name[30];
        char employe_ID[20];
        char joining_DATE[20];
        char position[20];
        char marital_status[10];
        char age[10];
        char salary[20];
        char comment[80];
        
    public: //Public Members of class
    
///////////////////////////////////////////////////////////////////////////////
//This function will get data from user
         
    void getEmp_data()
    {
         cout<<"\n\n\n Enter Employee Name: ";
         cin.ignore();
            cin.getline(name,30);
            cout<<" Enter Employee ID: ";
     		cin.getline(employe_ID,20);
     		cout<<" Joining Date Of Employee: (DD/MM/YYYY) ";
         	cin.getline(joining_DATE,20);
            cout<<" Enter Job Description: ";
         	cin.getline(position,20);
         	cout<<" Maritial Status: ";
         	cin.getline(marital_status,10);
            cout<<" Enter Employee Age: ";
         	cin.getline(age,10);
         	cout<<" Enter Employee Salary: $ ";
         	cin.getline(salary,20);
         	cout<<" Any Comment Regarding Employee: ";
         	cin.getline(comment,80);
    }
    
////////////////////////////////////////////////////////////////////////////////
// This Fuction will display ALL user data.

void showemp_data()
{
     cout<<" Name: "<< name<<endl;
     cout<<" Employee ID: "<< employe_ID<<endl;
     cout<<" Position: "<< position<<endl;
     cout<<" Date of joining: "<< joining_DATE<<endl;
     cout<<" Age of Employee: "<< age<<endl;
     cout<<" Total Salary in $: "<< salary<<endl;
     cout<<" Maritial Status: "<< marital_status<<endl;
     cout<<" Comment: "<< comment<<endl;
}
    
///////////////////////////////////////////////////////////////////////////////
//This Function will help to Modify Entered data.

    void modifyEmp_data()
    {
        cout<<"\t\n Employee ID: "<<employe_ID<<endl;
        cout<<"\n\n Modify Name Of Employee: ";
        cin.ignore();
        cin.getline(name,30);
        cout<<" Modify Joining Date Of Employee: (DD/MM/YYYY) ";
        cin.getline(joining_DATE,20);
        cout<<" Modify Position Of Employee: ";
        cin.getline(position,20);
        cout<<" Modify Maritial Status Of Employee: ";
        cin.getline(marital_status,10);
        cout<<" Modify Age Of Employee: ";
        cin.getline(age,10);
        cout<<" Modify Salary Of Employee: $ ";
        cin.getline(salary,20);
        cout<<" Modify Comment About Employee: ";
        cin.getline(comment,50);     
    }
    
    
///////////////////////////////////////////////////////////////////////////////
//This Pointer Fuction will store ID No of Employee
	char *getEmp_ID()
	{
    	return employe_ID; //return employee id
	}

//////////////////////////////////////////////////////////////////////////////
//This Fuction will used to display some information about employee whose exist.

	void empReport()
	{
    
    	cout<<"\t"<<employe_ID<<"\t\t"<<name<<"\t\t"<<salary<<endl;
	}
};



///////////////////////////////////////////////////////////////////////////////
// CLASS LIBRARY: this class will used to write data into file: //
//////////////////////////////////////////////////////////////////////////////

class Library
{
    public:
     Employee Emp; //Employee class object. 
     fstream fp; //file pointers.
     
     
//////////////////////////////////////////////////////////////////////////////
//This class will write Employee data into the files.
	void WriteEmployee()
    {
        int more; //for loop.
        fp.open("Employe.DAT",ios::out | ios::app); 
    	 if(!fp) // error checker
     	{
         	cout<<"\n\a Error...!! Employee file could not open";
    		getch(); //get character:
         	return;
     	}	 
        do //loop: to repeat data until you press 2:
        {
            Emp.getEmp_data(); //funtion calling.
            fp.write((char*)&Emp,sizeof(Emp));
            cout<<"\n\n\a Press 1 to Enter More Data: "<<endl;
            cout<<" Press 2 to Return Main menu: "<<endl;
            cout<<" Option: ";
            cin>>more;
        }
        while(more==1); //Enter data again while enter no is 1;
        fp.close();
        
    } 
    
////////////////////////////////////////////////////////////////////////////
// This Fuction will used to Modify Employee Data:
    void W_ModifyEmp()
    {
        int found=0; //if we found data then return 1, else 0;
        char n[20]; //for getting user id.
        
        cout<<"\n\n\a Enter User ID"<<endl;
        cout<<" \nUser ID: ";
        cin>>n;
        
        fp.open("Employe.DAT",ios::in | ios::out);
        if(!fp) //error checker:
    {
         cout<<"\n\a Error...!! Employee file could not open";
         getch(); //get character:
         return;
     }
        
        while(fp.read((char*)&Emp, sizeof(Emp)))
        {
            if(strcmpi(Emp.getEmp_ID(),n)==0) //if enter id matched with any data
            {
                Emp.showemp_data(); //show the record:
                cout<<"\n Enter New Data To Modify: "<<endl;
                Emp.modifyEmp_data();
                int position=-1*sizeof(Emp); //start from current postion to backward.
                fp.seekp(position,ios::cur); //set writing pointer to curr position.
                fp.write((char*)&Emp,sizeof(Emp));
     			found=1; //we found data, so found is set to 1,
            }
        }
        fp.close();
        if(found==0)
        {
            cout<<"\n\n\a Record Not found: "<<endl;
        }
        else
        cout<<"\n\t\a Employee Data Modify Successfully:"<<endl;
        getch();
    }
    

/////////////////////////////////////////////////////////////////////////////
//By this function we can find any data from all stored data:
    void W_SearchEmp()
    {
        int found=0; //if we found record then return 1. else 0;
        char n[20]; //to get employee id from user
        
        cout<<"\n\n\a Enter Employee ID: "<<endl;
        cout<<" Employee ID: ";
        cin>>n;
        
     	fp.open("Employe.DAT",ios::in);
         if(!fp) //error chacker
     	{
         	cout<<"\n\a Error...!! Employee file could not open";
         	getch();
         	return;
     	}
     
     while(fp.read((char*)&Emp,sizeof(Emp)))
     {
         if(strcmpi(Emp.getEmp_ID(),n)==0) //if entered id will match with any data.
         {
             Emp.showemp_data(); //calling function
             found=1; //we found data so found is set to 1.
         }
     }
     fp.close();
     if(found==0) //uf we didnt found record then found will be 0;
     {
         cout<<"\n\n\a Record Not found: "<<endl;
     }
         getch();
    }

    
//////////////////////////////////////////////////////////////////////////////
// This function will be used to delete any record
void deleteEmp()    
{
     int found=0; //if we found data the return 1. else 0;
     char n[20]; //for getting user id from user.
     
     cout<<"\n\n\a Enter User ID: "<<endl;
     cout<<" User ID: ";
     cin>>n;
     
     fp.open("Employe.DAT",ios::out | ios::in);
     if(!fp) //error chacker
     {
         cout<<"\n\a Error...!! Employee file could not open";
         getch();
         return;
     }
    fstream fp2; //temperory file pointer
    fp2.open("temp.DAT", ios::out);
     if(!fp2) //error chacker
     {
         cout<<"\n\a Error...!! Temperary file could not open";
         getch();
         return;
     }
    fp.seekg(0,ios::beg); //set reading pointer at the beganing
    while(fp.read((char*)&Emp,sizeof(Emp)))
    {
        if(strcmpi(Emp.getEmp_ID(),n)!=0) //read all data and if entered id will match the any stored id then lev this and get all other data.
        {
            fp2.write((char*)&Emp,sizeof(Emp)); //and copy all data to temp file except the matched one.
        }
        
        else //now we have got the temp file without the selected one record.
        found=1; //as we found the record so found is set to 1;
    }
    
    fp.close();
    fp2.close();
    
    remove("Employe.DAT"); //delete the Employee file
    rename("temp.DAT","Employe.DAT"); //rename the temp file with employee file.
    if(found==0) //if found = 0; then its mean we didnt found the record.
    {
        cout<<"\n\n\a Record Not Found: "<<endl;
    }
    else
    cout<<"\n\t\a Employee Data Delete Successfully:"<<endl;
    getch();
    
}

////////////////////////////////////////////////////////////////////////////////
//This function is used to display all stored data.
void W_displayEmp()
{
    fp.open("Employe.DAT",ios::in);
    if(!fp) //error chacker
     {
         cout<<"\n\a Error...!! Employee file could not open";
         getch();
         return;
     }
     
     cout<<" \n\n\t\t EMPLOYE LIST ";
    cout<<"\n\n**********************************************************************"<<endl;
    cout<<"\t ID Number:" <<"\t\t"<<"Name "<<"\t\t"<<"Total Salary: "<<endl;
    cout<<"**********************************************************************"<<endl;
    
    while(fp.read((char*)&Emp,sizeof(Emp)))
    {
        Emp.empReport(); //function calling
    }
    fp.close();
    getch();
}


///////////////////////////////////////////////////////////////////////////////
//This is the front page of display screen:
    void intro()
{
system("color B3");
cout<<"\n\n\n\n\t\t\t|***********************************|"<<endl;
    cout<<"\n\t\t\t *INFOBROTHER DATA MANAGEMEMT SYSTEM*"<<endl;
    cout<<"\n\t\t\t|***********************************|"<<endl;
    Sleep(600);
    cout<<"\n\n\n";
    Sleep(400);
}

///////////////////////////////////////////////////////////////////////////////
//this is the list of Employee:
    void EmployManu()
{
    
char ch;
    int option;
    cout<<endl;
cout<<"\n\t\t===========================================";
    cout<<"\n\n\t\tPress 1 to CREATE NEW EMPLOYEE RECORD: ";
    cout<<"\n\n\t\tPress 2 to DISPLAY ALL EMPLOYEE RECORD: ";
    cout<<"\n\n\t\tPress 3 to MODIFY EMPLOYEE RECORD: ";
    cout<<"\n\n\t\tPress 4 to DELETE EMPLOYEE RECORD: ";
    cout<<"\n\n\t\tPress 5 to SEARCH EMPLOYEE RECORD: ";
    cout<<"\n\n\t\tPress 6 to BACK TO MAIN MENU: "<<endl;
    cout<<"\t\t==========================================="<<endl;
    
    cout<<"\n\t\t Option: ";
    cin>>option;
    
    switch(option)
    {
        case 1:
            system("cls");
            system("color 2A");
            cout<<"\n\n\n\t\t\t\a |==========================|"<<endl;
     cout<<"\t\t\t\t\aWRITE EMPLOYEE DATA "<<endl;
     cout<<"\t\t\t |==========================|"<<endl;
            WriteEmployee();
            break;
            
        case 2:
            system("cls");
            system("color 0D");
            cout<<"\n\n\n\t\t\t\a |============================|"<<endl;
     cout<<"\t\t\t\t\aDISPLAY EMPLOYEE DATA "<<endl;
     cout<<"\t\t\t |============================|"<<endl;
            W_displayEmp();
            break;
        case 3:
            system("cls");
            system("color 30");
            cout<<"\n\n\n\t\t\t\a |============================|"<<endl;
     cout<<"\t\t\t\t\aMODIFY EMPLOYEE DATA "<<endl;
     cout<<"\t\t\t |============================|"<<endl;
            W_ModifyEmp();
         break;
        case 4:
            system("cls");
            system("color 80");
            cout<<"\n\n\n\t\t\t\a |============================|"<<endl;
     cout<<"\t\t\t\t\aDELETE EMPLOYEE DATA "<<endl;
     cout<<"\t\t\t |============================|"<<endl;
            deleteEmp();
            break;
        case 5:
            system("cls");
            system("color 50");
            cout<<"\n\n\n\t\t\t\a |============================|"<<endl;
     cout<<"\t\t\t\t\aSEARCH EMPLOYEE DATA "<<endl;
     cout<<"\t\t\t |============================|"<<endl;
            W_SearchEmp();
            break;
        case 6:
            system("cls");
            default: cout<<"\a";
            
    }
}

};

///////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTION //
/////////////////////////////////////////////////////////////////////////////

main()
{

    Library obj;
    int option=0;
    obj.intro();
    cout<<endl<<endl;
    for(;;)
    {
    cout<<"\n\n\t\t=================================================="<<endl;
        cout<<"\n\t\t\t Press 1 to Enter \"EMPLOYEE\" menu"<<endl;
        cout<<"\n\t\t=================================================="<<endl;
        cout<<"\t\t Option: ";
        cin>>option;
        
        switch(option)
        {
            case 1:
                system("cls");
                system("color 72");
                cout<<"\n\n\n\t\t\t\a|=============================|"<<endl;
     cout<<"\t\t\t\a E M P L O Y E E D A T A "<<endl;
     cout<<"\t\t\t|=============================|"<<endl;
                obj.EmployManu();
                break;
            default:
                cout<<"\a NO Option Selected: ";
                exit(0);
        }

    }
    return 0;
}

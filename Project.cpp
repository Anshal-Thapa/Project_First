#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include<fstream>

using namespace std;

string filename = "";

int project();
void createFile();
void inputData();
void displayData();
// void deleteData();
// void updateData();
// void searchData();
void initChoice();
void pressToContinue();
int checkFile();
void checkDat();
void header();

class Student
{
    private:
        int RegNo;
        char name[30];
        char DOB[12];
        char gender[10];
        char email[50];
        int marks;

    public:
        void addData();
        void showData();
        void deleteData();
        int Regno()
        {
            return RegNo;
        }
}s;

void Student::addData()
{
    cout<<"\n\nEnter Student Details......\n";
    cout<<"Enter Registration No.  : "; cin>>RegNo;
    cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
    cout<<"Enter Gender (M/F)      : "; cin>>gender;
    cout<<"Enter DOB               : "; cin>>DOB;
    cout<<"Enter Email             : "; cin>>email;
    cout<<"Enter Marks (out of 500): "; cin>>marks;
    cout<<endl;
}

void Student::showData()
{
 cout<<"\n\n.......Student Details......\n";
 cout<<"Registration No.  : "<<RegNo<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"DOB               : "<<DOB<<endl;
 cout<<"Email             : "<<email<<endl;
 cout<<"Marks (out of 500): "<<marks<<endl;
 cout<<endl;
}


int main()
{
    initChoice();
    return 0;
}

int project()
{
    system("cls");
    int choice;
    while (true) {
        header();
        cout << "1. Add Data." << endl;
        cout << "2. Display Data." << endl;
        cout << "3. Search Data." << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Delete Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
         switch (choice) {
            case 1:
                inputData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                //searchData();
                break;
            case 4:
                //updateData();
                break;
            case 5:
                //deleteData();
                break;
            case 6:
                cout << "Thank you for using the Student Management System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        pressToContinue();
    }
    return 0;
}

void initChoice()
{
    char choice;
    system("cls");
    header();
    cout << "Does your file exist or not?\n";
    cin >> choice;
    if(toupper(choice)== 'Y')
    {
        if(checkFile()==0)
        {
            project();
        }
        
    }
    else if (toupper(choice)== 'N')
    {
        header();
        //pressToContinue();
        createFile();
    }
    
}
void pressToContinue(){
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void createFile()
{
    cout << "Creating a file:\n";
    cout << "Enter the filename: ";
    cin>>filename;
    checkDat();
    ofstream file;
    file.open(filename, ios::out | ios::binary);
    if (!file) {
        cerr << "The file could not be opened." << endl;
        exit(1);
    }
}

int checkFile()
{
    header();
    cout << "Enter your the filename: ";
    cin>>filename;
    checkDat();
    ifstream file;
    file.open(filename);
    if(file)
    {
        cout << "File exists.\n" << endl;
    }
    else
    {
        cout << "File does not exists.\nTry again.\n" << endl;
        return 1;
    }
    pressToContinue();
    return 0;
}

void checkDat()
{
    if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".dat") 
    {
        filename += ".dat";
    }
}

void header()
{
    system("cls");
        cout << "=======================================" << endl;
        cout << "       STUDENT MANAGEMENT SYSTEM" << endl;
        cout << "=======================================" << endl;
}

void displayData()
{
    ifstream fin;
    fin.open(filename,ios::in | ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.showData();
    }
    fin.close();
}

void inputData()
{
    ofstream fout;
    fout.open(filename, ios::out | ios::binary | ios::app);
    s.addData();
    fout.write((char*)&s,sizeof(s));
    fout.close();
}
// Develop a program in C++ to create a database of student’s information system containing the 
// following information: Name, Roll number, Class, Division, Date of Birth, Blood group, 
// Contact address, Telephone number, Driving license no. and other. Construct the database with 
// suitable member functions. Make use of constructor, default constructor, copy constructor, 
// destructor, static member functions, friend class, this pointer, inline code and dynamic memory 
// allocation operators-new and delete as well as exception handling

#include <iostream>
#include <string.h>
using namespace std;

class Studdata {
     // basic details of student in private field
    string Name, DOB, Address, Class, Bldgrp;
    char Div;
    int RollNo;
    long long TeleNo, LicNo;

     // intialising static variable called count for incrementing count of students. This is also used for assigning roll no of students as the obj(of class student) is created.
    static int count;

    friend class Showdata; // Now the class Showdata can access all the private data members of this class (Studdata)

    public:
        //default constructor used for incrementing count variable as the object created.
        Studdata() {
            count++;
            RollNo = count;
        }
        
        //copy constructor used for copying contents of the object which being pass in this constructor to the object which is being created by using this constructor
        Studdata(Studdata &stud) {
            cout<<"\nCopying the this data to other student data\n\n";
            Name = stud.Name;
            RollNo = stud.RollNo;
            Class=stud.Class; 
            Div = stud.Div;
            DOB = stud.DOB;
            Bldgrp = stud.Bldgrp;
            Address = stud.Address;
            TeleNo = stud.TeleNo;
            LicNo = stud.LicNo;
        }
        
        static void getcount() { //static function can only access static variable
            cout<<"\nTotal number of students: "<<count;
        }

        inline void Getdata() {
            cout<<"\n\nEnter the information for the "<<count;
            if (count==1) cout<<"st";
            else if (count==2) cout<<"nd";
            else if (count==3) cout<<"rd";
            else cout<<"th";
            cout<<" student:\n\n";
            // just formatting 

            cout<<"Enter the name of the student: ";
            cin.ignore();
            getline(cin, Name);
            point1:
            cout<<"\nEnter the Class of the student: ";
            try {
                cin>>Class;
                if (Class!= "FE"  && Class!= "SE" && Class!="TE" && Class!="BE") { 
                    throw "Invalid input, please try again\n";
                }
                
            } catch (const char* e) {
                cerr << e <<endl;
                goto point1;
            }
            point2:
            cout<<"\nEnter the Division of the student: ";
            try {
                cin>>Div;
                if (Div!= 'A' && 'B') {
                    throw "Invalid input, please try again\n";
                }
                
            } catch (const char* e) {
                cerr << e <<endl;
                goto point2;
            }
            cout<<"\nEnter the Date of Birth of the student as string: ";
            cin.ignore();
            getline(cin, DOB);
            cout<<"\nEnter the Blood group of the student: ";
            point3:
            try {
                cin>>Bldgrp;
                if (Bldgrp!="A" && Bldgrp!="B" && Bldgrp!="AB" && Bldgrp!="O"){
                    throw "Invalid input, please try again\n";
                }
                
            } catch (const char* e) {
                cerr << e <<endl;
                goto point3;
            }
            cout<<"\nEnter the contact address of the student: ";
            cin.ignore();
            getline(cin, Address);
            cout<<"\nEnter the Telephone number of the student: ";
            cin>>TeleNo;
            cout<<"\nEnter the Driving license number of the student: ";
            cin>>LicNo;
        }

        ~Studdata() {
            cout<<"\nDeleting object\n";
            count--;
            cout<<"Number of students: "<<count;
        }
};

//class showdata is used here to display all the information of student when pass through its constructor
class Showdata {
    public:
    Showdata(Studdata &stud) {
        cout<<"\n\nInformation of student "<<stud.RollNo<<": "<<endl<<endl;

        for(int i=0;i<25;i++) cout<<"-";
        cout<<"\n\n";
        cout<< "Name: " << stud.Name<<endl;
        cout<< "Roll number: " << stud.RollNo<<endl;
        cout<< "Class: " << stud.Class<<endl; 
        cout<< "Division: " << stud.Div<<endl;
        cout<< "Date of Birth: " << stud.DOB<<endl;
        cout<< "Blood group: " << stud.Bldgrp<<endl;
        cout<< "Contact address: " << stud.Address<<endl;
        cout<< "Telephone number: " << stud.TeleNo<<endl;
        cout<< "Driving license no.: " << stud.LicNo<<endl;
        cout<<"\n\n";
        for(int i=0;i<25;i++) cout<<"-";
    }
};

int Studdata :: count = 0; //static variable initialization 


int main() {
    int n;
    cout<<"How many students do you want to add?\n: ";
    cin>>n;
    Studdata *s[n];

    for(int i=0; i<n; i++) {
        s[i] = new Studdata;
        s[i]->Getdata();
    }

    for(int i=0; i<n; i++) {
        Showdata info(*s[i]);
    }
    Studdata :: getcount();
    
}
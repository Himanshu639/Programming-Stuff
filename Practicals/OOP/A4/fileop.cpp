// Write a C++ program that creates an output file, writes information to it, closes the file, open it 
// again as an input file and read the information from the file.

#include <iostream>
#include <fstream> // included this because to perform operations on file
using namespace std;


class FileOperation {
    private:
    string path; // To store file location

    string Name = "";
    string Class = "";
    char Div = '\0';
    int RollNo = 0;
    public:
    FileOperation(string path) {
        this->path=path;    // used "this" pointer because to avoid ambiguity between class FileOperation's path and passed parameter path
    }
    void insert();
    void display();
};

void FileOperation::insert() {

    cout<<"Enter the Name: ";
    cin.ignore();
    getline(cin, Name);
    cout<<"Enter the Roll no.: ";
    cin>>RollNo;
    cout<<"Enter the Class: ";
    cin>>Class;
    cout<<"Enter the Division: ";
    cin>>Div;

    ofstream data(path);
    data<< Name<<endl;
    data<< RollNo<<endl;
    data<< Class<<endl; 
    data<< Div<<endl;
    data.close();
    cout<<"\n\nEntered data successfully\n\n";
}

void FileOperation::display() {
    ifstream data(path);

    getline(data, Name);
    data >> RollNo;
    data >> Class;
    data >> Div;
    data.close();
    cout<<"\n\nData Retrived Successfully\n\n";

    cout<< "Name: " << Name<<endl;
    cout<< "Roll number: " << RollNo<<endl;
    cout<< "Class: " << Class<<endl; 
    cout<< "Division: " << Div<<endl;
}

int main() {
    string cd = "D://Programming Stuff//Practicals//OOP//A4//";
    string file_name;
    int ch;
    while(1) {
        
        file_name+=cd;
        cout<<"* * * Menu * * *\n\n1. insert data\n2. retrive data\n3. exit\n\nEnter your choice: ";
        cin>>ch;

        if(ch==1) {
            cout<<"Enter file name: ";
            cin>>file_name;
            FileOperation f1(cd+file_name); // created object f1 for FileOperation; there is cd+file_name because to tell the current directory 'cd' and file name
            f1.insert();
        }            
        else if(ch==2) {
            cout<<"Enter file name: ";
            cin>>file_name;
            FileOperation f1(cd+file_name);
            f1.display();
        } else if (ch==3) {
            return 0;
        } else {
            cout<<"\n\nInvalid choice\n\n";
        }
        
    }
}
//  Write C++ program using STL for sorting and searching user defined records such as personal
// records (Name, DOB, Telephone number etc) using vector container.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <vector>
using namespace std;

class Info
{
    string Name, DOB;
    long long TeleNo;
    int RollNo;

protected:
public:
    static int count;
    friend istream &operator>>(istream &in, Info &obj)
    {

        cout << "\n\nEnter Information about student " << count + 1 << " :\n\n";
        cout << "Enter the Roll No.: ";
        cin >> obj.RollNo;
        cout << "Enter the Name: ";
        cin.ignore();
        getline(cin, obj.Name);
        cout << "Enter the DOB: ";
        getline(cin, obj.DOB);
        cout << "Enter the Telephone number: ";
        cin >> obj.TeleNo;

        count++;
        return in;
    }

    friend ostream &operator<<(ostream &out, Info obj)
    {

        cout << "  " << left << setw(20) << obj.RollNo << left << setw(20) << obj.Name << left << setw(20) << obj.DOB << left << setw(20) << obj.TeleNo << "\n";

        return out;
    }

    bool operator==(Info obj)
    {
        return (RollNo == obj.RollNo);
    }

    bool operator<(Info obj)
    {
        return (RollNo < obj.RollNo);
    }

    friend void search(vector<Info> v);
};

void print(Info obj)
{
    cout << obj;
}

void display(vector<Info> v)
{
    cout << "* * * * * * * * * * * * Information of Students * * * * * * * * * * * *\n\n\n";
    cout << "\n\n"
         << left << setw(20) << "Roll No." << left << setw(20) << "Name" << left << setw(20) << "Date of Birth" << left << setw(20) << "Telephone number\n\n";
    for_each(v.begin(), v.end(), print);
    cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
    cout << "\tTotal number of students: " << Info::count << "\n\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
}

void insert(vector<Info> &v)
{

    int n;
    cout << "How many Students?\n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Info obj;
        cin >> obj;
        v.push_back(obj);
    }
}

void search(vector<Info> v)
{
    vector<Info>::iterator it;
    Info obj;
    cout << "\n\nEnter the Roll no you want to search: ";
    cin >> obj.RollNo;
    it = find(v.begin(), v.end(), obj);
    if (Info::count>0) {
    if (it != v.end())
    {
        cout << "\n\n"
         << left << setw(20) << "Roll No." << left << setw(20) << "Name" << left << setw(20) << "Date of Birth" << left << setw(20) << "Telephone number\n\n";
        cout<<*it<<"\n\n";
    }
    else
        cout << "Element not found.\n\n";
    } else {
        cout<<"\n\nNo data available for searching\n\n";
    }
}

void vecsort(vector<Info> &v)
{
    sort(v.begin(), v.end());
    display(v);
}

int Info::count;

int main()
{
    vector<Info> v;
    int ch;
    while (1)
    {
        cout << "* * * Menu * * *\n\n1. Insert the data\n2. Sort the vector\n3. Search from vector\n4. Display data\n5. exit\n\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            insert(v);
            break;
        case 2:
            vecsort(v);
            break;
        case 3:
            search(v);
            break;
        case 4:
            display(v);
            break;
        default:
            return 0;
        }
    }
}
// Imagine a publishing company which does marketing for book and audio cassette versions. 
// Create a class publication that stores the title (a string) and price (type float) of publications. 
// From this class derive two classes: book which adds a page count (type int) and tape which adds 
// a playing time in minutes (type float).
// Write a program that instantiates the book and tape class, allows user to enter data and displays 
// the data members. If an exception is caught, replace all the data member values with zero 
// values.


#include <iostream>
using namespace std;

class publication  // created parent class called publication
{
  protected:
    string title;
    float price;

  //public:
//    virtual void display() = 0;
//    virtual void getdata() = 0;
};

//Inherited class book from publication with public inheritance mode
class book : public publication
{
    int page_count = 0;

  public:
    void getdata()
    {
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, title);
        try         //exception handling
        {
            cout << "Enter the price of the book: ";
            cin >> price;
            if (price <= 0)
            {
                throw price;
            }
            cout << "Enter the total no. of pages: ";
            cin >> page_count;
            if (page_count <= 0)
            {
                throw page_count;
            }
            
        }
        catch (...)
        {
            cout << "\n* exception caught *\ninvalid value entered\n\n";
            title = "";
            price = 0;
            page_count = 0;
        }
    }
    void display()
    {
        cout << "Title: " << title<<endl;
        cout << "page count: " << page_count<<endl;
        cout << "price: " << price<<endl;
        
        cout<<"\n\n";
    }
};

//Inherited class tape from publication with public inheritance mode
class tape : public publication
{
    float min = 0;

  public:
    void getdata()
    {
        cout << "Enter the title of the tape: ";
        cin.ignore();
        getline(cin, title);

        try             //exception handling
        {
            cout << "Enter the price of the tape: ";
            cin >> price;
            if (price <= 0)
            {
                throw price;
            }
            cout << "Enter the total no. of minutes: ";
            cin >> min;
            if (min <= 0)
            {
                throw min;
            }
        }   
        catch (float)
        {
            cout << "\n* exception caught *\ninvalid value entered\n\n";
            title = "";
            price = 0;
            min = 0;
        }
    }
    void display()
    {
        cout << "Title: " << title<<endl;
        cout << "duration of tape: " << min << " minutes"<<endl;
        cout << "price: " << price<<endl;
        
        cout<<"\n\n";
    }
};

int main()
{
    int ch, nb = 0, nt = 0;
    book b[20]; // created object array of class book
    tape t[20]; // created object array of class tape
    while (1)
    {
        cout << "\n* * * Menu * * *\n\n1. Enter Book Info\n2. Enter Tape Info\n3. Display Book Info\n4. Display Tape Info\n5. exit\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b[nb].getdata(); // accesing method getdata of class book
            nb++;
            break;
        case 2:
            t[nt].getdata(); // accesing method getdata of class tape
            nt++;
            break;
        case 3:
            cout << "\n\n* * * Information of Books * * *\n\nThere are total " << nb << " book/s\n\n";
            for (int i = 0; i < 25; i++)
                cout << "-";
            cout << "\n\n";

            for (int i = 0; i < nb; i++)
            {
                cout<<"\n\nInfo of Book "<<i<<endl<<endl;
                b[i].display();     // accesing method display of class book
            }

            cout << "\n\n";
            for (int i = 0; i < 25; i++)
                cout << "-";
            cout << "\n\n";
            break;
        case 4:
            cout << "* * * Information of Tapes * * *\n\nThere are total " << nt << " tape/s\n\n";
            for (int i = 0; i < 25; i++)
                cout << "-";
            cout << "\n\n";
            for (int i = 0; i < nt; i++)
            {
                cout<<"\n\nInfo of Tape "<<i<<endl<<endl;
                t[i].display();     // accesing method display of class tape
            }
            cout << "\n\n";
            for (int i = 0; i < 25; i++)
                cout << "-";
            cout << "\n\n";
            break;
        case 5:
            return 0;
        default:
            cout << "\n\ninvalid choice\n";
        }
    }
}
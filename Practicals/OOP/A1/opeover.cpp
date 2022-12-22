// Problem Statement :- Implement a class Complex which represents the Complex Number data type. Implement the 
// following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.



#include <iostream>
using namespace std;

class Complex {
    int img, real;
    public:
        Complex() {
            img = real = 0;
        }
        Complex operator+ (Complex temp) {
            Complex res;
            res.real = real + temp.real;
            res.img = img + temp.img;
            return res;
        }
        Complex operator* (Complex temp) {
            Complex res;
            res.real = real * temp.real - img * temp.img;
            res.img = real * temp.img + img * temp.real;
            return res;
        }
        friend ostream &operator<<(ostream &out, Complex temp) {
            out<<temp.real<<" + "<<temp.img<<"i";
            return out;
        }
        friend istream &operator>>(istream &in, Complex &temp) {
            cout<<"Real part of the complex no: ";
            in>>temp.real;
            cout<<"Imaginary part of the complex no: ";
            in>>temp.img;
            cout<<"\n\n";
            return in;
        }
};

int main() {
    int ch;
    Complex c1,c2,c3;
    cout<<"Enter the complex numbers\n\n";
    cout<<"For 1st complex number\n";
    cin>>c1;
    cout<<"For 2nd complex number\n";
    cin>>c2;

    while(1) {
        cout<<"\n\n* Operations\n1. Addition of complex number\n2. Multiplication of complex number\n3. Change the numbers\nEnter your choice: ";
        cin>>ch;

        if (ch==1) {
            c3 = c1 + c2;
            cout<<"\n\nThe addition of two complex number which are\n"<<c1<<" and "<<c2<<endl<<"is "<<c3<<endl;
        } else if (ch==2) {
            c3 = c1 * c2;
            cout<<"\n\nThe multiplication of two complex number which are\n"<<c1<<" and "<<c2<<endl<<"is "<<c3<<endl;
        } else if(ch==3) {
            cout<<"For 1st complex number\n";
            cin>>c1;
            cout<<"For 2nd complex number\n";
            cin>>c2;
        } else {
            cout<<"Invalid choice\n";
        }
    }
}
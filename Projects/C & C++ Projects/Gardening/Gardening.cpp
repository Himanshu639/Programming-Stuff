#include <iostream>
using namespace std;
class garden {
    public:
    string flower[5];
    int m,n;
    string arr[5][12];
    void visit();
    void bloom();
};

void garden::visit() {
    int month;
    
    cout<<"Enter the month\n";
    cin>>month;
    for(int i=0;i<5;i++) {
        cout<<arr[i][month-1]<<" ";
    }
    

}

void garden::bloom() {
    int k=0;

    
    while(k<5) {
        cout<<"Enter which flower:- ";
        cin>>flower[k];
        cout<<"\nEnter the range for the blomming of the flower:- ";
        cin>>m>>n;
    for (int i=m-1;i!=n-1;i++) {
        if (i==12) {
            i=0;
        }
        arr[k][i]=flower[k];
        
    }
    k++;
}
}



int main() {int num;
    garden a;
    a.bloom();
    cout<<"how many?";
    cin>>num;
    
    for (int i=0;i<num;i++)
        a.visit();
}
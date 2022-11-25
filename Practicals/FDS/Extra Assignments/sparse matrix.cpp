#include <iostream>
using namespace std;

int main() {
    int r,c,size=0,ele;
    cout<<"How many rows?";
    cin>>r;
    cout<<"How many columns?";
    cin>>c;

    cout<<"Enter the elements:- \n";
    int spar[r*c+1][3],k=1;
    spar[0][0]=r;
    spar[0][1]=c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) {
            cin>>ele;
            if (ele!=0) {
                spar[k][0]=i;
                spar[k][1]=j;
                spar[k][2]=ele;
                k++;size++;
            }
        }
    }
    spar[0][2]=size;
    
    cout<<"\n\n\n* * * Sparse Matrix * * *\n\n";
    for(int i=0;i<size+1;i++) {
        for(int j=0;j<3;j++) {
            cout<<"| "<<spar[i][j]<<" | \t";
        }
        cout<<endl;}

        cout<<endl;
}
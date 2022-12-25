// Write a function template for selection sort that inputs, sorts and outputs an integer array and a 
// float array.

#include <iostream>
using namespace std;

template <class T> //used template to modify this function for any data type
void selection_sort(T arr[], int n) {
    // selection sort algo given below
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(arr[i]>arr[j]) {  //we can also sort in descending order by changing the comparision operator
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
template <class T> // same as above
void display(T arr[], int n) {
    cout<<"The array elements are\n: ";
    for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
}

int main() {
    int ch, n;
    cout<<"What to sort?\n\n1. Integer\n2. Float\n\nEnter the choice: ";
    cin>>ch;
    if (ch==1) {
        cout<<"No. of elements: ";
        cin>>n;
        int arr[n];
        cout<<"Enter the elements\n: ";
        for(int &x:arr) {cin>>x;} // used for each loop to get values
        selection_sort(arr,n);
        display(arr,n);
    } else if (ch==2) {
        cout<<"No. of elements: ";
        cin>>n;
        float arr[n];
        cout<<"Enter the elements\n: ";
        for(float &x:arr) {cin>>x;}
        selection_sort(arr,n);
        display(arr,n);
    } else {
        cout<<"\n\nInvalid choice\n\n";
    }
}
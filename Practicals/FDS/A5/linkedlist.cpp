#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;
};

int main() {
    node *head, *n;
    head = new node; n = new node;

    //inserting data for head node
    cout<<"Enter the data for head: ";
    cin>>head->data;
    head->next=n;

    //inserting data for ordinary node
    cout<<"Enter the data for ordinary nodes: ";
    for(int i=0;i<4;i++) {
        cin>>n->data;
        n->next = new node;
        n=n->next;
    }


    //printing head node
    cout<<"\n\nData at head: ";
    cout<<head->data;


    //printing ordinary node
    for(int i=0;i<4;i++) {
        head=head->next;
        cout<<"\nData at ordinary node"<<i+1<<": ";
        cout<<head->data;
    }
    
}
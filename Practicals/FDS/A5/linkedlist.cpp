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
    cout<<"Enter the data for head: ";
    cin>>head->data;
    n=head->next;
    for(int i=0;i<4;i++) {
        cout<<"Enter the data for nodes: ";
        cin>>n->data;
        n=n->next;
    }
    
}
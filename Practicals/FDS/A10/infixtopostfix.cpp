#include <iostream>
using namespace std;
#define Max 50

class stack {
    int top;
    char arr[Max];
    public:
    stack() {
        top = -1;
    }
    void push(char);
    void pop();
    char Top();
    bool isempty();
    bool isfull();
};

bool stack::isempty() {
    if (top==-1) {
        return 1;
    } else {
        return 0;
    }
}

bool stack::isfull() {
    if (top==Max-1) {
        return 1;
    } else {
        return 0;
    }
}

char stack::Top() {
    if(!isempty()) {
        return arr[top];
    }
}

void stack::pop() {
    if(!isempty()) {
        top--;
    } else {
        cout<<"Stack Underflow\nCan't Pop\n";
    }
}

void stack::push(char ch) {
    if(!isfull()) {
        top++;
        arr[top] = ch;
    } else {
        cout<<"Stack Overflow\nCan't Push\n";
    }
}

int prec(char ch) {
    if (ch=='*' || ch=='/') {
        return 2;
    } else if(ch=='+' || ch=='-') {
        return 1;
    } else {
        return -1;
    }
}

string infixtopostfix(string str) {
    string res = "";
    stack st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
        {
            res+=str[i];
        } else if(str[i]=='(') {
            st.push(str[i]);
        } else if(str[i]==')') {
            while(!st.isempty() && st.Top()!='(') {
                res+=st.Top();
                st.pop();
            }
            if(!st.isempty())
                st.pop(); //to pop the opening bracket

        } else {
            while(!st.isempty() && prec(str[i]) < prec(st.Top())) {
                res+= st.Top();
                st.pop();
            }
            st.push(str[i]); //to push the current operator
        }
        
    }
    
    while(!st.isempty()) {
        res+=st.Top();
        st.pop();
    }

    return res;
}

int main()
{
    string infixeqn, postfixeqn;
    cout<<"Enter infix expression: ";
    cin>>infixeqn;
    postfixeqn = infixtopostfix(infixeqn);
    cout<<postfixeqn;
    return 0;
}
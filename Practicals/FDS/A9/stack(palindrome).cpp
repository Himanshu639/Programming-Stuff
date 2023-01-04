
/*
A palindrome is a string of character that‘s the same forward and backward. 
Typically, punctuation, capitalization, and spaces are ignored. For example, 
“Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters 
“poor danisina droop” and observing that they are the same forward and backward. 
One way to check for a palindrome is to reverse the characters in the string and then 
compare with them the original-in a palindrome, the sequence will be identical. 
Write C++ program with functions-
a)    To print original string followed by reversed string using stack
b)    To check whether given string is palindrome or not
*/
#include<iostream>
#define n 50
using namespace std;
class stack{
	char arr[n];
	int top=-1;
	public:
		void push(char ch);
		char pop();
		char Top();
		bool empty();
	    friend class palindrone;
};
void stack::push(char ch)
{
	if(top==n-1)
	{
		cout<<"stack overflow"<<endl;
		return;
	}
	top++;
	arr[top]=ch;
}
char stack::pop()
{
	char temp;
	if(top==-1)
	{
		cout<<"stack undeflow"<<endl;
	}
	else {
	temp=arr[top];
	top--;
	return temp;}
}

char stack::Top()
{
		if(top==-1)
	{
		cout<<"stack undeflow"<<endl;
	
	} else
	return arr[top];
}
bool stack::empty()
{
	if(top ==-1)
	return 1;
	else
	return 0;
}

class palindrone{
	public:
		stack st;
		stack st1;
		stack st2;
		string str;
	
	void accept()
	{
		
		cout<<"Enter your string: ";
		getline(cin,str);
		for (int i =0;i<str.length();i++)
		{
			st.push(str[i]);
			st1.push(str[i]);
		}
		
	}
	void palin() {
	    for(int i=0;i<str.length();i++) {
	        st2.push(st1.pop());
	    }
	    for(int i=0;i<str.length() && st2.top==st.top;i++) {
	        if(st.pop()!=st2.pop()) {
	             cout<<"\n\nThe string is not palindrome";
	             return;
	        }
	    }
	    cout<<"\n\nThe string is palindrome";
	}
	
	
};
int main()
{
    palindrone p;
    p.accept();
    p.palin();
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

//Reverse a stack using Recursion

void insertAtBottom(stack<int> &s, int element) {
    //base case
    if(s.empty()) {
        s.push(element);
        return ;
    }

    int num = s.top();
    s.pop();
    
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &s) {
    //base case
    if(s.empty()) {
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call
    reverseStack(s);

    insertAtBottom(s, num);
}


void printStack(stack<int> s) {
    while(!s.empty()) {
        cout<< s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    stack<int> st;

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    printStack(st);

    reverseStack(st);
    cout<<"After Reversing Stack: ";
    printStack(st);
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

//insert an element at its bottom in a given stack

void solve(stack<int> &s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x) {
    solve(myStack, x);
    return myStack;
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

    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    printStack(st);

    pushAtBottom(st, 7);
    cout<<"After Inserting x at Bottom: ";
    printStack(st);
    return 0;
}
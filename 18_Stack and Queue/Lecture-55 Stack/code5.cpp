#include <iostream>
#include <stack>
using namespace std;

//helper function to insert in sorted way
void sortedInsert(stack<int> &s, int num) {
    //base case
    if(s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return ;
    }

    int n = s.top();
    s.pop();

    //Recursive call
    sortedInsert(s, num);

    s.push(n);
}

//Que - Sort a Stack
void sortStack(stack<int> &stack) {
    //base case
    if(stack.empty()) {
        return ;
    }

    int num = stack.top();
    stack.pop();

    //Recursive call
    sortStack(stack);

    sortedInsert(stack, num);
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

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);
    printStack(st);

    sortStack(st);
    cout<<"After sorting stack: ";
    printStack(st);
    return 0;
}